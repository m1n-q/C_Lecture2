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
		int i = 3;		// name hiding : �� ���� scope���� ����� i �� ������.	 �̸��� �������� stack�� ������ ����!
		printf("i in block : %lld\n", (long long)&i);

		// j is visible here	:  stack�� ������ ����!
		printf("j %d\n", j);

		int ii = 123;

	}	// stack frame



	// ii is not visible here

	printf("i in main %lld\n", (long long)&i);
	
	func(5);	// stack frame ��ü�� �ٲ� !! ���� ������ �� �� ����.
	

	
	
	for (int m = 1; m < 2; m++)
		printf("m %lld\n", (long long)&m);		// for, while : no block, no scope ? ����!


	return 0;

}

void func(int k)	// stack frame
{
	int i = k * 2;
	printf("i in function : %lld\n", (long long)&i);
}	