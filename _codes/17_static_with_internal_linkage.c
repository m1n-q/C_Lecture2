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
		Static with internal linkage
		- Static storage duration, file scope, internal linkage
		- declaration in file scope with 'static' keyword


		
		- IN DATA or BSS !
		- DATA segement : 초기 값 지정시!
		- BSS segment   : 미지정시 BSS에서 일괄적으로 0으로 초기화

*/


static int g_int = 123;	// defining declaration

void fun();
void fun_second();
void fun_third();


int main()
{	

	fun();
	fun_second();
	fun_third();



	return 0;

}

void fun()
{
	
	g_int += 1;
	printf("g_int in fun()  : %d %p\n", g_int, &g_int);
}