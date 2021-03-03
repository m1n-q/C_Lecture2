#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
	ABCDEF . . .

	Current position 0 -> read A and move position 1 
	Current position 1 -> read B and move position 2 

*/

/*
		ftell() :
			현 cursor위치, 시작점으로부터 몇 bytes?


		fseek(fp, 2L, SEEK_SET) :
			SEEK_SET(시작점) 으로부터
			2L(bytes) 만큼 떨어진 곳으로 cursor 이동


		SEEK_CUR : 
			current cursor부터

		SEEK_END : 
			파일의 맨 뒤부터
*/


int main()
{	
	int ch;
	long cur;

	FILE* fp = fopen("random.txt", "r");

	cur = ftell(fp);	
	printf("ftell() = %ld\n", cur);
		
	fseek(fp, 2L, SEEK_SET);	
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	ch = fgetc(fp);		// read and move cursor 1 byte
	printf("%d %c\n", ch, ch);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	
	ch = fgetc(fp);		// read and move cursor 1 byte
	printf("%d %c\n", ch, ch);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);


	fseek(fp, 0L, SEEK_END);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	
	ch = fgetc(fp);				// read and move cursor 1 byte
	printf("%d %c\n", ch, ch);	// EOF


	fseek(fp, -1L, SEEK_CUR);
	ch = fgetc(fp);				// read and move cursor 1 byte
	printf("%d %c\n", ch, ch);


	printf("\n");

	/*
		fsetpos() : seek
		fgetpos() : tell

		-> pointer parameter
		-> return 0
	*/

	fpos_t pt;
	pt = 10;	
	fsetpos(fp, &pt);		// 10 위치로 cursor 이동
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	fgetpos(fp, &pt);		// ftell()
	printf("%lld\n", pt);




	fclose(fp);
	
	
	
	
	
	
	
	
	return 0;

}