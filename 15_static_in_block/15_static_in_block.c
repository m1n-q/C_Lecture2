#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
		STORAGE CLASS

		- Automatic
		- Register
		- Static with internal linkage
		- Static with external linkage
		- Static without linkage

*/

/*
		Static without linkage
		- Static storage duration, block scope, no linkage.
		- 'static' keyword in block scope 
			
				
		* 'static' : 1. �޸𸮿��� ���������� �����ϵ���.
		*			 2. scope �� ���� ������ �����ϵ���.

		
		- STATIC VARIABLES
		- IN DATA or BSS !
*/

/* int* */void count()
{
	int ct = 0;				// - automatic storage duration
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;					//  IN STACK

	/*return &ct;*/			// �� block�� ������ ����� ����!

}

void static_count()
{
	static int ct = 0;		//- static stroage duration
							
	/*static int ct;		// initialized only once !
	ct = 0;*/				// assignment!

	printf("Static count = %d %lld\n", ct, (long long)&ct);
	ct++;					// STATIC

	
}

void counter_caller()
{
	count();
}


void static_counter_caller()
{
	static_count();
}




int main()
{	

	count();		// memory�� ���� ������ ���� ?!
	count();		// Ư�� �޸� �ּҸ� ��� ���� �ִ� ���� �ƴ϶�,	
					// ����Ǵ� �Լ��� �̰� ���̶� stack�� ���� ���� ����ϰ� �� �� ��.
					// �޸𸮰� ��� ���� ���� �Ǵ°��� !!!!!
	counter_caller();

	static_count();
	static_count();
	static_counter_caller();

	return 0;

}