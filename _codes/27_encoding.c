#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>	// SetConsoleOutputCP()

/*

	�ֿܼ����� ������ �纻.txt ���� ����� ���� ?
	
	- �ᱹ file�� binary ���·� ����
	- �ܼ� ��� decoding ����� �߸��� �� (ANSI)
	- binary ���� �״�δϱ� 
	- UTF-8 ���ڵ��� txt������ ����!

*/
int main()
{	
	const UINT default_cp = GetConsoleOutputCP();
	printf("%u\n", default_cp);


	int  ch;
	FILE* fr, * fw;

	const char* in_filename = "����.txt";
	const char* out_filename = "�纻.txt";

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
	

	SetConsoleOutputCP(CP_UTF8);	// console ��½� utf-8�� ����

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
		UTF - 8 �� ��, console ����
		���α׷� ���� �ѱ��� ���� !
	*/
	SetConsoleOutputCP(default_cp);	// ISO 2022 KOREAN

	printf("FILE %s has %lu character\n", in_filename, count);
	printf("Copied to %s\n", out_filename);

	printf("�ѱ� ��� Ȯ��");


	return 0;

}