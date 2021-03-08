#pragma once
#include "my_functions.h"

#include <stdio.h>

int status = 0;

int add(int a, int b)
{
	return a + b;
}



void print_status()
{
	printf("In print_status()\nAddress = %p, Value = %d\n", &status, status);
}
void print_address()
{
	printf("In my_functions.c, print_address()\n");
	printf("Static function address %p\n", multiply);
	printf("Static variable address %p\n", &si);
}