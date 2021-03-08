#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

//TODO: sort by height

struct kid
{
	char name[100];
	int height;

};

int compare(const void* fir, const void* sec)
{	
	if (((struct kid*)fir)->height > ((struct kid*)sec)->height)
		return 1;
	if (((struct kid*)fir)->height < ((struct kid*)sec)->height)
		return -1;
	else
		return 0;


}



int main()
{
	struct kid my_friends[] = {
		{"Jack Jack", 40 },
		{"Geenie", 300},
		{"Aladdin", 170},
		{"Piona", 150} 
	};

	const int n = sizeof(my_friends) / sizeof(struct kid);
	
	qsort(my_friends, n, sizeof(struct kid), compare);


	for (int i = 0; i < n; i++)
		printf("%-15s\t%d\n", my_friends[i].name,my_friends[i].height);
	return 0;

	

}