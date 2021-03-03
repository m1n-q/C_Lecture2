#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


extern int g_int;		//referencing declaration


static void tool(void)
{

}


/* static */ void fun_second(void)
{

	tool();


	g_int += 1;
	printf("g_int in fun_second() : %d %p\n", g_int, &g_int);
}

/*
	왜 굳이 static으로 막나 ?!

	EX ) 외부에서는 fun_second를 위해 사용된
		 tool 을 사용할 일이 없다고 판단될 때


*/