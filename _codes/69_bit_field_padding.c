#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>

void char_to_binary(unsigned char uc)
{
	const int bits = CHAR_BIT * (sizeof(unsigned char));
	for (int i = bits - 1; i >= 0; i--)
	{
		printf("%d", (uc >> i) & 1);
	}
}

void print_binary(char* data, int bytes)	// extended for any sizes
{
	for (int i = 0; i < bytes; ++i)
		char_to_binary(data[i]);
	printf("\n");


	// for (int i = 0; i < bytes; ++i)
	// 	char_to_binary(data[bytes - 1 - i]);
	// printf("\n");
}


int main()
{	
	/*
		bit-field struct member�� �ڷ��� ?
		1. � �ڷ���ó�� �ؼ�����
		2. bit-field�� ũ�� ������ �ۿ�  (����� �������� bits ��ŭ��, �������� padding!)
	*/



	struct {
		bool option1 : 1;
		//bool		 : 0;		// ������ �޸� �䱸
		//unsigned long long : 0;
		bool option2 : 1;
		unsigned long long option3 : 1;	// try lager bits
	} bbf;



	/* padding �� bit-field Ȯ���ϱ� */

	memset((char*)&bbf, 0xff, sizeof(bbf));		// bbf�� �ش��ϴ� �޸𸮸� ���� 11111111�� �ʱ�ȭ
	print_binary((char*)&bbf, sizeof(bbf));
	bbf.option1 = 0;
	bbf.option2 = 0;
	bbf.option3 = 0;	// try larger integer
	print_binary((char*)&bbf, sizeof(bbf));


	printf("%lu bytes\n", sizeof(bbf));

	struct {
		unsigned short option1 : 8;
		unsigned short option2 : 7;
		//unsigned short		   : 0;
		unsigned short option3 : 1;
	} usbf;

	printf("%zu bytes\n", sizeof(usbf));		// unsigned short

	struct {
		unsigned int option1 : 1;
		//unsigned int		 : 0;		// �ڷ�����ŭ size �þ
		unsigned int option2 : 1;
		
	} uibf;

	printf("%zu bytes\n", sizeof(uibf));	//  1bit + 1bit = ?	
											//  unsigned int



	return 0;

}