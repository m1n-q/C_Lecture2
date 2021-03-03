#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc()

/*

char arr[] = "Hello";		// 배열이 메모리를 가지고 있고, 거기에 문자가 저장됨
char *str = "Hello";		// 문자열 Literal이 있고, pointer가 참조할 뿐!
							// 문자열 Literal은 Read only segment (전역) 에 있어.

str[1] = 'm' <- ERROR!!



*/
void test_function()
{
	int j;
	printf("Stack (high) \t%u\n", &j);
}

int main()
{	

	/* ARRAY vs POINTER */

	const char* pt2 = "I am a string";
	const char* pt3 = "I am a string";
	const char* pt4 = "I am a string!!";

	const char ar1[] = "I am a string";
	const char ar2[] = "I am a string";
	const char ar3[] = "I am a string!!!";


	printf("RO data (low) \t%u %u %u %u\n",
		(unsigned)pt2, (unsigned)pt3, (unsigned)pt4, (unsigned)"I am a string");

	printf("Stack (high) \t%u %u %u\n",
		(unsigned)ar1, (unsigned)ar2, (unsigned)ar3);


	// compiler가 동일한 literal을 하나로 저장!
	// array는 각각 자신의 메모리에 복사!



	/**** Memory address check ****/

	/* Local Variables */

	printf("Stack (high) \t%u %u %u\n",
		(unsigned)&pt2, (unsigned)&pt3, (unsigned)&pt4);

	int i;
	printf("Stack (high) \t%u\n", (unsigned)&i);



	/* Local Variables in a function */
	
	test_function();



	/* Dynamic allocation */
	char* p5 = (char*)malloc(sizeof(char) * 100);
	printf("Heap (middle) \t%u\n", (unsigned)p5);

	char* p6 = (char*)malloc(sizeof(char) * 100);
	printf("Heap (middle) \t%u\n", (unsigned)p6);


	/* ARRAY vs POINTER */

	//ar1++; //ERROR
	pt2++;	 //OK
	puts(pt2);


	/* ARRAY and POINTER Difference */

	char heart[] = "I love you";
	char *head = "I hate you";

	for (int i = 0; i < 6; i++)
		putchar(heart[i]);
	putchar('\n');


	for (int i = 0; i < 6; i++)
		putchar(head[i]);
	putchar('\n');



	// pointer addition

	for (int i = 0; i < 6; i++)
		putchar(*(heart + i));
	putchar('\n');


	for (int i = 0; i < 6; i++)
		putchar(*(head + i));
	putchar('\n');
		


	while (*(head) != '\0')
		putchar(*(head++));
	putchar('\n');
		


	head = heart;	
	//heart = head;	// ERROR



	char* word = "Google";
	//word[2] = 'o';	// Run-time error! read only memory.	(text segement)
	puts(word);


	// Note : const char * word    <- is recommended


	const char* str1 = "MY NAME IS MINKYU";
	const char* copy;

	copy = str1;			// 주소를 복사하는 것! 텍스트의 위치는 같다.


	printf("%s %p %p\n", str1, str1, &str1);
	printf("%s %p %p\n", copy, copy, &copy);
	
	// strcpy(), strncpy()
	
	return 0;

	
}