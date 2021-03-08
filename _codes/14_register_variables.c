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
	register int r;		// 가급적이면 register에 위치하도록 '요청'
	r = 123;


	//printf("%p\n", &r);		// ERROR : '메모리(주기억장치)' 에 위치하는 게 아니기 때문
	//int* ptr = &r;


	return 0;

}