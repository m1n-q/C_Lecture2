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


		// // (pointer, 사이즈, 개수) 를 넘겨줌!

		// fwrite(&d, sizeof(d), 1, fp);	// 8
		// fwrite(&n, sizeof(n), 1, fp);	// 4
		// fwrite(parr, sizeof(int), n, fp);	// 123 * 4


		// fclose(fp);
		// free(parr);

		// Total file size ?  
	}
	
	// Reading example
	{
		/* binary file의 type을 알고 있어야 해독 */

		

		FILE* fp = fopen("binary_file", "rb");
		double d;
		int n = 0;
		
		
		fread(&d, sizeof(d), 1, fp);		// 읽어들인 개수 return
		fread(&n, sizeof(n), 1, fp);

		printf("%f\n", d);
		printf("%d\n", n);


		int* parr = (int*)malloc(sizeof(int) * n);	// 읽어들인 n에 맞춰서!
		if (!parr) exit(1);

		fread(parr, sizeof(int), n, fp);	// 읽어들인 n에 맞춰서!

				
		for (int i = 0; i < n; ++i)
			printf("%d ", *(parr + i));
		printf("\n");

		
		
		// // feof() : EOF를 만났는가?
		// printf("feof = %d\n", feof(fp));	// return 0 : 딱 맞게 read 했으므로 !
		// fread(&n, sizeof(n), 1, fp);		// to make EOF : 하나 더 read
		// printf("feof = %d\n", feof(fp));	// return 1 : EOF 만남
		
		
		// // ferror() : error가 발생했는가?
		// printf("ferror = %d\n", ferror(fp));	// return 0 : no error
		// fwrite(&n, sizeof(n), 1, fp);			// to make error
		// printf("ferror = %d\n", ferror(fp));	// return 1 : error 발생

		

	}


	return 0;

}