#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()
{	
	// make a test binary file

	{
		FILE* fp = fopen("binary_random", "wb");
		for (int i = 0; i < 100; ++i)
		{
			double d = i * 1.11;
			fwrite(&d, sizeof(double), 1, fp);
		}
		fclose(fp);
	}

	// read

	FILE* fp = fopen("binary_random", "rb");
	long cur;
	double d;

	cur = ftell(fp);
	printf("Cursor before reading : %ld\n", cur);

	fread(&d, sizeof(double), 1, fp);
	printf("read : %f\n", d);	
	
	
	cur = ftell(fp);		// 8bytes moved
	printf("Cursor after reading : %ld\n", cur);	


	fread(&d, sizeof(double), 1, fp);
	printf("read : %f\n", d); 
	
	cur = ftell(fp);		// 8bytes moved
	printf("Cursor after reading : %ld\n", cur);

	
	fseek(fp, 32L, SEEK_SET);

	fread(&d, sizeof(double), 1, fp);
	printf("read : %f\n", d);
	cur = ftell(fp);		// 8bytes moved
	printf("Cursor after reading : %ld\n", cur);
	return 0;

}