#pragma once

#include <stdio.h>


static void different_function_in_different_file()
{
	printf("\ndifferent_function() in different file is called\n");
	printf("__func__ : %s\n", __func__);
	printf("__LINE__ : %d\n", __LINE__);		// �����ε� �� ���� ���� ǥ�õǴ°ɱ�?
												// MACRO : compile, ��ó�� �����̱� ����!
	printf("__FILE__ : %s\n", __FILE__);
}