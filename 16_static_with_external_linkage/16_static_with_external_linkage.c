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
		Static with external linkage
		- Static storage duration, file scope, external linkage
		- declaration in file scope w/o 'static' keyword
		
		
		- GLOBAL VARIABLES
		- IN DATA or BSS !
*/




//int g_int;			// 알아서 해주지만 직접 하는 것 권장
int g_int = 0;			// defining declaration
double g_arr[1000] = { 0.0, };


/*
	Initializing External Variables
	
	-cannot intialize in block scope
*/

int x = 5;					// OK w/ constant expression
int y = 1 + 2;
size_t z = sizeof(int);

//int x2 = 2 * x;			// NO, x is a variable.

void fun()
{
	printf("g_int in file   %d %p\n", g_int, &g_int);
}




void fun_sec();		// 선언만 해주면 linker가 찾아줌!

int main()
{	
	/*
		defining declaration vs referencing declaration
	*/

	//int g_int = 123;				// LOCAL : hides global g_int
	//extern int g_int;				// Optional : referencing declaration.
									// 명확한 표시 정도.


	//extern int g_int = 1024;		// cannot intialize in block scope

						

	extern double g_arr[];			// Optional, size is not necessary ( 이미 definition )

	printf("g_int in main() %d %p\n", g_int, &g_int);
	
	g_int += 1;
	fun();
	fun_sec();



	return 0;

}