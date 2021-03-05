#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


/*
#pragma tokens (ex: once)
*/


//#pragma pack(1)		// padding
//_Pragma("pack(1)")	// destringizing : remove first and last ", \" -> "
//#define PACK1 _Pragma("pack(1)")
//PACK1

//#pragma warning( disable : 4477 )
//#pragma warning( error : 4477 )

struct s
{
	int i;
	char ch;
	double d;
};

int main()
{
	// x64
	struct s A;

	printf("Size of A is : %d", sizeof(A));	// %d to Warning C 4477

	return 0;

}