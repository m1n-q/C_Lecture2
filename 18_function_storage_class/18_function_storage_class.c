#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Storage class of Function
	- external (by default)
	- static

	-> in TEXT segment ( PROGRAM CODE where string is located )


	- Function declaration is assumed to be "extern"

*/


int g_int = 123;
/*extern*/ void fun();
/*extern*/ void fun_second();

int main()
{	

	fun();
	fun_second();
	return 0;

}

void fun() 
{
	g_int += 1;
	printf("g_int in fun() : %d %p\n", g_int, &g_int);
}
