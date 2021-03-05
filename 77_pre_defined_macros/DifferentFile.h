#pragma once

#include <stdio.h>


static void different_function_in_different_file()
{
	printf("\ndifferent_function() in different file is called\n");
	printf("__func__ : %s\n", __func__);
	printf("__LINE__ : %d\n", __LINE__);		// 복붙인데 왜 여기 줄이 표시되는걸까?
												// MACRO : compile, 전처리 시점이기 때문!
	printf("__FILE__ : %s\n", __FILE__);
}