#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>




int main(int argc, char* argv[])	
{	
	/* 
		string to integer, double, long
				   atoi(), atof(), atol()
		
		 converts base 10 only
	*/
	
	//if (argc < 3)
	//	printf("Wrong Usage of %s\n", argv[0]);	// [0] : exe �̸�

	//else
	//{
	//	/* Example 1 */
	//	/* 
	//		input : num, string
	//				 ��> argc �� �ƴϱ� argv[1]��!
	//				 ��> input �� ���ڰ� �ƴ� ���ڷ� �޴� ��.
	//	*/


	//	//int times = atoi(argv[1]);			// ���ڷ� ���� num�� ���������� ��ȯ		

	//	//for (int i = 0; i < times; i++)
	//	//	puts(argv[2]);


	//	/* Example 2 */

	//	printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));

	//}
	//
	//

	/*
		string to long, unsigned long, double
				strtol(), strtoul(), strtod()


		strtol(), strtoul() converts multi-base
		strtod() converts base 10 only
	*/

	char str1[] = "1024Hello";		

	char* end = 1;
	long l = strtol(str1, &end, 10); // ���� �ȵǴ� �κ��� end��
	printf("%s %ld %s %d\n", str1, l, end, (int)*end);

	
	
	char str2[] = "10FFHello";	
	l = strtol(str2, &end, 16);		// 16���� : FF�� ���ڷ�!	
	printf("%s %ld %s %d\n", str2, l, end, (int)*end);


	
	
	
	/*
		Numbers to strings 
		Use sprintf() instead of _itoa(), _ftoa()
	*/




	char temp[100];


	_itoa(10, temp, 16);	// 10 �� 16���� ���� �ٲ㼭 temp��
	puts(temp);

	sprintf(temp, "%x", 10);
	puts(temp);

	return 0;

}