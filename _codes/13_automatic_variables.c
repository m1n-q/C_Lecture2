#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
		STORAGE CLASS

		- Automatic
		- Register
		- Static with internal linkage
		- Static with external linkage
		- Static without linkage

*/

/*
		Automatic Storage Class
		- Automatic storage duration, block scope, no linkage.
		- Any variable declared in a block or function header


		- LOCAL VARIABLES
		- IN STACK !

*/

void func(int k);


int main()			// NOTE: main() is a function.
{	
	auto int a;		// keyword auto : a storage-class specifier
	a = 1024;
	printf("%d\n", a);		// what happens if uninitialized ?
	auto int b = a * 3;		// what happens if uninitialized ?


	int i = 1;
	int j = 2;

	printf("i in main %lld\n", (long long)&i);


	{
		int i = 3;		// name hiding : 더 넓은 scope에서 선언된 i 가 가려짐.	 이름만 숨겨졌지 stack에 여전히 있음!
		printf("i in block : %lld\n", (long long)&i);

		// j is visible here	:  stack에 여전히 있음!
		printf("j %d\n", j);

		int ii = 123;

	}	// stack frame



	// ii is not visible here

	printf("i in main %lld\n", (long long)&i);
	
	func(5);	// stack frame 자체가 바뀜 !! 기존 변수들 쓸 수 없음.
	

	
	
	for (int m = 1; m < 2; m++)
		printf("m %lld\n", (long long)&m);		// for, while : no block, no scope ? 예외!


	return 0;

}

void func(int k)	// stack frame
{
	int i = k * 2;
	printf("i in function : %lld\n", (long long)&i);
}	