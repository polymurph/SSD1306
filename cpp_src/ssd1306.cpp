#include "ssd1306.h"

SSD1306::SSD1306(address_t address,
				 disp_size_t size,
				 i2c_write_reg8_t i2c_write_reg8):
	address(address),
	size(size),
	i2c_w_reg8(i2c_write_reg8)
{

}

void SSD1306::turn_ON()
{
	i2c_w_reg8(address, 0x00, 0xAF);
}

void SSD1306::turn_OFF()
{
	i2c_w_reg8(address, 0x00, 0xAE);
}

void SSD1306::delete_display()
{

}

