#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 
	Storage duration	: �޸��� ���ӱⰣ

	- static stroage duration : ���α׷� ���� ~ ��
			- external linkage : ��� �Լ� �� ����, compile ���� �ܺ� ���� OK
			- internal linkage : ��� �Լ� ��, static, compile ���� ���ο�����
			- no linkage	   : block ��, static
	- automatic storage duration : ���� ����
	- allocated storage duration : ���� �Ҵ�
	- thread storage duration : ��Ƽ������
*/

void count()		
{
	int ct = 0;				// - automatic storage duration
	printf("Count = %d\n", ct);
	ct++;
							
}

void static_count()
{
	static int ct = 0;		//- static stroage duration : linkage���� �ٸ� ����.
	printf("Static count = %d\n", ct);
	ct++;

}

int main()
{	
	count();
	count();
	static_count();
	static_count();		// ct : no linkage, scope �ۿ��� ����� �ȵ�����
						//		static storage duration, ���α׷��� ������ ����


	return 0;

}