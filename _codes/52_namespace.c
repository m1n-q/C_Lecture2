#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Namespace
	- Identify parts of a program in which a name is recognized
	- You can use the same name for one variable and one tag. ( not function )
	- C++ : use 'namespace' to use the same identifiers in the duplicated scopes.
*/
int iamfunc()
{
	return 1;
}

//int a = 123;		// Linking시 오류
					// 1>other.obj : error LNK2005: _a이(가) 52_namespace.obj에 이미 정의되어 있습니다.
					// extern 으로 불러오지 않아도 오류
int main()
{	

	int myname = 123;
	{
		int myname = 345;
		//double myname = 3.14;	//Error
	}



	struct rect { double x; double y; };	// rect is tag.

	//int rect = 123;		// rect is variable ( OK in C )
	//struct rect rect = { 1.1, 2.2 };		// rect is variable.  


	typedef struct rect rect;
	//rect rect = { 1.1,2.2 };	// Not OK ( rect is type ? )


	//int iamfunc = iamfunc();	// ERROR

	/*
		Namespace pollution
		- Names in different files accidentally conflicting with each other
	*/
	
	
	return 0;

}