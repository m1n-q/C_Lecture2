#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>			// <> : compiler�� directory�� �̹� �ƴ� ���. �ַ� ǥ�� ���̺귯��

#include "my_functions.h"	// ���� dir
#include "my_structures.h"

/* path */
#include "my_headers/my_macros.h"		
//#include "C:\Users\Administrator\Desktop\VS\Lecture2\75_include_header\my_headers\my_macros.h"
// properties -> additional include directory


extern int status;

int main()
{	

#include "hello_world.h"	
//printf("Hello, World from a header file\n");	// include�� �ܼ� ������!


	printf("PI = %f\n", PI);


	
	printf("In main\nAddress = %p, Value = %d\n", &status, status);
	
	printf("\n");
	print_status();
	

	printf("\n-----------------------------\n");
	printf("%d\n", multiply(51, 2));


	printf("\n");
	printf("main()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);			// include : ����, �� file scope!

	printf("\n");
	print_address();			// my_function.h�� include�� my_function.c�� scope

	printf("\n");
	printheader();
	return 0;

}