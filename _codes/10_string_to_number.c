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
	//	printf("Wrong Usage of %s\n", argv[0]);	// [0] : exe 이름

	//else
	//{
	//	/* Example 1 */
	//	/* 
	//		input : num, string
	//				 ㄴ> argc 가 아니구 argv[1]임!
	//				 ㄴ> input 은 숫자가 아닌 문자로 받는 중.
	//	*/


	//	//int times = atoi(argv[1]);			// 문자로 받은 num을 정수형으로 변환		

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
	long l = strtol(str1, &end, 10); // 변경 안되는 부분은 end로
	printf("%s %ld %s %d\n", str1, l, end, (int)*end);

	
	
	char str2[] = "10FFHello";	
	l = strtol(str2, &end, 16);		// 16진수 : FF도 숫자로!	
	printf("%s %ld %s %d\n", str2, l, end, (int)*end);


	
	
	
	/*
		Numbers to strings 
		Use sprintf() instead of _itoa(), _ftoa()
	*/




	char temp[100];


	_itoa(10, temp, 16);	// 10 을 16진수 수로 바꿔서 temp로
	puts(temp);

	sprintf(temp, "%x", 10);
	puts(temp);

	return 0;

}