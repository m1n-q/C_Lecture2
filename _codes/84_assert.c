#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

#include <limits.h>
_Static_assert(CHAR_BIT == 9, "9-bit char falsely assumed");
//빌드 자체를 막음, VS X

int divide(int a, int b)
{
	assert(b != 0);		// 반드시 만족해야하는 조건, Debug mode용
						// retry -> debug 진입
						// 아래 if문처럼 처리하기 보다는, assert로 딱 막아놓고
						// 근본적인 문제 처리를 다른 곳에서 하자
	

	//if (b == 0) {
	//	printf("Cannot divide\n");
	//	exit(1);
	//}			overhead : 효율성 저하

	


	return a / b;
}

int main()
{	
	int a, b;
	int f = scanf("%d%d", &a, &b);

	printf("a / b = %d", divide(a, b));


	return 0;

}