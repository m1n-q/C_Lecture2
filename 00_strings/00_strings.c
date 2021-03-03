#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MESSAGE "A symboic string constant"
#define MAXLENGTH 81




int main()
{	
	char words[MAXLENGTH] = "A string in an array";
	const char* pt1 = "A poitner to a string";

	puts("puts() adds a newline at the end");	// 문자열 literal
	puts(MESSAGE);	// symbolic constant
		
	puts(words);	// char* []
	puts(pt1);	// OK
	words[3] = 'p';
	puts(words);
	//pt1[8] = 'a'	// Compile Error ( const 없으면 Runtime error : 읽기 전용 문자열?)

	char greeting[50] = "Hello, and "" How are""YOU!";
	// OK


	printf("%s, %p, %c\n", "We", "are", *"PROGRAMMER");



	const  char m1[15] = "LOVE YOU!";	

	for (int i = 0; i < 15; i++)
		printf("%d ", (int)m1[i]);		// null character
	printf("\n");


	const  char m2[15] = { 'L','O','V','E',' ','Y','O','U','\0' };

	for (int i = 0; i < 15; i++)
		printf("%d ", (int)m1[i]);		// null character
	printf("\n");

	const  char m3[] = "LOVE, YOU~ !";



	char truth[10] = "TRUTH IS ";
	if (truth == &truth[0]) puts("true!");
	if (*truth == 'T') puts("true!");
	if (*(truth + 1) == truth[1]) puts("true!");
	if (truth[1] == 'R') puts("true!");



	return 0;

}