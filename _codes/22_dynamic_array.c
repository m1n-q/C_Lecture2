#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


int main()
{	

	/*
		one variable
	*/

	//int* ptr = NULL;

	//ptr = (int*)malloc(sizeof(int) * 1);
	//if (!ptr)exit(1);

	//*ptr = 1024 * 3;
	//printf("%d\n", *ptr);
	//
	//free(ptr);
	//ptr = NULL;


	
	/*
		1D array
	*/

	//int n = 3;
	//int *ptr = (int*)malloc(sizeof(int) * n);
	//if (!ptr)exit(1);

	//ptr[0] = 123;
	//*(ptr + 1) = 456;
	//*(ptr + 2) = 789;

	//
	//free(ptr);
	//ptr = NULL;


	/*
		2D array
	*/

	//int row = 3, col = 2;
	//int(*ptr)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
	//
	////int(*ptr)[col] = (int(*)[col])malloc(sizeof(int) * row * col);	//VLA

	//for (int i = 0; i < row; i++)
	//	for (int j = 0; j < col; j++)
	//		*(*(ptr + i) + j) = i+ j*row;
			
	
	

	/*
		Using 1D array as 2D array

		row = 3, col = 2

		(r, c)

		2D
		(0, 0) (0, 1)
		(1, 0) (1, 1)
		(2, 0) (2, 1)

		1D
		(0, 0) (0, 1) (1, 0) (1, 1) (2, 0) (2, 1) 
  		 0	    1	   2	  3	     4		5		=  c + col * r

	*/



	//int row = 3, col = 2;
	//int* ptr = (int*)malloc(row * col * sizeof(int));
	//if (!ptr)	exit(1);

	//for (int r = 0; r < row; r++)
	//	for (int c = 0; c < col ; c++)
	//		ptr[c + col * r] = c + col * r;

	//for (int r = 0; r < row; r++)
	//{
	//	for (int c = 0; c < col; c++)
	//		printf("%d ", *(ptr + c + col * r));
	//	printf("\n");
	//}




	/*
		1D array as 3D array
	*/

	int row = 3, col = 2, dep = 5;


	int* ptr = (int*)malloc(row * col * dep * sizeof(int));
	if (!ptr)	exit(1);

	for (int z = 0; z < dep; z++)
		for (int x = 0; x < row; x++)
			for (int y = 0; y < col; y++)
				ptr[y + col * x + (col * row) * z] = y + col * x + (col * row) * z;

	for (int z = 0; z < dep; z++)
	{
		for (int x = 0; x < row; x++)
		{
			for (int y = 0; y < col; y++)
				printf("%d ", ptr[y + col * x + (col * row) * z]);
			printf("\n");
		}
		printf("\n");
	}
	



	return 0;

}