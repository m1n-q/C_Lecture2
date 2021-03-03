#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()
{	
	/*
		Union
		- Store different data types in the same memory space
		- Structure vs Union
	*/


	union my_union
	{
		int		i;
		double	d;
		char	c;

		// 세 인식자가 한 메모리 공유! (같은 메모리 공간 사용)
		// 가장 큰 자료형의 크기
	};

	union my_union uni;

	printf("%zd\n", sizeof(union my_union));
	printf("%lld\n", (long long)&uni);
	printf("%lld %lld %lld\n",
		(long long)&uni.i, (long long)&uni.d, (long long)&uni.c);

	union my_union save[10];

	printf("%zd\n", sizeof(save));



	/*
		Union of different types
	*/


	union my_union uni1;

	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// 0xCCCCCC41 = -858993599
		
	
	uni1.i = 0;
	uni1.c = 'A';
	printf("%c %x %d\n", uni1.c, (int)uni1.c, uni1.i);
	// 0x00000041 = 65

	uni1.d = 1.2;
	printf("%d %f %d %c\n", uni1.i, uni1.d, (int)uni1.c, uni1.c);
	// 33 33 33 33 33 33 f3 3f
	// double (8bytes): 0x3ff3333333333333 = 1.199999999999999999,,,,,
	// int	  (4bytes): 0x33333333 = 858993459 
	// char	  (1bytes): 0x33 = 51 = '3'

	/*
		Initializing unions
	*/

	union my_union uni2 = uni1;			// copy
	union my_union uni3 = { 10 };		// First member only
	union my_union uni4 = { .c = 'A' };	// Designated initializer
	union my_union uni5 = { .d = 1.23, .i = 100 };	// NOT recommended

	printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);

	uni5.i = 123;
	uni5.d = 1.2;
	uni5.c = 'k';		// 맨 앞칸 1칸만 k 가 된겨

	printf("%d %f %c\n", uni5.i, uni5.d, uni5.c);

	union my_union* pu = &uni;	
	int x = pu->i;	// uni.i


	uni.c = 'A';
	double real = 3.14 * uni.d;		// do NOT recommend (의도 파악 어려움)

	return 0;
}