#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	#define, #undef, #if, #ifdef, #ifndef, #else, #elif, #endif
*/

/*
	#undef
*/

#define LIMIT 400
//#undef LIMIT	

#undef NON_DEFINED // It's OK to undefine previously NOT defined macro.

/*
	#ifndef, #endif 
	- header guard
*/

#include "Header_B.h"
#include "Header_A.h"		// 중복 include : #ifndef header guard


/*
	Conditional Compilation, #if
*/
#define TYPE 1

#if TYPE == 1
#include "my_function_1.h"
#elif TYPE == 2
#include "my_function_2.h"
#else
static void mu_function()
{
	printf("Wrong compile option!");
}
#endif


/*
	Empty Macro, #ifdef
*/


//#define REPORT			// define 되어있다. flag 느낌?

int sum(int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; ++k)
	{
		s += k;

//#ifdef _DEBUG
//#ifdef _NDEBUG
#ifdef REPORT		// project properties - preprocessor definitions
		printf("%d %d\n", s, k);
#endif
	}

	return s;
}

/*
	#ifdef, #elif
*/

void say_hello()
{
#ifdef _WIN64
	printf("Hello, WIN64");
#elif _WIN32
	printf("Hello, WIN32");
#elif __linux__
	printf("Hello, linux");
#endif
}


int main()
{	

	/*
		#undef
	*/

	printf("%d\n", LIMIT);


	/*
		#ifndef, #endif
		- header guard
	*/
	test_function_A();
	test_function_B();


	/*
		Conditional Compilation, #if
	*/
	my_function();


	/*
		Empty Macro, #ifdef
	*/	

	printf("\n");
	printf("\n%d \n", sum(1, 10));
	
	/*
		#ifdef, #elif
	*/

	say_hello();
	return 0;

}