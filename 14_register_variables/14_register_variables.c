#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
		STORAGE CLASS

		- Automatic
		- Register
		- Static with internal linkage
		- Static with external linkage
		- Static without linkage

*/

/*
		Register Storage Class
		- Automatic storage duration, block scope, no linkage.
		- Any variable declared in a block or function header

		- IN REGISTER or STACK !
*/

void temp(register int r)
{
	// do sth w/ r
}
int main()
{	
	register int r;		// �������̸� register�� ��ġ�ϵ��� '��û'
	r = 123;


	//printf("%p\n", &r);		// ERROR : '�޸�(�ֱ����ġ)' �� ��ġ�ϴ� �� �ƴϱ� ����
	//int* ptr = &r;


	return 0;

}