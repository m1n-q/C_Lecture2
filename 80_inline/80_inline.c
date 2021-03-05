#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Function call has overhead (추가적인 업무)
	- set up the call, pass arguments, jump to the function code, and return.
						( 값 복사 )

	-> Overhead를 없애기 위한 방법
		1.	Function-like Macro 
		2.	Inline Function


	Inline function specifier
	- Suggests inline replacements.
	( 코드 중간에 이 함수의 내용을 그냥 복사해달라는 " 제안 " )


	Inline functions should be short.
	A function with internal linkage can be made inline. (GCC, clang)
	You can't take its address. (단순 복붙)

	cf) 메모리 어딘가에 있는 function을 필요할때마다 해당 주소에서 가져다 씀.
*/

#define FOO 5

inline int foo() 
{
	return 5;
}

// Driver code
int main()
{	
	int ret;

	// inline function call
	ret = foo();
	//ret = 5;
	//ret = FOO;

	printf("Output is: %d\n", ret);		// if foo() in for ?

	return 0;

}