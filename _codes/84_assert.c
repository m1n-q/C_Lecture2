#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 9, "9-bit char falsely assumed");
//���� ��ü�� ����, VS X

int divide(int a, int b)
{
	assert(b != 0);		// �ݵ�� �����ؾ��ϴ� ����, Debug mode��
						// retry -> debug ����
						// �Ʒ� if��ó�� ó���ϱ� ���ٴ�, assert�� �� ���Ƴ���
						// �ٺ����� ���� ó���� �ٸ� ������ ����
	

	//if (b == 0) {
	//	printf("Cannot divide\n");
	//	exit(1);
	//}			overhead : ȿ���� ����

	


	return a / b;
}

int main()
{	
	int a, b;
	int f = scanf("%d%d", &a, &b);

	printf("a / b = %d", divide(a, b));


	return 0;

}