#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



void selectionSort(int arr[], int length);
void printArr(int arr[], int length);

int main()
{	

	int arr[] = { 64, 85, 2, 77, 101, 3, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectionSort(arr, n);
	printArr(arr, n);






	return 0;

}
void selectionSort(int arr[], int length)
{

	unsigned start_idx = 0;
	unsigned min_idx;
	int tmp;

	
	while (start_idx < length)
	{
		min_idx = start_idx;

		for (int i = start_idx; i < length; i++)
		{
			if (*(arr + i) <= *(arr + min_idx))
				min_idx = i;

		}


		tmp = *(arr + start_idx);				//swap
		*(arr + start_idx) = *(arr + min_idx);
		*(arr + min_idx) = tmp;
		start_idx++;
	}
}

void printArr(int arr[], int length)
{
	for (int i = 0; i < length; ++i)
		printf("%d ", *(arr + i));
}