#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 
	Storage duration	: 메모리의 지속기간

	- static stroage duration : 프로그램 시작 ~ 끝
			- external linkage : 모든 함수 밖 선언, compile 단위 외부 연결 OK
			- internal linkage : 모든 함수 밖, static, compile 단위 내부에서만
			- no linkage	   : block 안, static
	- automatic storage duration : 지역 변수
	- allocated storage duration : 동적 할당
	- thread storage duration : 멀티쓰레딩
*/

void count()		
{
	int ct = 0;				// - automatic storage duration
	printf("Count = %d\n", ct);
	ct++;
							
}

void static_count()
{
	static int ct = 0;		//- static stroage duration : linkage랑은 다른 문제.
	printf("Static count = %d\n", ct);
	ct++;

}

int main()
{	
	count();
	count();
	static_count();
	static_count();		// ct : no linkage, scope 밖에서 사용은 안되지만
						//		static storage duration, 프로그램의 끝까지 지속


	return 0;

}