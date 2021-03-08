#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>	// SetConsoleOutputCP()

/*

	콘솔에서는 깨져도 사본.txt 에는 제대로 저장 ?
	
	- 결국 file은 binary 형태로 저장
	- 콘솔 출력 decoding 방식이 잘못된 것 (ANSI)
	- binary 값은 그대로니까 
	- UTF-8 인코딩된 txt에서는 정상!

*/
int main()
{	
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);


	int  ch;
	FILE* fr, * fw;

	const char* in_filename = "원본.txt";
	const char* out_filename = "사본.txt";

	unsigned long count = 0;


	if ((fr = fopen(in_filename, "r")) == NULL)
	{
		printf("Can't open file %s\n", in_filename);
		exit(EXIT_FAILURE);
	}

	if ((fw = fopen(out_filename, "w")) == NULL)
	{
		printf("Can't open file %s\n", out_filename);
		exit(EXIT_FAILURE);
	}
	

	SetConsoleOutputCP(CP_UTF8);	// console 출력시 utf-8로 변경

	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);
		fputc(ch, fw);
		count++;
	}
	printf("\n");
	fclose(fr);
	fclose(fw);



	/* 
		UTF - 8 일 때, console 말고
		프로그램 안의 한글이 깨짐 !
	*/
	SetConsoleOutputCP(default_cp);	// ISO 2022 KOREAN

	printf("FILE %s has %lu character\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("한글 출력 확인");


	return 0;

}