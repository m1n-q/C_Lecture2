#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>


/*
	fopen() mode for binary IO
	- rb, wb, ab,
	- ab+, a+b
	- wb+, w+b
	- ab+, a+b

	'..x' : if file exist, fail, no overwriting.
	- wx, wbx ...
*/

/*
		BINARY					TEXT

		fwrite()		|		fputs(), fprintf()
		fread()			|		fgets(), fscanf()

*/

int main()
{	

	// Writing Example
	{
		// FILE* fp = fopen("binary_file", "ab");	// writing binary

		// double d = 1.0 / 3.0;
		// int n = 123;
		// int* parr = (int*)malloc(sizeof(int) * n);
		// if (!parr) exit(1);
		// for (int n = 0; n < 123; ++n)
		// 	*(parr + n) = n * 2;


		// // (pointer, ������, ����) �� �Ѱ���!

		// fwrite(&d, sizeof(d), 1, fp);	// 8
		// fwrite(&n, sizeof(n), 1, fp);	// 4
		// fwrite(parr, sizeof(int), n, fp);	// 123 * 4


		// fclose(fp);
		// free(parr);

		// Total file size ?  
	}
	
	// Reading example
	{
		/* binary file�� type�� �˰� �־�� �ص� */

		

		FILE* fp = fopen("binary_file", "rb");
		double d;
		int n = 0;
		
		
		fread(&d, sizeof(d), 1, fp);		// �о���� ���� return
		fread(&n, sizeof(n), 1, fp);

		printf("%f\n", d);
		printf("%d\n", n);


		int* parr = (int*)malloc(sizeof(int) * n);	// �о���� n�� ���缭!
		if (!parr) exit(1);

		fread(parr, sizeof(int), n, fp);	// �о���� n�� ���缭!

				
		for (int i = 0; i < n; ++i)
			printf("%d ", *(parr + i));
		printf("\n");

		
		
		// // feof() : EOF�� �����°�?
		// printf("feof = %d\n", feof(fp));	// return 0 : �� �°� read �����Ƿ� !
		// fread(&n, sizeof(n), 1, fp);		// to make EOF : �ϳ� �� read
		// printf("feof = %d\n", feof(fp));	// return 1 : EOF ����
		
		
		// // ferror() : error�� �߻��ߴ°�?
		// printf("ferror = %d\n", ferror(fp));	// return 0 : no error
		// fwrite(&n, sizeof(n), 1, fp);			// to make error
		// printf("ferror = %d\n", ferror(fp));	// return 1 : error �߻�

		

	}


	return 0;

}