#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



int main()
{	
	printf("DUMMY\n");

	for (int k = 0; k < 1000000; ++k)	// 메모리 누수 : free 안해주고 계속 메모리가 쌓이는것 
	{	
		int  n = 100000000;			// x86, x64 heap 크기 차이.
		int* ptr = (int*)malloc(n * sizeof(int));

		if (!ptr)
		{	
			printf("Malloc() failed");
			exit(EXIT_FAILURE);
		}
		for (int i = 0; i < n; ++i)
			ptr[i] = i + 1;
		
		
		//ptr_bu = ptr;


		//free(ptr);	// 진단 도구 snapshot
						// ptr_bu로 test.
	
	}

	
	
	/*for (int i = 0; i < 100; ++i)
		printf("%d ", *(ptr_bu + i));*/


	printf("DUMMY\n");
	

}