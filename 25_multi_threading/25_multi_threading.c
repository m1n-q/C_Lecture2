#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>	// 멀티쓰레딩은 운영체제에서 제공


// _Atomic int acnt = 0;	// NA

DWORD WINAPI ThreadFunc(void* data)
{
	int n = 1;
	sleep(1000);
	//acnt += n;	// NA
	return 0;
}

int main()
{	
	HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	if (thread)
		WaitForSingleObject(thread, INFINITE);

	return 0;

}