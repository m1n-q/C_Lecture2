#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

void selectionSort(char* arr[], int length);
void printArr(char* arr[], int length);


int main()
{	
	/* pointer 의 배열인거 생각하기............... */

	char* arr[] = {"AppleRa", "Boss", "Kiwi", "Apple", "Banana","Ramen" };
	int n = sizeof(arr) / sizeof(arr[0]);	// pointer 의 배열이자나... size 동일하지...

	/*selectionSort(arr, n);
	printArr(arr, n);*/


	printf("%u\n", (unsigned)&arr[0]);
	printf("%u\n", (unsigned)&arr[1]);
	printf("%u\n", (unsigned)&arr[2]);
	printf("%u\n", (unsigned)&arr[3]);
	printf("%u\n", (unsigned)&arr[4]);
	printf("%u\n", (unsigned)&arr[5]);

	printf("\n");
	printf("%u\n", (unsigned)arr[0]);
	printf("%u\n", (unsigned)arr[1]);
	printf("%u\n", (unsigned)arr[2]);
	printf("%u\n", (unsigned)arr[3]);
	printf("%u\n", (unsigned)arr[4]);
	printf("%u\n", (unsigned)arr[5]);

	printf("\n");
	printf("%u\n", (unsigned)*(arr+1));

	return 0;

}
void selectionSort(char* arr[], int length)
{

	unsigned start_idx = 0;
	unsigned min_idx;
	char* tmp;


	while (start_idx < length)
	{
		min_idx = start_idx;

		for (int i = start_idx; i < length; i++)
		{
			if (strcmp(*(arr + i), *(arr + min_idx)) == -1)		// < 0
				min_idx = i;

		}


		tmp = *(arr + start_idx);				//swap
		*(arr + start_idx) = *(arr + min_idx);
		*(arr + min_idx) = tmp;
		start_idx++;
	}
}

void printArr(char* arr[], int length)
{
	for (int i = 0; i < length; ++i)
		printf("%s ", *(arr + i));
}
