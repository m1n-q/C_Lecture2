#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include "DifferentFile.h"

void different_function();



int main()
{
	printf("__FILE__ : %s\n", __FILE__);
	printf("__DATE__ : %s\n", __DATE__);	
	printf("__TIME__ : %s\n", __TIME__);		// 전처리, compile 시점
	printf("__LINE__ : %d\n", __LINE__);		// 현재 line number
	printf("__func__ : %s\n", __func__);		// 현재 함수 이름


	different_function();

	different_function_in_different_file();
	printf("\n");
	
	
	/* NOT defined in VS */

	//printf("__STDC__ : %d\n", __STDC__);	// conforms to the C standard
	//printf("__STDC_HOSTED__ : %d\n", __STDC_HOSTED__);	// hosted vs freestanding implemntation
	//printf("__STDC_VERSION__ : %d\n", __STDC_VERSION__);


//#line 7
//	printf("__LINE__ after #line : %d\n", __LINE__);
//#line 1	"hello.txt"
//	printf("__LINE__ after #line : %d\n", __LINE__);
//	printf("__FILE__ : %s\n", __FILE__);


//#if __LINE__ != 38
//#error Not line 38
//#endif


//#if defined(_WIN64) != 1
//#error NOT WIN64 platform
//#endif

//#if __STDC_VERSION__ != 201112L
//#error Not C11
//#endif

	
	
	return 0;

}

void different_function()
{
	printf("\ndifferent_function() is called\n");
	printf("__func__ : %s\n", __func__);
	printf("__LINE__ : %d\n", __LINE__);
}