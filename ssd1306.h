#ifndef _SSD1306_H_
#define _SSD1306_H_

#include <stdint.h>
// TODO: implement variants for 6800/8080-parallel inteface and 3/4-wire serial interface (p.15)


class SSD1306
{
    public:
    
    typedef enum{
        i2c_address_0 = 0b01111000,
        i2c_address_1 = 0b01111010 
    } i2c_address_t;

    turn_on();
    turn_off();
    set_contrast(uint8_t constrast);
    invert_on();
    invert_off();

    private:

    typedef enum{
        scrolling_cmd_RIGHT_HORIZONTAL_SCROLL = 0x26,
        scrolling_cmd_LEFT_HORIZONTAL_SCROLL = 0x27,
        scrolling_cmd_PAGE_0 = 0x00,
        scrolling_cmd_PAGE_1 = 0x01,
        scrolling_cmd_PAGE_2 = 0x02,
        scrolling_cmd_PAGE_3 = 0x03,
        scrolling_cmd_PAGE_4 = 0x04,
        scrolling_cmd_PAGE_5 = 0x05,
        scrolling_cmd_PAGE_6 = 0x06,
        scrolling_cmd_PAGE_7 = 0x07,
        scrolling_cmd_FRAMES_5 = 0x00,
        scrolling_cmd_FRAMES_64 = 0x01,
        scrolling_cmd_FRAMES_128 = 0x02,
        scrolling_cmd_FRAMES_256 = 0x03,
        scrolling_cmd_FRAMES_3 = 0x04,
        scrolling_cmd_FRAMES_4 = 0x05,
        scrolling_cmd_FRAMES_25 = 0x06,
        scrolling_cmd_FRAMES_2 = 0x07,
        scrolling_cmd_   
    }scrolling_cmd_t;

    i2c_address_t address;
    uint8_t contrast;

};

#ednif // _SSD1306_H_