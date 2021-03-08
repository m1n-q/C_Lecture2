#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Linkage

	Variables with block, function, prototype scope
	- No linkage

	Variables with file scope
	- External or Internal linkage

*/

/*

	compile 최소 단위 (transration unit) : FILE !
	두개의 File이 각각 compile 된 두 개의 object 파일을
	서로 연결해주는 LINKER !

*/


int el;			// file scope with external linkage (global)
				// -> extern 을 통해 어떤 transration unit에서든 사용가능

static int il;	// file scope with internal linkage 
				// static 키워드로 scope가 file scope 로 제한되어 있다.


void testLinkage();	// prototype 선언으로 다른 file의 함수 LINKING

int main()
{	
	el = 1024;

	testLinkage();
	printf("%d\n", el);

	return 0;

}