#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
/*
	Signed Integers

	- Sign-magnitude representation
	00000001 == 1, 10000001 == -1
	00000001 == 0, 10000000 == -0
	Two zeros +0 -0, from -127 to +127


	- One's complement mthod
	To reverse the sign. invert each bit.
	00000001 == 1, 11111110 == -1
	11111111 == -0
	Two zeros +0 -0, from -127 to +127

	- Two's complement mthod ( commonly used in most systems )
	To reverse the sign. invert each bit and add 1.
	One zero, from -128 to +127
*/

void print_binary(const char num);

int main()
{	

	print_binary(127);
	print_binary(-127);
	print_binary(~127+1);
	printf("\n");

	print_binary(12);
	print_binary(-12);
	print_binary(~12 + 1);
	printf("\n");

	print_binary(7);
	print_binary(-7);
	print_binary(~-7 + 1);

	print_binary(-14);
	return 0;

}
void print_binary(const char num)
{
	char bi[9];

	const size_t bits = sizeof(num) * 8;



	//for (size_t i = bits - 1; i >= 0; i--);	// ERROR
	for (size_t i = 0; i < bits; i++)
	{

		//const unsigned char mask = pow(2, i) 
		//if( (num & mask) == mask)
		if ((num & ((int)pow(2, i))) == (int)pow(2, i))
			bi[8 - i - 1] = '1';

		else
			bi[8 - i - 1] = '0';
	}

	bi[bits] = '\0';





	printf("Decimal %5d\t== Binary %s\n", num, bi);
}