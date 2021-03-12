#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


/* COMMAND LINE 에서 EXE 로 실행할 것. */

/* project properties - debugging에서 설정도 가능하다. */


int main(int argc, char* argv[])	// parameter : 1. 아예 없거나, 2. 이 형태
{							
	int count;

	printf("argc == %d\n", argc);
	printf("The command line has %d arguments:\n", argc);

	for (count = 0; count < argc; count++)
		printf("Arg %d : %s\n", count, argv[count]);

	printf("\n");
	

	return 0;

}