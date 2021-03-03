#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


void my_strcat(char *str1, char *str2);

int main()
{	
	/*
		strcat() and strncat() : string concatenation
									�ڿ� ����!
	*/ 

	char str1[100] = "First string";
	char str2[] = "Second string";

	/*strcat(str1, ", ");
	strcat(str1, str2);*/
	//strncat(str1, str2, 2);		//	Append n character
	//my_strcat(str1, str2);
	//puts(str1);

	//TODO: implement my_strcat()!


	/*
		strcmp() and strncmp() : compare strings ( not characters )	

		return : ������ -> 0
				 �ٸ��� -> -1, 1 (ASCII ũ�� ����)
	*/


	printf("%d\n", strcmp("A", "A"));
	printf("%d\n", strcmp("A", "B"));
	printf("%d\n", strcmp("B", "A"));
	printf("%d\n", strcmp("Hello", "Hello"));
	printf("%d\n", strcmp("Hello", "HelloOO"));

	
	printf("%d\n", strncmp("Hello", "Hello12345",5));
	//TODO: implement strcmp

	/*
		strcpy() and strncpy() : not only POINTER !
	*/

	char dest[100] = "";		// make sure memory is enough
	char source[] = "Start programming";

	//dest = source;	// ERROR : �迭���� ���.
	//dest = "Start something";	// ERROR

	
	strncpy(dest, source, 5);		//'\0' is Not added
	puts(dest);
	strcpy(dest, source);
	puts(dest);
	strcpy(dest + 6, "coding!");	// ����� !
	puts(dest);

	
	strncpy(dest, "adddd", 5);		//'\0' is Not added
	puts(dest);

	/*
		sprintf() : printf�� ù ���ڷ�!
	*/

	char str[100] = "";
	int i = 123;
	sprintf(str, "%05d.png", i);
	puts(str);




	/* 
		more.......
	*/

	printf("%s\n", strchr("Hello, World", 'l'));		// ù��° 'l'�� ������ return
	printf("%s\n", strrchr("Hello, World", 'l'));		// reverse.

	printf("%s\n", strpbrk("Hello, World", "ABCDE"));	// 
	printf("%s\n", strpbrk("Hello, World", "abcde"));	// 'abcde' �� �ϳ��� �����ϴ� ������ return

	printf("%s\n", strstr("Hello, World", "wor"));
	printf("%s\n", strstr("Hello, World", "Wor"));		// Wor �� �����ϴ� ù��° ������.
	



	return 0;

}
void my_strcat(char *str1, char *str2)
{
	while (*str2 != '\0')
	{
		while (*str1 != '\0')
			str1++;
		*(str1++) = *str2++;
	}
	*str1 += *str2;
}
