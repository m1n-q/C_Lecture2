#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, prototype, file.
*/


/* file scope : 모든 함수의 밖 */
int g_i = 123;	// global variable
int g_j;		// global variable

void func1()
{
	g_i++;
}

void func2()
{
	g_i += 2;

	//local = 456;	// ERROR
}

int main()
{	
	int local = 1234;

	func1();
	func2();

	printf("%d\n", g_i);
	printf("%d\n", g_j);	// BSS segment : 0으로 초기화.
	printf("%d\n", local);	




	return 0;

}