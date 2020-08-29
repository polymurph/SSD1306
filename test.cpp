#include <iostream>


// for i2c functionality

#include <linux/i2c-dev.h>
#include <sys/ioctl.h>


#include <i2c/smbus.h>


using namespace std;


enum{
	I2C_ADDR_SSD1306 = 0x3C
};


int main(void)
{
	cout << "SSD1306 test" << endl;	


	

	return 0;
}
