#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TEST "String from define"



/*
	TODO: puts() w/o new line.
	Use pointer, putchar()
*/
void custom_put(const char* str);		// 두 줄 구현!
int custom_put2(const char* str);		// Add \n, return # of char

int main()
{	
	/*
		puts() : add \n
	*/



	//char str[60] = "String Array";
	//const char* ptr = "A Pointer";

	//puts("String without \\n");
	//puts("END");
	//puts(TEST);
	//puts(TEST + 5);


	//puts(&str[3]);
	////puts(str[3]);	//error

	//puts(ptr);
	//puts(ptr + 3);



	/*
		string without \0
	*/

		
	//char test[] = { 'H', 'i' };
	//puts(test);		// \0을 만날때까지 출력!

	

	/*
		puts() and fputs()
	*/


	//char line[10];
	
	
	//while (gets(line))		//while (gets(line) != NULL)
	//	puts(line);


	//while (fgets(line, 10, stdin))	// 최대 입력개수 : runtime error 방지
	//	fputs(line, stdout);
	//								// does NOT remove \0, \n								



	/*
		printf()
	*/
	//char input[100] = "";

	//int ret = scanf("%10s", input);		// Just do it
	//printf("%s\n", input);				// Just
	//ret = scanf("%10s", input);			// remaning buffer
	//printf("%s\n", input);				// do

	
	// scanf() : 여러가지 자료형 입력받을 때 편리. but 한 단어..
	//		     %10s로 강제해도 빈칸에서 멈춤.






	/* custom output */

	custom_put("Just do it");

	printf("%d\n",custom_put2("12345"));





	return 0;


}
void custom_put(const char* str)		// 두 줄 구현!
{
	while (*str != '\0')
		putchar(*str++);
}

	

int custom_put2(const char* str)		// Add \n, return # of char
{
	unsigned count = 0;
	while (*str != '\0')
	{
		putchar(*str++);
		count++;
	}
	putchar('\n');
	return count;

}


