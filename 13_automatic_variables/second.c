#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>


//extern int g_int;

//extern int g_int = 777;	// file scope�� �ʱ�ȭ�� ����������,
							// �ٸ� ���Ͽ��� �̹� �ʱ�ȭ�� ����!
							
							// ���� ��ġ���� ���� �ߴٸ� ������ ��.
							// �ٵ� �� extern ���� ���� ��ġ���� �ʱ�ȭ ����.



void temp()
{
	//extern int g_int = 777;	// block �������� �ʱ�ȭ �Ұ���
	g_int += 1000;
}


void fun_sec()
{
	extern int g_int;
	temp();

	g_int += 7;
	printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}


