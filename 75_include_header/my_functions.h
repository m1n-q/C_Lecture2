#pragma once
#include <stdio.h>

#ifndef __MY_FUNCTIONS__
#define __MY_FUNCTIONS__

//#include "my_functions.h"



extern int status;

static int si = 0;

/* extern */int add(int a, int b);

static int multiply(int a, int b)
{
	return a * b;
}

//int subtract(int a, int b)
inline int subtract(int a, int b)
{
	return a - b;
}

void print_status();
void print_address();

void printheader()
{
	printf("In my_function.h\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);
}

#endif // !__MY_FUNCTIONS__