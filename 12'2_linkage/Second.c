#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Linkage

	Variables with file scope
	- External or Internal linkage

*/

/*

	compile �ּ� ���� (transration unit) : FILE !
	�ΰ��� File�� ���� compile �� �� ���� object ������
	���� �������ִ� LINKER !

*/

extern int el;	// ���� ���� : ���α׷� ��ü���� ��� ����!
//extern int il;	//	static Ű����� scope�� ���� ���� ���ѵǾ� �ִ�.



void testLinkage()
{
	printf("DoSomething called\n");
	printf("Second.c : %d\n", el);
	//printf("Second.c : %d\n", il);
	el++;
}