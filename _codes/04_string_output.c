#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TEST "String from define"



/*
	TODO: puts() w/o new line.
	Use pointer, putchar()
*/
void custom_put(const char* str);		// �� �� ����!
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
	//puts(test);		// \0�� ���������� ���!

	

	/*
		puts() and fputs()
	*/


	//char line[10];
	
	
	//while (gets(line))		//while (gets(line) != NULL)
	//	puts(line);


	//while (fgets(line, 10, stdin))	// �ִ� �Է°��� : runtime error ����
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

	
	// scanf() : �������� �ڷ��� �Է¹��� �� ��. but �� �ܾ�..
	//		     %10s�� �����ص� ��ĭ���� ����.






	/* custom output */

	custom_put("Just do it");

	printf("%d\n",custom_put2("12345"));





	return 0;


}
void custom_put(const char* str)		// �� �� ����!
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


