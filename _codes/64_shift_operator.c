#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
/*
	Bitwise shift operators

	- Left shift
	number << n : multiply number by 2^n

	- Right shift
	number >> n : divide number by 2^n	(for non-negative numbers)

	** NOT always **
	* - ������� �ʴ� number�� ��츸.
	
*/

void int_binary(const int num);
int main()
{	
	// 8bit integer cases
	//								   76543210		   76543210		  76543210
	printf("%hhd\n", 1 << 3);		// 00000001 ->	00000001???	 ->	  00001000
	printf("%hhd\n", 8 >> 1);		// 00001000 ->	   ?00001000 ->	  00000100

	// signed 						   76543210		   76543210		  76543210
	printf("%hhd\n", -119 >> 3);	// 10001001 ->	   ???10001001 -> 11110001
	printf("%hhd\n", -119 / 8);
	// unsigned						   76543210		   76543210		  76543210
	printf("%hhu\n",  137 >> 3);	// 10001001 ->	   ???10001001 -> 00010001
	printf("%hhu\n",  137 / 8);


	//								   76543210		   76543210		  76543210
	printf("%hhd\n", -119 << 4);	// 10001001 -> 10001001???? ->	  10010000	( -112)
	printf("%hhu\n",  137 << 3);	// 10001001 -> 10001001???? ->	  10010000  (  144)
	
	
	//NOTE : the signed result is machine dependent

	int a = 1;
	a <<= 3;
	a >>= 2;

	printf("\nUnsigned int %u\n", 0xffffffff);
	printf("Signed int %d\n\n", 0xffffffff);
	int_binary(0xffffffff);

	printf("Right shift by 3\n");
	int_binary((signed)	 0xffffffff >> 3);
	int_binary((unsigned)0xffffffff >> 3);

	
	printf("\nUnsigned int %u\n", 0x00ffffff);
	printf("Signed int %d\n\n", 0x00ffffff);
	int_binary(0x00ffffff);
	
	printf("Right shift by 3\n");
	int_binary((signed)	 0x00ffffff >> 3);
	int_binary((unsigned)0x00ffffff >> 3);


	return 0;


}
void int_binary(const int num)
{
	printf("Decimal %12d == Binary ", num);

	const size_t bits = sizeof(num) * CHAR_BIT;

	for (size_t i = 0; i < bits; ++i)
	{
		const int mask = 1 << (bits - 1 - i);

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);

	}
	printf("\n");
}