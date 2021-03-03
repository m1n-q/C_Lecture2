#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

unsigned char to_decimal(const char bi[]);

int main()
{	
	printf("Binary (string) to Decimal conversion\n");
	
	printf("%d\n", to_decimal("00000110"));
	printf("%d\n", to_decimal("00010110"));

	printf("%d\n", to_decimal("10010100"));
	return 0;

}

unsigned char to_decimal(const char bi[])
{
	size_t n = strlen(bi);
	unsigned char ret = 0;
	for (size_t i = 0; i < n; i++)
	{
		//ret += pow(2, atoi(bi[i]));
		if (bi[i] == '0')
			;
		else if (bi[i] == '1')
			ret += (int)pow(2, n-1 - i);

		/*if (bi[i] == '1')
			ret += (int)pow(2, n - 1 - i);
		else if (bi[i] != '0') {
			printf("Wrong character : %c", bi[i]);
			exit(1);
		}*/
			
	}
	return ret;
}