#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Function call has overhead (�߰����� ����)
	- set up the call, pass arguments, jump to the function code, and return.
						( �� ���� )

	-> Overhead�� ���ֱ� ���� ���
		1.	Function-like Macro 
		2.	Inline Function


	Inline function specifier
	- Suggests inline replacements.
	( �ڵ� �߰��� �� �Լ��� ������ �׳� �����ش޶�� " ���� " )


	Inline functions should be short.
	A function with internal linkage can be made inline. (GCC, clang)
	You can't take its address. (�ܼ� ����)

	cf) �޸� ��򰡿� �ִ� function�� �ʿ��Ҷ����� �ش� �ּҿ��� ������ ��.
*/

#define FOO 5

inline int foo() 
{
	return 5;
}

// Driver code
int main()
{	
	int ret;

	// inline function call
	ret = foo();
	//ret = 5;
	//ret = FOO;

	printf("Output is: %d\n", ret);		// if foo() in for ?

	return 0;

}