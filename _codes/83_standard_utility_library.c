#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>    // not in VS





/*
	rand(), srand(), malloc(), free(), exit(), qsort() ...
*/




// function specifier _Noreturn
// causes undefined behavior if i <= 0
// exits if i > 0

_Noreturn void stop_now(int i)	// _Noreturn : 이 함수가 끝나고 어딘가로 돌아가지 않는다.
{
	if (i > 0) 
	{
		;
		// exit(i);
	}
	// return i;
}






void good_bye(void)
{
	printf("Good bye\n");
}

void thankyou(void)
{
	printf("Thank you\n");
}
int main()
{	
	/* 
		atexit() : 프로그램 종료시, 실행될 함수 등록 (pointer)

		- 함수 pointer의 목록 !
		- runtime에 결정
	*/


	// stop_now(20);

	printf("Purchased?\n");
	if (getchar() == 'y')
		atexit(thankyou);			// 함수 등록!

	while (getchar() != '\n');

	printf("Goodbye message ?\n");
	if (getchar() == 'y')
		atexit(good_bye);			


	
	return 0;

}