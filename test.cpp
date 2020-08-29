#include <iostream>
#include <stdint.h>

// for i2c functionality

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>


#include <i2c/smbus.h>

#include <wiringPiI2C.h>

#include "cpp_src/ssd1306.h"


using namespace std;


enum{
	I2C_ADDR_SSD1306 = 0x3C
};

static int i2c_handle = 0;


void i2c_write_reg8(uint8_t reg, uint8_t data);

int main(void)
{
	int i = 0;

	cout << "SSD1306 test" << endl;	
	cout << "using device address: 0x" << hex << I2C_ADDR_SSD1306 << dec << endl;

	i2c_handle = wiringPiI2CSetup(I2C_ADDR_SSD1306);
	// turns off Display	
	wiringPiI2CWriteReg8(i2c_handle, 0x00, 0xAE);
	

	static SSD1306 display(SSD1306::SIZE_128x64, i2c_write_reg8);

	cout << "turned on display" << endl;
	display.turn_ON();
	

	for(i = 0; i < 100000000; i++);

	cout << "turned off display" << endl;
	
	display.turn_OFF();
	return 0;
}


void i2c_write_reg8(uint8_t reg, uint8_t data)
{
	wiringPiI2CWriteReg8(i2c_handle, reg, data);	
}
