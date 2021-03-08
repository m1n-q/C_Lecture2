#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Regular Logical Operators 
	- && (and)
	- || (or)
	- !	 (not)

	Bitwise Logical Operators
	- &	(and)
	- | (or)
	- ~ (not)
	- ^ (xor)
	
*/

int main()
{	/* 8 bytes (56bits) */
	unsigned char has_sword = 1;		// 7 bits ³¶ºñ..
	unsigned char has_shield = 0;
	unsigned char has_potion = 0;
	unsigned char has_shoes = 1;
	unsigned char has_gun = 0;
	unsigned char has_pet = 1;
	unsigned char has_guntlet = 0;
	unsigned char has_arrow = 0;		// 7 * 8 = 56 bits ³¶ºñ



	/* 1 bytes (8bits) */
	unsigned char items = 148;	// Binary 10010100


	/* 
		Bitwise AND & 
		- 1 & 1 = 1
		- 1 & 0 = 0
		- 0 & 1 = 0
		- 0 & 0 = 0
	*/

	unsigned char a = 6;		// 2^2 + 2^1  = 00000110
	unsigned char b = 5;		// 2^2 + 2^0  = 00000101
	
	printf("%hhu", a & b);		//			  = 00000100
	
	
	/*
		Bitwise OR |
		- 1 | 1 = 1
		- 1 | 0 = 1
		- 0 | 1 = 1
		- 0 | 0 = 0
	*/
	
	unsigned char a = 6;		// 2^2 + 2^1  = 00000110
	unsigned char b = 5;		// 2^2 + 2^0  = 00000101

	printf("%hhu", a | b);		//  		  = 00000111



	/*
		Bitwise XOR ^
		- 1 ^ 1 = 0
		- 1 ^ 0 = 1
		- 0 ^ 1 = 1
		- 0 ^ 0 = 0
	*/

	unsigned char a = 6;		// 2^2 + 2^1  = 00000110
	unsigned char b = 5;		// 2^2 + 2^0  = 00000101

	printf("%hhu", a ^ b);		//  		  = 00000011



	/*
		Bitwise NOT ~
		- ~ 1 = 0
		- ~ 0 = 1
	
	*/

	unsigned char a = 6;		// 2^2 + 2^1  = 00000110
	
	printf("%hhu", ~a);			//  		  = 11111001

	return 0;

}