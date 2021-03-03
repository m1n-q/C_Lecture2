#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{	
	int ch;
	FILE* fr;	//TODO: file pointer to write
	FILE* fw;

	unsigned long count = 0;

	if (argc != 3)
	{
		printf("Usage : %s <filename> <output> \n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n",argv[1]);
		exit(EXIT_FAILURE);
	}
	

	/*
		fopen mode for text file
		- r : reading
		- w : over-writing / creating-and-writing
		- a : appending / creating-and-writing
		- r+ : reading + writing
		- w+ : reading + writing, over-wrinting
		- a+ : reading + writing, appending
	*/

	//TODO: open file to write with "w"


	fw = fopen(argv[2], "a");
	

	while ((ch = fgetc(fr)) != EOF)	// getc(fr)
	{
		//putc(ch, stdout);	// same as putchar(ch)
		fputc(ch, stdout);	
		fputc(ch, fw);

		//TODO: use fputs() to write a file stream

		count++;
	}
	printf("\n");

	fclose(fr);
	fclose(fw);

	printf("FILE %s has %lu characters\n", argv[1], count);

	return 0;

}