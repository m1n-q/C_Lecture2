#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{
	/*
		malloc() : �޸� �Ҵ縸.
		calloc() : contiguous allocation, �޸� �Ҵ�, 0���� �ʱ�ȭ
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

		
		* 100�� �޸𸮷δ� �����ϴ�.
			- 200 �޸� �Ҵ�
			- 100 �޸� ����
			- 100 �޸� �ݳ� 

		-> realloc()�� �� ������ �ѹ��� ! (�ݳ��� �����ֳ�)
	*/

	for (int i = 0; i < n; ++i)
		ptr[i] = i + 1;

	n = 20;
	int* ptr2 = NULL;
	ptr2 = (int*)realloc(ptr, n*sizeof(int));
	//ptr = (int*)realloc(ptr, n * sizeof(int));		// �� �ڸ����� ����

	printf("%p %p\n", ptr, ptr2);
	printf("%d\n", *(ptr + 1));
	
	for (int i = 0; i < n; i++)
		printf("%d ", *(ptr2 + i));		// ���� �޸� ����, �߰��� �޸𸮴� �ʱ�ȭ �ȵ�


	return 0;

}