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

// TODO: Do some inheritance. I think breaking this into a base class USB device
// and then building the specifics on top would be great
class Device {
  public:
	Device(int prod_id, int vend_id, int timeout = 3000);
	~Device();

	// Important that all these get* and set* are blocking
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

	// WHen interactive with the gui, these offer a way to consistently get the
	// state of the machine. These are updated in the "monitor" function and
	// thread. I don't usually need them as integers so I leave them as chars:
	char *pulse_position = new char[64];
	char *encoder_position = new char[64];
	char *motor_status = new char[64];

  private:
	// My thinking is many of these private functions could be given to a base
	// class and then inhereted
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

	// Having these hard-coded is probably bad practice, but it works well
	unsigned char read_endpoint = 0x82;
	unsigned char write_endpoint = 0x02;
};

#endif
