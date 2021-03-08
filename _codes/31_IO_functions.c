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

	ungetc(ch, fp);			// ch를 stream 에 넣어버림.
	long cur = ftell(fp);
	printf("%ld\n", cur);	// cursor도 다시 제자리로.


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



	//ch = fgetc(fp);		// 한 글자만 읽었음. 
	//					// 근데 밑에 버퍼가 꽉차있네?
	//					// 버퍼를 먼저 채우고, 그 버퍼에서 한글자만 가져온것!
	//

	//// dump buffer
	//for (int i = 0; i < sizeof(buffer); ++i)
	//	printf("%c", buffer[i]);
	//printf("\n");


	//fclose(fp);


	/* fflush() */


	// Writing a large amount of data
	// fflush(fp);		// buffer가 비워질때까지 !


	return 0;

}