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
		�����Ͱ� (��ȯ��, parameter)�� �˾ƾ���

		cf) �Ϲ� ������ : �ڷ����� ����� �˾ƾ���
	*/

	void (*pf1)() = func1;			// �Լ��� �̸� ��ü�� �ڵ忡 ���� pointer
	//void (*pf1)() = &func1;		// both OK

	int (*pf2)(char) = func2;


	(*pf1)();		// call func via pf1
	//pf1();		// both OK

	int a = pf2('A');

	printf("%d\n", a);

	return 0;

}