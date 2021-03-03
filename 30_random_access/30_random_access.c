#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
/*
	ABCDEF . . .

	Current position 0 -> read A and move position 1 
	Current position 1 -> read B and move position 2 

*/

/*
		ftell() :
			�� cursor��ġ, ���������κ��� �� bytes?


		fseek(fp, 2L, SEEK_SET) :
			SEEK_SET(������) ���κ���
			2L(bytes) ��ŭ ������ ������ cursor �̵�


		SEEK_CUR : 
			current cursor����

		SEEK_END : 
			������ �� �ں���
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
	fsetpos(fp, &pt);		// 10 ��ġ�� cursor �̵�
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	fgetpos(fp, &pt);		// ftell()
	printf("%lld\n", pt);




	fclose(fp);
	
	
	
	
	
	
	
	
	return 0;

}