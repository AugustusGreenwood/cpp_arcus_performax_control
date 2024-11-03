#include "device.h"
#include <format>
#include <iostream>

Device::Device(int prod_id, int vend_id, int timeout)
	: product_id(prod_id), vendor_id(vend_id), timeout(timeout),
	  process_transfers_thread(&Device::processTransfers, this),
	  monitor_thread(&Device::monitor, this) {
	int result = open();
	if (result != LIBUSB_SUCCESS) {
		throw(std::runtime_error(
			std::format("Failed to open device, exiting now. Error was: \'{}\'",
						libusb_error_name(result))));
	}

	flush();
}

Device::~Device() {
	monitor_thread.request_stop();
	monitor_thread.join();
	process_transfers_thread.request_stop();
	process_transfers_thread.join();
	close();

	delete[] pulse_position;
	delete[] encoder_position;
	delete[] motor_status;
}

int Device::open() {
	int result = libusb_init(&context);
	if (result != LIBUSB_SUCCESS) {
		return result;
	}

	libusb_device **list;
	int num_devices = libusb_get_device_list(context, &list);

	struct libusb_device_descriptor descriptor;
	for (int i = 0; i < num_devices; i++) {
		result = libusb_get_device_descriptor(list[i], &descriptor);
		if (result != LIBUSB_SUCCESS) {
			std::cerr << "Failed to get descriptor for some connected device. "
						 "Continuing...\n";
		}

		if ((descriptor.idProduct == product_id) &&
			(descriptor.idVendor == vendor_id)) {
			result = libusb_open(list[i], &handle);
			if (result != LIBUSB_SUCCESS) {
				return result;
			}

			result = libusb_claim_interface(handle, interface_number);
			if (result != LIBUSB_SUCCESS) {
				return result;
			}

			result = controlWrite(0x02);
			if (result != LIBUSB_SUCCESS) {
				return result;
			}

			result = clearReadBuffer();
			if (result != LIBUSB_SUCCESS) {
				return result;
			}

			return LIBUSB_SUCCESS;
		}
	}

	libusb_free_device_list(list, 1);

	return LIBUSB_ERROR_NOT_FOUND;
}

int Device::close() {
	int result = controlWrite(0x04);
	if (result != LIBUSB_SUCCESS) {
		return result;
	}

	result = libusb_release_interface(handle, interface_number);
	if (result != LIBUSB_SUCCESS) {
		return result;
	}

	libusb_close(handle);
	libusb_exit(context);
	return result;
}

int Device::sendCommandGetResponse(const char command[64], char response[64]) {
	int result = clearReadBuffer();
	if (result != LIBUSB_SUCCESS) {
		return result;
	}
	result = bulkWrite(reinterpret_cast<const unsigned char *>(command));
	if (result != LIBUSB_SUCCESS) {
		return result;
	}
	result = bulkRead(reinterpret_cast<unsigned char *>(response));
	if (result != LIBUSB_SUCCESS) {
		return result;
	}
	return LIBUSB_SUCCESS;
}
int Device::controlWrite(const int value) {
	return libusb_control_transfer(handle, 0x40, 0x02, value, 0x00, NULL, 0,
								   timeout);
}
int Device::clearReadBuffer() {
	unsigned char buffer[4096];
	int transferred;
	// This is going to timeout no matter what, so I make the timeout smaller to
	// reduce waiting for nothing
	int result = libusb_bulk_transfer(handle, read_endpoint, buffer,
									  sizeof(buffer), &transferred, 1);

	if (result == LIBUSB_ERROR_TIMEOUT) {
		result = LIBUSB_SUCCESS;
	}

	return result;
}

int Device::flush() { return controlWrite(0x01); }

int Device::bulkWrite(const unsigned char command[64]) {
	int amt_written, result;
	result = libusb_bulk_transfer(handle, write_endpoint,
								  const_cast<unsigned char *>(command), 64,
								  &amt_written, timeout);

	if (amt_written != 64) {
		return LIBUSB_ERROR_IO;
	}

	return result;
}

int Device::bulkRead(unsigned char output[64]) {
	int amt_read, result;
	result = libusb_bulk_transfer(handle, read_endpoint, output, 64, &amt_read,
								  timeout);

	if (amt_read != 64) {
		return LIBUSB_ERROR_IO;
	}

	return result;
}

