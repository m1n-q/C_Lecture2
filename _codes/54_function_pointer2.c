#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>	//toupper(), tolower()


// parameter �� ��ȯ���� ���� �Լ� -> ���� �����Ϳ� ����!

void toupperstr(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;

	}
}
void tolowerstr(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;

	}
}



// ����� �����ε�, �ϳ��� ���� �� ���� .

void updatestr(char* str, int(*pf)(int))	// tolower�� ������ ����
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}



int main()
{	
	char str[] = "Hello, World";

	void (*pf)(char*);

	pf = toupperstr;

	printf("String literal %lld\n", (long long)("Hello, World"));
	printf("Function pointer %lld\n", (long long)toupperstr);
	printf("Variable str %lld\n", (long long)str);

	(*pf)(str);
	//pf(str)
	printf("toupperstr  %s\n", str);

	
	
	pf = tolowerstr;
	(pf)(str);
	printf("tolowerstr  %s\n", str);


	/* 
		passing function pointers to function

	*/

	updatestr(str, toupper);
	printf("toupper %s\n", str);
	
	updatestr(str, tolower);
	printf("tolower %s\n", str);


	//NOTE: __cdecl is function calling convention

	return 0;

}