#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

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

	fp = fopen("30_input.txt", "r");

	ch = fgetc(fp);
	fputc(ch, stdout);

	ungetc(ch, fp);			// ch�� stream �� �־����.
	long cur = ftell(fp);
	printf("%ld\n", cur);	// cursor�� �ٽ� ���ڸ���.


	ch = fgetc(fp);
	fputc(ch, stdout);

	fclose(fp);
	
	{
		/*char k;
		ungetc('A', stdin);
		scanf("%c", &k);
		printf("%c", k);*/
	}



	/* setvbuf() */
	
	//fp = fopen("30_input.txt", "r");

	//char buffer[32] = { '\0', };
	//

	//setvbuf(fp, buffer, _IOLBF, sizeof(buffer));	// _IOLBF, _IOFBF, _IONBF
	//												//  Line    Full    No

	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%hhd", buffer[i]);
	//printf("\n");



	//ch = fgetc(fp);		// �� ���ڸ� �о���. 
	//					// �ٵ� �ؿ� ���۰� �����ֳ�?
	//					// ���۸� ���� ä���, �� ���ۿ��� �ѱ��ڸ� �����°�!
	//

	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%c", buffer[i]);
	//printf("\n");


	//fclose(fp);


	/* fflush() */


	// Writing a large amount of data
	// fflush(fp);		// buffer�� ����������� !


	return 0;

}