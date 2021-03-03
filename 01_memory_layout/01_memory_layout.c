#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc()

/*

char arr[] = "Hello";		// �迭�� �޸𸮸� ������ �ְ�, �ű⿡ ���ڰ� �����
char *str = "Hello";		// ���ڿ� Literal�� �ְ�, pointer�� ������ ��!
							// ���ڿ� Literal�� Read only segment (����) �� �־�.

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


	// compiler�� ������ literal�� �ϳ��� ����!
	// array�� ���� �ڽ��� �޸𸮿� ����!



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

	copy = str1;			// �ּҸ� �����ϴ� ��! �ؽ�Ʈ�� ��ġ�� ����.


	printf("%s %p %p\n", str1, str1, &str1);
	printf("%s %p %p\n", copy, copy, &copy);
	
	// strcpy(), strncpy()
	
	return 0;

	
}