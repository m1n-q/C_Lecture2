#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Variable scopes (visibility)
	- block, function, prototype, file.
*/



void f1(int hello, double world);	// prototype scope ( != function body)

double func_block(double d)		
{
	double p = 0.0;

	int i;
	for (i = 0; i < 10; i++)
	{
		double q = d * i;
		p *= q;

		if (i == 5)
			goto hello;		// ����������, �ĺ��� ���� ���� ��� ����.

	}

hello:				
	printf("Hello, world");

	return p;
}

int main()
{

	func_block(1.0);
	

	return 0;

}