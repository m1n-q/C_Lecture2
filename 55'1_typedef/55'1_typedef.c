#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	"One good way to synthesize declaration is 
	in small steps with typedef . . ."
*/

/* Complicated Function Declarations */

char char3[3] = { 'A', 'B', 'C' };



//double (*ptr)[3] : double 3�� �迭�� ������
//char (*ptr)[3] : char 3�� �迭�� ������
//char (*complicated_function1())[3] : char 3�� �迭�� ������ return�ϴ� �Լ�
char (*complicated_function1())[3]
{
	return &char3;

	//char 3�� �迭�� ������ return�ϴ� �Լ�
}


typedef char(*FRPTC())[3]; //char 3�� �迭�� ������ return�ϴ� �Լ� �ڷ���
typedef char(*(*PTFRPTC3)())[3];


/* Use typedef to make declaration simpler */

typedef char c3[3];			// char 3��¥�� �迭

c3* complicated_function2()
{
	return &char3;		// returns a pointer to char[3]
}

int main()
{	
	char (*(*fptr)())[3] = complicated_function1;
	//char 3�� �迭�� ������ return�ϴ� �Լ��� ������

	
	FRPTC* fptr2 = complicated_function1;	//char 3�� �迭�� ������ return�ϴ� �Լ� �ڷ���./ �� ������
	PTFRPTC3 fptr3 = complicated_function1;

	char(*ret_val)[3] = fptr();
	printf("%c %c %c\n", (*ret_val)[0], (*ret_val)[1], (*ret_val)[2]);


	c3* my_c3 = fptr2();	// char*3�� ���� ������
	printf("%c %c %c\n", (*my_c3)[0], (*my_c3)[1], (*my_c3)[2]);


	return 0;

}