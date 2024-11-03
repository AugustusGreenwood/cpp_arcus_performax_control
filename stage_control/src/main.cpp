#include "device.h"
#include <iostream>

const int VENDOR_ID = 0x1589;
const int PRODUCT_ID = 0xa101;

using namespace std;

int main() {
	Device device(PRODUCT_ID, VENDOR_ID, 3000);

	device.setPulsePosition(999);
	int pos = device.getPulsePosition();
	std::cout << pos << std::endl;

	return 0;
}
