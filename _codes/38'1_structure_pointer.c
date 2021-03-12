#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct my_data
{
	int a;
	char c;
	float arr[2];
};



int main()
{		
	struct my_data d1 = { 1234, 'A', };

	d1.arr[0] = 1.1f;
	d1.arr[1] = 2.2f;

	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
	printf("%lld %lld %lld\n", (long long)&d1.a, (long long)&d1.c, (long long)d1.arr);
	printf("%f %f\n", d1.arr[0], d1.arr[1]);
	printf("%lld %lld\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);

	printf("\n");

	
	struct my_data d2 = d1;		// d1의 member의 "값"을 copy!


	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
	printf("%f %f\n", d2.arr[0], d2.arr[1]);		
	printf("%lld %lld\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);

	printf("\n");


	/*
		일렬로 나열된 구조체 메모리.
		a -> a
		c -> c
		arr[0] -> arr[0]  
		arr[1] -> arr[1]

		일렬 그대로, 메모리에 저장된 값들을 복사...
		(그러면, 배열 원소를 복사.. )
		arr 이라는 배열명이 pointing하는 주소값을 넘겨준게 아님ㅎㅎ 
	*/
	return 0;

}