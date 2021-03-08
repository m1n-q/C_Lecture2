#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>	 // rand(), srand()	
#include <time.h>	 // time()

#include "my_rand.h"


/*
	rand()
	- 0 to RAND_MAX	( typically INT_MAX )

	srand()
	- random seed

*/


int main()
{	
	//srand(3);		// seed 에 따라 값이 고정됨
	//srand((unsigned)time(0));
	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d\n", rand());
	//}



	//unsigned int next = 2;			// seed
	////unsigned int next = (unsigned)time(0);
	//for (int i = 0; i < 10; ++i)
	//{
	//	next = next * 1103515245 + 1234;		// overflow 이용 !
	//	next = (unsigned)(next / 65536) % 32768;
	//	printf("%d\n", next);
	//}

	printf("\n");


	my_srand(2);
	for (int i = 0; i < 10; ++i)
		printf("%d\n", my_rand());




	return 0;

}
