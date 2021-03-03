#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define STRLEN 81





/* 
	scanf()
	gets()
	gets_s()
	fgets()
 */




int main()
{
	/* Creating Spcae */

	//char* name = "";	// runtime error

	//char name[128];
	//int result = scanf("%s", name);
	//int c;
	//while ((c = getchar()) != '\n');

	
	
	/*
		scanf() vs gets()
		scanf() reads one word
		gets() reads one line and remove \n, \0
	*/

	
	
	//char words[STRLEN] = ""; 
	//gets(words);		     // parmeter : pointer!

	////gets_s(words, sizeof(words));

	//	
	//printf("%s", words);			// no \n
	//puts(words);					// adds \n
	//printf("END");


	//TODO: try STRLEN -> 5
	//gets() start with pointer. No idea when string ends. -> runtime error
	//gets_s()?

	// 안잘라줌 ?




	/* fgets() and fputs() */
	// 알아서 잘라줌 ?


	char words[STRLEN] = "";
	//TODO: try STRLEN -> 5
	//fgets(words, STRLEN, stdin);	// does NOT remove \n

	////TODO: \n to \0
	////for (int i = 0; i < STRLEN; i++)
	////{
	////	if (words[i] == '\n') 
	////	{
	////		words[i] = '\0';
	////		break;
	////	}
	////}


	//fputs(words, stdout);			// does NOT add \n
	//fputs("END", stdout);
	


	/* small array */

	//char small_array[5];
	//puts("ENTER LONG STRING : ");
	//fgets(small_array, 5, stdin);	
	//fputs(small_array, stdout);

	
	/* return of fgets */

	// 정상 입력 : 포인터 인자 그대로 반환
	// EOF : \0 반환


	/* Repeating short reading */

	//char small_array[5];
	//puts("ENTER LONG STRING : ");
	//while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
	//	fputs(small_array, stdout);	
	//	//puts(small_array);
	//// buffer에서 받아오는 특성 이용!



	/* scanf() */

	char str1[6], str2[6];

	//int count = scanf("%5s %5s", str1, str2);	// %5s : 5개만 입력받도록 제한!
	//int count = scanf("%6s %6s", str1, str2);	// runtime error
	//int count = scanf_s("%s %s", str1, 6, str2, 6);	// size
	printf("%s|%s \n", str1, str2);

	return 0;

}