#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdbool.h>

struct 
{
	bool has_sword		: 1;	// member가 사용할 bit 개수
	bool has_shield		: 1;
	bool has_potion		: 1;
	bool has_guntlet	: 1;
	bool has_hammer		: 1;
	bool has_key		: 1;
	bool has_ring		: 1;
	bool has_amulet		: 1;

} items_flag;

int main()
{	
	items_flag.has_sword = 1;
	sizeof(items_flag);
	// flags = flags | MASK_SWORD;


	return 0;

}