#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>			// <> : compiler가 directory를 이미 아는 경우. 주로 표준 라이브러리

#include "my_functions.h"	// 같은 dir
#include "my_structures.h"

/* path */
#include "my_headers/my_macros.h"		
//#include "C:\Users\Administrator\Desktop\VS\Lecture2\75_include_header\my_headers\my_macros.h"
// properties -> additional include directory


extern int status;

int main()
{	

#include "hello_world.h"	
//printf("Hello, World from a header file\n");	// include는 단순 복붙임!


	printf("PI = %f\n", PI);


	
	printf("In main\nAddress = %p, Value = %d\n", &status, status);
	
	printf("\n");
	print_status();
	

	printf("\n-----------------------------\n");
	printf("%d\n", multiply(51, 2));


	printf("\n");
	printf("main()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);			// include : 복붙, 이 file scope!

	printf("\n");
	print_address();			// my_function.h를 include한 my_function.c의 scope

	printf("\n");
	printheader();
	return 0;

}