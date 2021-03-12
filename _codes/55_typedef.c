#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	typedef specifier
	- Give symbolic names (or aliases) to types
	- Does not create new types.
*/


int main()
{	
	typedef unsigned char BYTE;	

	BYTE x, y[10] = { 0, }, * z = &x;		// unsigned char

	{
		typedef unsigned char byte;		// Note the scope of BYTE

		/* Portable data types */

		size_t s = sizeof(byte); // unsinged int(x86)
								 // unsinged long long(x64)

		// unsinged int s = sizeof(byte);		// x86에서만
		// unsinged long long s = sizeof(byte);	// x64에서만 ?

		// go to definition of size_t
	}
	
	//byte b;		// typedef has scope

	// time_t t = time(NULL);

	/*
		typedef		vs		 #define
		
	*/

	typedef char* STRING;		

	STRING name, sign;		// NOTE: the type of sign
	

	/* 
		typedef : by compiler, not the preprocessor 
	
	*/

	/*
		#define STRING char*

		STRING name, sign;		// NOTE: the type of sign
		char * name, * sign;	
	*/	
	

	typedef struct complex {
		float real;
		float imag;
	}	COMPLEX;		// typedef struct complex COMPLEX


	typedef struct { double width; double height; } rect; // No tag


	rect r1 = { 1.1, 2.2 };
	rect r2 = r1;




	return 0;

}	