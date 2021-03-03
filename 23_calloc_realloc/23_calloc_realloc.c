#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{
	/*
		malloc() : 메모리 할당만.
		calloc() : contiguous allocation, 메모리 할당, 0으로 초기화
	*/


	int n = 10;
	int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * n); 
	ptr = (int*)calloc(n, sizeof(int));

	if (!ptr) exit(1);

	for (int i = 0; i < n; ++i)
		printf("%d ", ptr[i]);
	printf("\n");


	/*
		realloc()
		- doesn't initialize the bytes added
		- returns NULL if can't enlarge the memory block

		- if 1st argument (Block) is NULL, it works like malloc()
		- if 2nd argument (Size) is 0, it frees the memory block.

		
		* 100의 메모리로는 부족하다.
			- 200 메모리 할당
			- 100 메모리 복사
			- 100 메모리 반납 

		-> realloc()이 이 절차를 한번에 ! (반납은 안해주넹)
	*/

	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;
	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n*sizeof(int));
	//ptr = (int*)realloc(ptr, n * sizeof(int));		// 그 자리에서 연장

	printf("%p %p\n", ptr, ptr2);
	printf("%d\n", *(ptr + 1));
	
	for (int i = 0; i < n; i++)
		printf("%d ", *(ptr2 + i));		// 기존 메모리 복사, 추가된 메모리는 초기화 안됨


	return 0;

}