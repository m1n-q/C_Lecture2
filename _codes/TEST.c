#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{

	char* arr[] = { "apple", "kiwi" };

	printf("%p\n", &"apple");
	printf("%p\n", &arr[0][0]);
	printf("%p\n", &arr[0]);

	// "apple" => "a" �� ���� ������.
	// arr[0]  =? "apple" �� ���� ������. �� "a"�� ���� �������� ������.



	//&arr + 1
	//	arr + 1

	//*arr
	//**&arr
	char str[100] = { 0, };
	char a = 'a';
	_itoa(10, str, 10);
	printf("%s", str);

	return 0;

}