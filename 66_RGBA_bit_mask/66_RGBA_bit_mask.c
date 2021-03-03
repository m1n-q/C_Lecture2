#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define BYTE_MASK 0xff

int main()
{	
	unsigned int rgba_color = 0x66CDAAFF;
		// 4 bytes, medium aqua marine (102, 205, 170, 255)

	unsigned char red, green, blue, alpha;
	
	
	// Use right shift (>>) operator
	alpha	= 0;
	blue	= 0;
	green	= 0;
	red		= 0;

	
	alpha |= rgba_color;
	blue  |= rgba_color >> 2;
	green |= rgba_color >> 4;
	red	  |= rgba_color >> 6;



	printf("(R, G, B, A) = (%hhu, %hhu, %hhu, %hhu)\n",
		red, green, blue, alpha);
	return 0;

}