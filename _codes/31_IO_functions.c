#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

/*
	ungetc()
	setvbuf()
	fflush()
*/

int main()
{	
	FILE* fp;
	int ch;

	/* ungetc() */

	// fp = fopen("31_input", "a+");

	// if (fp == NULL) exit(1);

	// long cur = ftell(fp);
	// printf("%ld\n", cur );
	// fseek(fp, 0L, SEEK_SET);

	// ch = fgetc(fp);
	// fputc(ch, stdout);

	// ungetc(ch, fp);			// ch�� stream �� �־����.
	// cur = ftell(fp);
	// printf("%ld\n", cur);	// cursor�� �ٽ� ���ڸ���.


	// ch = fgetc(fp);
	// fputc(ch, stdout);
	// printf("\n");
	// fclose(fp);
	
	{
		/*char k;
		ungetc('A', stdin);
		scanf("%c", &k);
		printf("%c", k);*/
	}



	/* setvbuf() */
	
	fp = fopen("31_input", "r");

	char buffer[32] = { '\0', };
	

	setvbuf(fp, buffer, _IOLBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF
													//  Line    Full    No

	// dump buffer
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%hhd", buffer[i]);
	printf("\n");


	fseek(fp,0L,SEEK_SET);
	ch = fgetc(fp);		// �� ���ڸ� �о���. 
	//					// �ٵ� �ؿ� ���۰� �����ֳ�?
	//					// ���۸� ���� ä���, �� ���ۿ��� �ѱ��ڸ� �����°�!
	//

	// dump buffer
	for (int i = 0; i < sizeof(buffer); ++i)
		printf("%c", buffer[i]);
	printf("\n");

	printf("%c\n", ch);

	scanf("%c", &ch);



	fseek(fp,0L,SEEK_SET);
	
	
	ch = fgetc(fp);
	printf("%c\n", ch);




	fclose(fp);


	/* fflush() */


	// Writing a large amount of data
	// fflush(fp);		// buffer�� ����������� !


	return 0;

}