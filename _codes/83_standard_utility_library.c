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

_Noreturn void stop_now(int i)	// _Noreturn : �� �Լ��� ������ ��򰡷� ���ư��� �ʴ´�.
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
		atexit() : ���α׷� �����, ����� �Լ� ��� (pointer)

		- �Լ� pointer�� ��� !
		- runtime�� ����
	*/


	// stop_now(20);

	printf("Purchased?\n");
	if (getchar() == 'y')
		atexit(thankyou);			// �Լ� ���!

	while (getchar() != '\n');

	printf("Goodbye message ?\n");
	if (getchar() == 'y')
		atexit(good_bye);			


	
	return 0;

}