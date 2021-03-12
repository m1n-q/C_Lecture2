#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void func1()
{
	return;
}

int func2(char i)
{
	return (int)i;
}

int main()
{	
	/*
		포인터가 (반환형, parameter)를 알아야함

		cf) 일반 포인터 : 자료형의 사이즈를 알아야함
	*/

	void (*pf1)() = func1;			// 함수의 이름 자체가 코드에 대한 pointer
	//void (*pf1)() = &func1;		// both OK

	int (*pf2)(char) = func2;


	(*pf1)();		// call func via pf1
	//pf1();		// both OK

	int a = pf2('A');

	printf("%d\n", a);

	return 0;

}