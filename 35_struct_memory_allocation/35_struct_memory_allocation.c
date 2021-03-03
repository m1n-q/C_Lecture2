#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


/* property - struct member alignment - default */

int main()
{	
	/*
		Well alligned structure
	*/

	struct Aligned
	{
		int a;
		float b;
		double c;
	};

	/*
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
		| int a |float b|       double c	|

		4 + 4 + 8 = 16
	*/

	struct Aligned a1, a2;

	printf("struct Alligned a1\n");
	printf("Size of %zd\n", sizeof(struct Aligned));
	printf("%lld\n", (long long)&a1);
	printf("%lld\n", (long long)&a1.a);
	printf("%lld\n", (long long)&a1.b);
	printf("%lld\n", (long long)&a1.c);

	printf("\nstruct Aligned a2\n");
	printf("Size of %zd\n", sizeof(a2));
	printf("%lld\n", (long long)&a2);
	printf("%lld\n", (long long)&a2.a);
	printf("%lld\n", (long long)&a2.b);
	printf("%lld\n", (long long)&a2.c);





	/* 
		padding (struct member alignment)    // 줄맞춤
		- 1 word : 4 bytes (x86), 8 bytes (x64)
			
			ㄴ memory와 cpu가 데이터를 주고받는 최소 단위 

	*/


	struct Padded1
	{
		char a;
		float b;
		double c;
	};

	/*	Without padding
	
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
		|a|float b|     double c   |  ? ? ?  |

		1 + 4 + 8 = 13

		4bytes 씩 주고 받을 때, float, double이 잘려서 오게 됨
	*/
	
	
	/*	With padding
	
		0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
		|char a |float b|      double c	    |

		4 + 4 + 8 = 16
	*/


	struct Padded1 p1;
	p1.a = 'A';
	p1.b = 10.0f;
	printf("\nstruct Alligned p1\n");
	printf("Size of %zd\n", sizeof(struct Padded1));
	printf("%lld\n", (long long)&p1);
	printf("%lld\n", (long long)&p1.a);
	printf("%lld\n", (long long)&p1.b);
	printf("%lld\n", (long long)&p1.c);







	struct Padded2
	{
		float a;
		double b;
		char c;
	};

	/*	Padded

	0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 |
	|float a        |       double b       |char c 	              |

	4 + 8 + 1 = 13
	
	8(float?) + 8 + 8(char?) = 24

	- double을 자르지 않기 위해, compiler가 float과 char를  padding

*/

	struct Padded2 p2;
	
	printf("\nstruct Alligned p2\n");
	printf("Size of %zd\n", sizeof(struct Padded2));
	printf("%lld\n", (long long)&p2);
	printf("%lld\n", (long long)&p2.a);
	printf("%lld\n", (long long)&p2.b);
	printf("%lld\n", (long long)&p2.c);

	




	struct Padded3
	{
		char a;
		double b;
		double c;
		
	};

	/*	Padded

	0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 |
	|char a         |       double b       |       double c       |

	
	8(float?) + 8 + 8 = 24
	
	*/

	struct Padded3 p3;

	printf("\nstruct Alligned p3\n");
	printf("Size of %zd\n", sizeof(struct Padded3));
	printf("%lld\n", (long long)&p3);
	printf("%lld\n", (long long)&p3.a);
	printf("%lld\n", (long long)&p3.b);
	printf("%lld\n", (long long)&p3.c);



	struct Person
	{
		char name[41];
		int age;
		float height;
	};

	

	struct Person mom;

	printf("\nstruct Person\n");
	printf("Size of %zd\n", sizeof(struct Person));
	printf("%lld\n", (long long)&mom);
	printf("%lld\n", (long long)&mom.name);
	printf("%lld\n", (long long)&mom.age);
	printf("%lld\n", (long long)&mom.height);	// 41 + 4 + 4 = 49?
												// 44 ( padded )
	

	struct Person f[4];		// structure array

	printf("\nSizeof a structure array %zd\n", sizeof(f));
	
	/*
	
	|f[0].name       |  f[0].age  | f[0].height |f[1].name       |  f[1].age  | f[1].height |
	
	*/


	
	return 0;







}