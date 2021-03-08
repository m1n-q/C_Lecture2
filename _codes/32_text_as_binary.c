#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>	

/*
	CR : 13
	LF : 10
*/


int main()
{	
	FILE* fp = fopen("31_text.txt", "rb");	// rb : read as binary

	unsigned char ch;

	SetConsoleOutputCP(CP_UTF8);

	/* fread() : binary */
	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)	// 읽어들인 개수 return
	{
		printf("%c", ch);
		//printf("%hhu %c\n",ch, ch);		// NOTE: 한글, 여러 바이트 조합?
	}

	fclose(fp);
	return 0;

}