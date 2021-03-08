#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Motivation

	int c= 0; // red: 0, blue: 1, green: 2, ..
	
	if (c == 0)
		printf("red");
		.
		.
		.
	if (c == 2)
		printf("green");
		.
		.
		.

*/


int main()
{	
	/*
		Enumerated Type
		- Symbolic names to represent integer constants
		- Improve readability, easy to maintain
		- enum-specifier	( struct-specifier , union-specifier )


		Enumerators
		- The symbolic constants
	*/

	enum spectrum { red, orange, yellow, green, blue, violet} ;

	enum spectrum color;
	//printf("color = %lld", (long long)&color);

	color = blue;
	if (color == yellow)
		printf("yellow\n");		// Note : enumerators are not strings

	for (color = red; color <= violet; color++)
		printf("%d\n", color);

	
	enum levels { low = 100, medium = 500, high = 2000 };

	int score = 800;
	if (score > high)
		printf("High score!\n");
	else if (score > medium)
		printf("Good job!\n");
	else if (score > low)
		printf("Not bad\n");
	else
		printf("Do your best\n");


	enum pet { cat, dog = 10, lion, tiger };

	printf("cat %d\n", cat);
	printf("lion %d\n", lion);



	return 0;

}