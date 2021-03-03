#define _CRT_SECURE_NO_WARININGS
#include <stdio.h>


//extern int g_int;

//extern int g_int = 777;	// file scope라서 초기화는 가능하지만,
							// 다른 파일에서 이미 초기화가 됐음!
							
							// 기존 위치에서 선언만 했다면 가능은 함.
							// 근데 걍 extern 말고 기존 위치에서 초기화 권장.



void temp()
{
	//extern int g_int = 777;	// block 범위에서 초기화 불가능
	g_int += 1000;
}


void fun_sec()
{
	extern int g_int;
	temp();

	g_int += 7;
	printf("g_int in fun_sec() %d %p\n", g_int, &g_int);
}


