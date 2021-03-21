#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Generic selection expression
	- Generic programming : code is not spcific to a particular type

	_Generic : C11 keyword

	VS 에선 지원하지 않음.
*/

// X : expression
#define MYTYPE(X) _Generic((X), \
	int : (X + 123), \
	float : "float", \
	double : "double", \
	long : "long", \
	int* : "int*", \
	default : "other"\
)

int main()
{	

	int d = 5;

	printf("%d\n", MYTYPE(d));
	printf("%s\n", MYTYPE(2.0*d));
	printf("%s\n", MYTYPE(3L));
	printf("%s\n", MYTYPE(&d));


	return 0;

}