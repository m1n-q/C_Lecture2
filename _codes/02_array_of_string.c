#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()
{	
	const char* mythings[5] = {
	"Apple",
	"Banana",
	"Cocktail",
	"Dance",
	"Ear"
	};
	// char Ÿ�� �������� �迭


	char yourthings[5][40] = {
	"Studying",
	"Ramen",
	"Pizza",
	"Chicken",
	"Keyboard"
	};
	// 40�� �迭 5�� (2����)

	const char* str1 = "Apple";
	const char* str2 = "Studying";

	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)str1);		// ������ : ���ͷ� ����
	printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)str2);	// �迭 : ������ ����Ǿ� ����� ��.
	printf("\n");

	printf("%zd, %zd\n", sizeof(mythings), sizeof(yourthings));




	for (int i = 0; i < 200; i++)
		printf("%c", yourthings[0][i]);		// size = 200

	// Not a good idea
	

	
	
	return 0;

}