void Device::addTransfer(Transfer *transfer) { transfers.push(transfer); }
void Device::addTransfers(std::vector<Transfer *> transfers_) {
	for (Transfer *t : transfers_) {
		transfers.push(t);
	}
}

void Device::processTransfers(std::stop_token stoken) {
	Transfer *transfer;
	while (!stoken.stop_requested()) {
		if (handle == nullptr) {
			continue;
		}

		if (transfers.empty() == false) {
			transfer = transfers.pop();
			transfer->result =
				sendCommandGetResponse(transfer->command, transfer->response);
			transfer->completed = true;
		}
	}
}
void Device::monitor(std::stop_token stoken) {
	std::vector<Transfer *> transfers_ = {
		new Transfer{"PX\0", pulse_position},
		new Transfer{"EX\0", encoder_position},
		new Transfer{"MST\0", motor_status}};
	while (!stoken.stop_requested()) {
		addTransfers(transfers_);
		while (transfers_[2]->completed == false) {
			std::this_thread::yield();
		}

		transfers_[2]->completed = false;
	}
}

// Getters and setters
int Device::getPulsePosition() {
	Transfer transfer = {"PX\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}

int Device::getHighSpeed() {
	Transfer transfer = {"HSPD\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}

int Device::getEncoderPosition() {
	Transfer transfer = {"EX\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}

int Device::getMotorStatus() {
	Transfer transfer = {"MST\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}

int Device::getCurrentPulseSpeed() {
	Transfer transfer = {"PS\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}

int Device::getAccelerationTime() {
	Transfer transfer = {"ACC\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}
int Device::getDecelerationTime() {
	Transfer transfer = {"DEC\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}
int Device::getIdleCurrent() {
	Transfer transfer = {"DRVIC\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}
int Device::getIdleTime() {
	Transfer transfer = {"DRVIT\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}
int Device::getMicrosteps() {
	Transfer transfer = {"DRVMS\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}
int Device::getRunCurrent() {
	Transfer transfer = {"DRVRC\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}
int Device::getLowSpeed() {
	Transfer transfer = {"LSPD\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	return std::atoi(transfer.response);
}

void Device::setEncoderPosition(int pos) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "EX=%i", pos);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setIncrementalMovement() {
	Transfer transfer = {"INC\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setAbsoluteMovement() {
	Transfer transfer = {"ABS\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setPulsePosition(int pos) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "PX=%i", pos);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setAccelerationTime(int time) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "ACC=%i", time);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setDecelerationTime(int time) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "DEC=%i", time);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setIdleCurrent(int current) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "DRVIC=%i",
				  current);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setIdleTime(int time) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "DRVIT=%i", time);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setMicrosteps(int steps) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "DRVMS=%i", steps);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setRunCurrent(int current) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "DRVRC=%i",
				  current);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setLowSpeed(int speed) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "LSPD=%i", speed);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::setHighSpeed(int speed) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "HSPD=%i", speed);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::turnMotorOn() {
	Transfer transfer = {"EO=1\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::turnMotorOff() {
	Transfer transfer = {"EO=0\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::stop() {
	Transfer transfer = {"STOP\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::abort() {
	Transfer transfer = {"ABORT\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::moveTo(int pos) {
	Transfer transfer = {""};
	std::snprintf(const_cast<char *>(transfer.command), 64, "X%i", pos);
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::moveUp() {
	Transfer transfer = {"J+\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
void Device::moveDown() {
	Transfer transfer = {"J-\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}
bool Device::checkDriverRead() {
	Transfer transfer = {"R2\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	if (std::atoi(transfer.response) == 1) {
		return true;
	} else {
		return false;
	}
}

bool Device::checkDriverWrite() {
	Transfer transfer = {"R4\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}

	if (std::atoi(transfer.response) == 1) {
		return true;
	} else {
		return false;
	}
}

void Device::readDriverParameters() {
	Transfer transfer = {"RR\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}

void Device::writeDriverParameters() {
	Transfer transfer = {"RW\0"};
	addTransfer(&transfer);
	while (transfer.completed == false) {
		std::this_thread::yield();
	}
}

void Device::waitForMotorIdle() {
	do { } while (getMotorStatus() != 0); }

void Device::waitForMotorIdle(std::function<void(void)> func) {
	do {
		func();
	} while (getMotorStatus() != 0);
}
