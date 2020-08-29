#include <iostream>


// for i2c functionality

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>


#include <i2c/smbus.h>

#include <wiringPiI2C.h>

using namespace std;


enum{
	I2C_ADDR_SSD1306 = 0x3C
};


int main(void)
{
	int i2c_handle = 0;
	cout << "SSD1306 test" << endl;	
	cout << "using device address: 0x" << hex << I2C_ADDR_SSD1306 << dec << endl;

	i2c_handle = wiringPiI2CSetup(I2C_ADDR_SSD1306);
	// turns off Display	
	wiringPiI2CWriteReg8(i2c_handle, 0x00, 0xAE);
	
	

	return 0;
}
