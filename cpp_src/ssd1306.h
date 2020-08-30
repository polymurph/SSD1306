#ifndef _SSD1306_H_
#define _SSD1306_H_

#include <stdint.h>

class SSD1306
{
	public:
		
		typedef enum{
			I2C_ADDRESS_0x3C = 0x3C
		}address_t;

		typedef enum{
			SIZE_128x32,
			SIZE_128x64
		}disp_size_t;
		
		typedef void (*i2c_write_reg8_t)(uint8_t, uint8_t, uint8_t);	

		SSD1306(address_t address,
				disp_size_t size,
				i2c_write_reg8_t i2c_write_reg8);

		void turn_ON();
		void turn_OFF();
		void delete_display();

	private:

		// fundamental commands
		enum{
			SET_CONTRAST_CONTROL_V = 0x81,
			ENTIRE_DISPLAY_RESET = 0xA4,
			ENTIRE_DISPLAY_ON = 0xA5,
			SET_NORMAL_DISPLAY = 0xA6,
			SET_INVERSE_DISPLAY = 0xA7,
			SET_DISPLAY_OFF = 0xAE,
			SET_DISPLAY_ON = 0xAF
		};

		// scrolling commands
		//
		enum{
			RIGHT_HORIZONTAL_SCROLL = 0x26,
			LEFT_HORIZONTAL_SCROLL = 0x27,
			VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL = 0x29,
			VERTICAL_AND_LEFT_HORIZONTAL_SCROLL = 0x2A,
		};

		address_t address;
		disp_size_t size;
		i2c_write_reg8_t i2c_w_reg8;
};

#endif //_SSD1306_H_
