#include "gfx.h"

static const GFX::kernel_t kernel[5] = {
		{3,static_cast<uint8_t*>({0x02,0x07,0x02})},
		{3,static_cast<uint8_t*>({0x07,0x07,0x07})},
		{5,static_cast<uint8_t*>({0x04,0x0E,0x1F,0x0E,0x04})},
		{5,static_cast<uint8_t*>({0x0E,0x1F,0x1F,0x1F,0x0E})},
		{7,static_cast<uint8_t*>({0x18,0x3C,0x7E,0x7F,0x7E,0x3C,0x18})}


GFX::GFX(uint8_t n_pixle_row,
		 uint8_t n_pixle_col,
		 set_binary_pixle_t set_b_pix) :
	n_pixle_row(n_pixle_row),
	n_pixle_col(n_pixle_col),
	set_bin_pixle(set_b_pix)
{
	
}

void GFX::clear_display(bool foreground)
{
	uint8_t i;
	uint8_t j;
	
	for(i = 0; i < n_pixle_row; i++) {
		for(j = 0; j < n_pixle_col; j++) {
			set_bin_pixle(i, j, foreground);
		}
	}
}

void GFX::draw_line(uint8_t x0,
				    uint8_t y0,
					uint8_t x1,
					uint8_t y1,
					uint8_t width,
					bool foreground)
{
	uint8_t x;
	uint8_t y;
	uint8_t x_start;
	uint8_t x_end;
	
	// y = m * x + b
	
	// calculate slope m
	float m = (y1 - y0) / (x1 - x0);
	// calculate offset b
	float b = (y0 > y1) ? y1 : y0;
	
	for(x = (x0 > x1) ? x1 : x0;
	    x < (x0 > x1) ? x0 : x1;
		x++) {
		draw_kernel(x,
					static_cast<uint8_t>(m * x + b),
					width,
					foreground);
	}
}

void GFX::draw_kernel(uint8_t x,
					  uint8_t y,
					  uint8_t size,
					  bool foreground)
{
	if(size = 0) return;
	if(size = 1) {
		set_bin_pixle(x,y,foreground);
		return;
	}
	
	size -= 2;
	
	uint8_t k_size = kernel[size].size;
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t offset = (k_size - 1) / 2; 
	uint8_t x_start = x - offset;
	uint8_t y_start = y - offset;
	bool set = false;
	
	// drawing kernel centered on (x, y)
	for(i = 0; i < k_size; i++) {
		for(j = 0; j < k_size; j++) {
			set = static_cast<bool>(kernel[size].pattern[i] >> j) ^ !foreground;
			set_bin_pixle(x_start + i, y_start + j, set);
		}
	}
}
		

