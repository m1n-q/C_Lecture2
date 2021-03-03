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
			
				
		* 'static' : 1. 메모리에서 고정적으로 존재하도록.
		*			 2. scope 를 현재 영역에 고정하도록.

		
		- STATIC VARIABLES
		- IN DATA or BSS !
*/

/* int* */void count()
{
	int ct = 0;				// - automatic storage duration
	printf("count = %d %lld\n", ct, (long long)&ct);
	ct++;					//  IN STACK

	/*return &ct;*/			// 이 block이 끝나면 사라질 변수!

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

	count();		// memory가 같게 나오는 이유 ?!
	count();		// 특정 메모리 주소를 계속 갖고 있는 것이 아니라,	
					// 실행되는 함수가 이것 뿐이라서 stack의 같은 곳을 사용하게 된 것 뿐.
					// 메모리가 계속 새로 배정 되는것임 !!!!!
	counter_caller();

	static_count();
	static_count();
	static_counter_caller();

	return 0;

}