#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#define LEN 100

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);	//TODO: Add a new menu

int main()
{
	char options[] = { 'u','l','t' };
	void (*apf[])(char*) = { ToUpper, ToLower,Transpose };

	/*typedef int(*pf)(int);
	pf apf[] = { ToUpper,ToLower };*/

	unsigned n = sizeof(options);


	bool inoption = 0;
	char input[LEN];


	printf("Enter a string\n>> ");
	while (scanf("%[^\n]%*c", input) != 1)
	{
		printf("%s is wrong input, please try again\n>> ", input);
	}




	while (1)
	{
		unsigned op;
		printf("OPTIONS\nu) ToUpper\nl) ToLower\nt) Transpose\n >> ");
		char opsel;
		opsel = getc(stdin);
		while (getchar() != '\n');

		for (op = 0; op < n; op++)
		{

			if (opsel == options[op])
			{
				inoption = true;
				break;
			}

		}

		if (inoption)
		{
			/*update_string(input, apf[op]);*/
			apf[op](input);			// for문 안으로 ?
			printf(input);
			break;
		}
		else
			printf("%c is not in options, please try again.\n", opsel);
		inoption = false;
	}
}





void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = pf(*str);
		str++;
	}
}
void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}

}
void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else
			*str = tolower(*str);
		str++;
	}
}