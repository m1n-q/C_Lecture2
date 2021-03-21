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
		bit-field struct member의 자료형 ?
		1. 어떤 자료형처럼 해석될지
		2. bit-field의 크기 결정시 작용  (사용은 배정받은 bits 만큼만, 나머지는 padding!)
	*/



	struct {
		bool option1 : 1;
		//bool		 : 0;		// 강제로 메모리 요구
		//unsigned long long : 0;
		bool option2 : 1;
		unsigned long long option3 : 1;	// try lager bits
	} bbf;



	/* padding 과 bit-field 확인하기 */

	memset((char*)&bbf, 0xff, sizeof(bbf));		// bbf에 해당하는 메모리를 전부 11111111로 초기화
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
		//unsigned int		 : 0;		// 자료형만큼 size 늘어남
		unsigned int option2 : 1;
		
	} uibf;

	printf("%zu bytes\n", sizeof(uibf));	//  1bit + 1bit = ?	
											//  unsigned int



	return 0;

}