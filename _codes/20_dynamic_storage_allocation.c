#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>	  // malloc(), free()


/*
	STACK : scope(stack frame) 에 따라 
			stack에 자동적으로 들어갔다 나왔다 함.
	
			-> compile time (미리 결정)

	HEAP :	반납, 회수 전까지 계속 유지됨
		
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
					ㄴ type이 없는 순수한 주소! 크기만 정해짐!	
						ㄴ 직접 casting 
		
		free() : deallocating

	*/

	double* ptr = NULL;			// ptr 자체는 automatic duration!
								// 동적할당 받은 메모리는 존재하는데,
								// 접근할 포인터를 잃어버릴 수 있음!!

	ptr = (double*)malloc(30 * sizeof(double));		// runtime에 size 결정 가능

	
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
			printf("%f ", ptr[i]);			// 메모리할당 후 초기화 X
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