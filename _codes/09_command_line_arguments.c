#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


/* COMMAND LINE ���� EXE �� ������ ��. */

/* project properties - debugging���� ������ �����ϴ�. */


int main(int argc, char* argv[])	// parameter : 1. �ƿ� ���ų�, 2. �� ����
{							
	int count;

	printf("argc == %d\n", argc);
	printf("The command line has %d arguments:\n", argc);

	for (count = 0; count < argc; count++)
		printf("Arg %d : %s\n", count, argv[count]);

	printf("\n");
	

	return 0;

}