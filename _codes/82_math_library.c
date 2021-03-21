#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>
#include <tgmath.h>		// type generic macros, VS X


//Generic Selection Expression
#define SQRT(X) _Generic((X), \
long double: sqrtl, \
default: sqrt, \
float: sqrtf)(X)

int main()
{	
	printf("%f\n", cos(3.141592));


	double c = 5.0, b = 4.0, a;
	a = sqrt(c * c - b * b);
	printf("a = %f\n", a);


	float cf = 5.0f, bf = 4.0f, af;
	af = sqrtf(cf * cf - bf * bf);
	printf("af = %f\n", af);


	/* 
		Type Variants
	*/

	double t1 = SQRT(2.0f);
	double t2 = SQRT(2.0);

	if (t1 == t2)
		printf("Identical\n");
	else
		printf("Not identical\n");


	/*
		math.h    vs	tgmath.h 

		identical		not identical

	*/

	double a1 = sqrt(2.0f);
	double a2 = sqrt(2.0);

	// cf) 1.0f/3.0f , 1.0/3.0

	if (a1 == a2)
		printf("Identical\n");
	else
		printf("Not identical\n");



	return 0;

}