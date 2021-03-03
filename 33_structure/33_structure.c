#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define	MAX_LEN 50
#define CAPA 100

/*
* 
	Patient
	- name (string)
	- height (cm)
	- weight (kg)

*/

int main()
{	
	/* Variables */
	
	char name1[MAX_LEN], name2[MAX_LEN], name3[MAX_LEN]; // ...
	float height1, height2, height3;	// ...
	float weight1, weight2, weight3;	// ...

	strcpy(name1, "John");
	height1 = 180.0f;
	weight1 = 70.0f;

	printf("%s %f %f\n", name1, height1, weight1);



	/* 
		Arrays 
		- '자료형이 같은' data objects
	*/

	char names[CAPA][MAX_LEN];
	float heights[CAPA];
	float weights[CAPA];

	strcpy(names[0], "John");
	heights[0] = 180.0f;
	weights[0] = 70.0f;

	printf("%s %f %f\n", names[0], heights[0], weights[0]);



	/*
		자료형이 다른 data objects를 묶을 수는 없을까?

		-> Structures
	*/

	struct Patient	// Tag
	{
		/* Members */
		char name[MAX_LEN];
		float height;
		float weight;
		int age;
		// ...


		// 각 member가 array처럼 일렬로 나열!
	};

	struct Patient p1;	// structure variable


	strcpy(p1.name, "John");	// . : member operater
	p1.height = 180.0f;
	p1.weight = 70.0f;		



	return 0;

}