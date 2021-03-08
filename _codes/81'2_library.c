#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "../81_library/81_library.h"	// additional include directory


int main()
{	

	say_hello();
	say_world();		// Linking error!
						// - additional include directory
						// - additional dependencies

	return 0;

}