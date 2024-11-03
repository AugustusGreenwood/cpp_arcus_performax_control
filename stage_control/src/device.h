#ifndef DEVICE_H
#define DEVICE_H

#include "transferqueue.h"
#include <functional>
#include <libusb-1.0/libusb.h>
#include <thread>

struct Transfer {
	~Transfer() { delete[] response; }
	const char command[64];
	char *response = new char[64];
	int result = -1;
	bool completed = false;
};

class Device {
  public:
	Device(int prod_id, int vend_id, int timeout = 3000);
	~Device();

	int getPulsePosition();
	int getHighSpeed();
	int getEncoderPosition();
	int getMotorStatus();
	int getCurrentPulseSpeed();
	int getAccelerationTime();
	int getDecelerationTime();
	int getIdleCurrent();
	int getIdleTime();
	int getMicrosteps();
	int getRunCurrent();
	int getLowSpeed();

	void setEncoderPosition(int pos);
	void setIncrementalMovement();
	void setAbsoluteMovement();
	void setPulsePosition(int pos);
	void setAccelerationTime(int time);
	void setDecelerationTime(int time);
	void setIdleCurrent(int current);
	void setIdleTime(int time);
	void setMicrosteps(int steps);
	void setRunCurrent(int current);
	void setLowSpeed(int speed);
	void setHighSpeed(int speed);
	void turnMotorOn();
	void turnMotorOff();

	void stop();
	void abort();
	void moveTo(int pos);
	void moveUp();
	void moveDown();
	bool checkDriverRead();
	bool checkDriverWrite();
	void writeDriverParameters();
	void readDriverParameters();
	void waitForMotorIdle();
	void waitForMotorIdle(std::function<void(void)> func);

	int sendCommandGetResponse(const char command[64], char response[64]);
	void addTransfer(Transfer *transfer);
	void addTransfers(std::vector<Transfer *> transfers_);

	int product_id;
	int vendor_id;
	int timeout;

	char *pulse_position = new char[64];
	char *encoder_position = new char[64];
	char *motor_status = new char[64];

  private:
	int open();
	int close();
	int controlWrite(const int value);
	int clearReadBuffer();
	int flush();
	int bulkWrite(const unsigned char command[64]);
	int bulkRead(unsigned char output[64]);

	void processTransfers(std::stop_token stoken);
	void monitor(std::stop_token stoken);

	TransferQueue<Transfer *> transfers;
	std::jthread process_transfers_thread;
	std::jthread monitor_thread;

	libusb_context *context = nullptr;
	libusb_device_handle *handle = nullptr;
	int interface_number = 0;

	unsigned char read_endpoint = 0x82;
	unsigned char write_endpoint = 0x02;
};

#endif
