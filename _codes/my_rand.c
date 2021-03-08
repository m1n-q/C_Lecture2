static unsigned seed = 1;
#include "my_rand.h"

int my_rand()
{
	
	seed = seed * 1103515245 + 1234;
	seed = (unsigned)(seed / 65536) % 32768;

	return seed;
}
void my_srand(unsigned set_seed)
{
	seed = set_seed;

}