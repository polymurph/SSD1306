#ifndef _SSD1306_H_
#define _SSD1306_H_

#include <stdint.h>

class SSD1306
{
	public:
	typedef void (*i2c_write_reg8_t)(uint8_t, uint8_t);	
	SSD1306(i2c_write_reg8_t i2c_write_reg8);

	void turn_ON();
	void turn_OFF();

	private:

	i2c_write_reg8_t i2c_w_reg8;
};

#endif //_SSD1306_H_
