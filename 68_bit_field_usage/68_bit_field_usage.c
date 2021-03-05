#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>		// CHAR_BIT
#include <stdbool.h>


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


	//for (int i = 0; i < bytes; ++i)
	//	char_to_binary(data[bytes - 1 - i]);
	//printf("\n");
}
int main()
{
	struct items
	{
		bool has_sword		: 1;	// number means bits to use
		bool has_shield		: 1;
		bool has_potion		: 1;
		bool has_guntlet	: 1;
		bool has_hammer		: 1;
		bool has_key		: 1;
		bool has_ring		: 1;
		bool has_amulet		: 1;	// bool : �ؼ��� bool�� �� ��

	} items_flag;

	items_flag.has_sword	= 1;	// flags = flags | MASK_SWORD;
	items_flag.has_shield	= 1;
	items_flag.has_potion	= 0;
	items_flag.has_guntlet	= 1;
	items_flag.has_hammer   = 0;
	items_flag.has_key		= 0;
	items_flag.has_ring		= 0;
	items_flag.has_amulet	= 0;

	print_binary("abc",3);

	printf("SIZE = %zd BYTE\n", sizeof(items_flag));
	print_binary((char*)&items_flag, sizeof(items_flag));

	if (items_flag.has_key == 1)	// if ((flags & MASK_KEY) == MASK_KEY)
		printf(">> You Can Enter.\n");


	
	union {
		struct items bf;	// ����ü�� ��Ʈ�ʵ�� �����ϱ�
		unsigned char uc;	// ��Ʈ���� �������� �����ϱ�
	} uni_flag;

	uni_flag.uc = 0;
	uni_flag.bf.has_amulet = true;
	uni_flag.uc |= (1 << 4);
	print_binary((char*)&uni_flag, sizeof(uni_flag));
	
	uni_flag.bf.has_hammer = false;
	print_binary((char*)&uni_flag, sizeof(uni_flag));

	/*
		KNK DOS example
	*/

	struct file_time {
		unsigned int seconds : 5;	// 2^5 = 32, (0 ~ 29) * (2 seconds)
		unsigned int minutes : 6;	// 2^6 = 64, (0 ~ 59) minutes
		unsigned int hours	 : 5;	// 2^5 = 32, (0 ~ 23) hours
	};


	struct file_date {
		unsigned int day	: 5;	// 2^5 = 32,  0 ~ 31
		unsigned int month	: 4;	// 2^4 = 16,  1 ~ 12
		unsigned int year	: 7;	// 2^7 = 128, 1980 ~
	} fd;

	/* 1988 12 28 */
	fd.day = 28;		// try overflow (32), try signed int
	fd.month = 12;
	fd.year = 8;

	printf("Day %u, Month %u, Year %u\n", fd.day, fd.month, fd.year);
	//scanf("%d", &fd.day);	/* WRONG */

	return 0;

}