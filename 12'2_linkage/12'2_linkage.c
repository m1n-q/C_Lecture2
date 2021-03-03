#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Linkage

	Variables with block, function, prototype scope
	- No linkage

	Variables with file scope
	- External or Internal linkage

*/

/*

	compile �ּ� ���� (transration unit) : FILE !
	�ΰ��� File�� ���� compile �� �� ���� object ������
	���� �������ִ� LINKER !

*/


int el;			// file scope with external linkage (global)
				// -> extern �� ���� � transration unit������ ��밡��

static int il;	// file scope with internal linkage 
				// static Ű����� scope�� file scope �� ���ѵǾ� �ִ�.


void testLinkage();	// prototype �������� �ٸ� file�� �Լ� LINKING

int main()
{	
	el = 1024;

	testLinkage();
	printf("%d\n", el);

	return 0;

}