#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//TODO: try increasing/decreasing order
//TODO: try other types
int compare(const void* first, const void* second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;

}
int compare2(const void* first, const void* second)
{
	if (*(double*)first > *(double*)second)
		return 1;
	else if (*(double*)first < *(double*)second)
		return -1;
	else
		return 0;

}
int main()
{
	int arr[] = { 8, 2, 5, 3, 6, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	double darr[] = { 1.2, 3.4, 0.7, 1.0, 5.5 };
	int dn = sizeof(darr) / sizeof(darr[0]);
	
	qsort(darr, dn, sizeof(darr[0]), compare2);
	
	for (int i = 0; i < dn; i++)
		printf("%.1f ", darr[i]);


	return 0;

}