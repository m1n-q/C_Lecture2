#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);


int main()
{
	

	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");


	
	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);

	return 0;

}

unsigned char to_decimal(const char bi[])
{
	size_t n = strlen(bi);
	unsigned char ret = 0;
	for (size_t i = 0; i < n; i++)
	{
		//ret += pow(2, atoi(bi[i]));
		if (bi[i] == '0')
			;
		else if (bi[i] == '1')
			ret += (int)pow(2, n - 1 - i);

		/*if (bi[i] == '1')
			ret += (int)pow(2, n - 1 - i);
		else if (bi[i] != '0') {
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}*/

	}
	return ret;
}

void print_binary(const unsigned char num)
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

	

	
	
	printf("Decimal %2d\t== Binary %s\n", num, bi);
}