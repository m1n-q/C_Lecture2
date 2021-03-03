#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>	  // malloc(), free()


/*
	STACK : scope(stack frame) �� ���� 
			stack�� �ڵ������� ���� ���Դ� ��.
	
			-> compile time (�̸� ����)

	HEAP :	�ݳ�, ȸ�� ������ ��� ������
		
			-> run time	
*/




int main()
{	
	float x;
	char str[] = "Dancing with a star";

	int arr[100];

	/*
		malloc(size) returns a "void type pointer"
		void* : generic pointer
					�� type�� ���� ������ �ּ�! ũ�⸸ ������!	
						�� ���� casting 
		
		free() : deallocating

	*/

	double* ptr = NULL;			// ptr ��ü�� automatic duration!
								// �����Ҵ� ���� �޸𸮴� �����ϴµ�,
								// ������ �����͸� �Ҿ���� �� ����!!

	ptr = (double*)malloc(30 * sizeof(double));		// runtime�� size ���� ����

	
	if (ptr == NULL)
	{
		puts("Memory allocation failed.");

		/*
			exit(EXIT_FAILURE) : 1
			exit(EXIT_SUCCESS) : 0
		*/

		exit(EXIT_FAILURE);
	}

	printf("Before free : %p\n", ptr);
	
	free(ptr);
	
	printf("After free : %p\n", ptr);

	ptr = NULL;	



	/* Dynamically Allocated Array */

	int n = 5;
	ptr = (double*)malloc(n * sizeof(double));

	if (ptr != NULL)
	{
		
		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);			// �޸��Ҵ� �� �ʱ�ȭ X
		printf("\n");


		for (int i = 0; i < n; ++i)
			*(ptr + i) = (double) i;
		

		for (int i = 0; i < n; ++i)
			printf("%f ", ptr[i]);
		printf("\n");


	}
	free(ptr);
	ptr = NULL;


	/*
		Comparison to VLA

		VLA
		- VS X
		- automatic duration, cannot be resized
		- limited by STACK size
	
		
	*/






	return 0;

}