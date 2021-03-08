#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct names
{
	char first[20];
	char last[20];
};

struct person
{	
	int id;
	struct names name;	// nested structure
};

struct person2
{
	int id;
	struct { char first[20]; char last[20]; };	// anonymous structure
												// no tag
};						

int main()
{	
	/* nested structure */

	struct person ted = { 123, {"Bill", "Gates"} };
	struct person ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted3.name.first);	// 이중으로 접근



	/* anonymous structure */

	struct person2 ted2 = { 124, {"Steve", "wozniak"} };
	//struct person2 ted2 = { 124, "Steve", "wozniak" };	// also works
	
	puts(ted2.first);	// 직접 접근 가능 

	return 0;

}