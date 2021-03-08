#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{	
	unsigned int rgba_color = 0x66CDAAFF;
		// 4 bytes, medium aqua marine (102, 205, 170, 255)

	unsigned char red, green, blue, alpha;
		// 1 byte
	
	// Use right shift (>>) operator
	alpha   = 0;
	blue	= 0;
	green	= 0;
	red		= 0;

	alpha |= rgba_color;
	blue  |= (rgba_color >> 8);		// char = 1byte = 8bits
	green |= (rgba_color >> 16);
	red	  |= (rgba_color >> 24);

	//alpha = rgba_color & BYTE_MASK;
	//blue  = (rgba_color >> 8 & BYTE_MASK);
	//green = (rgba_color >> 16 & BYTE_MASK);
	//red	= (rgba_color >> 24 & BYTE_MASK);



	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha);

	printf("%d", 0 | 0);
	return 0;

}