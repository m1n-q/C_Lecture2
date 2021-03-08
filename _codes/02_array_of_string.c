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
	// char 타입 포인터의 배열


	char yourthings[5][40] = {
	"Studying",
	"Ramen",
	"Pizza",
	"Chicken",
	"Keyboard"
	};
	// 40개 배열 5개 (2차원)

	const char* str1 = "Apple";
	const char* str2 = "Studying";

	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)str1);		// 포인터 : 리터럴 참조
	printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)str2);	// 배열 : 값들이 복사되어 저장된 것.
	printf("\n");

	printf("%zd, %zd\n", sizeof(mythings), sizeof(yourthings));




	for (int i = 0; i < 200; i++)
		printf("%c", yourthings[0][i]);		// size = 200

	// Not a good idea
	

	
	
	return 0;

}
