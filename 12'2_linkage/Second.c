#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Linkage

	Variables with file scope
	- External or Internal linkage

*/

/*

	compile 최소 단위 (transration unit) : FILE !
	두개의 File이 각각 compile 된 두 개의 object 파일을
	서로 연결해주는 LINKER !

*/

extern int el;	// 전역 변수 : 프로그램 전체에서 사용 가능!
//extern int il;	//	static 키워드로 scope가 파일 내로 제한되어 있다.



void testLinkage()
{
	printf("DoSomething called\n");
	printf("Second.c : %d\n", el);
	//printf("Second.c : %d\n", il);
	el++;
}