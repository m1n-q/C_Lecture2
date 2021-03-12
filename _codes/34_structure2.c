#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 41

struct person	// tag
{
	/* members */
	char name[MAX];
	int age;
	float height;

	// member 선언은 메모리를 갖지 않는다
};

int main()
{	
	int flag;

	struct person prince;

	strcpy(prince.name, "Minkyu");
	//strncpy(prince.name, "Minkyu", MAX);

	prince.age = 26;


	// member operator (.) has higher precedence than &
	
	flag = scanf("%f", &prince.height);		// == &(prince.height)
	printf("%f\n", prince.height);

	
	
	/* Initialization */
	struct person princess = {
		"Minju",
		25,
		170.0f 
	};


	/* Initialization 2 */
	strcpy(princess.name, "Minju");
	princess.age = 25;
	princess.height = 170.0f;



	/* Designated Initialization */
	struct person king = {
		
		.name = "ramen king",
		.age = 50,
		
		120.0f
	};

	printf("%s %d %f \n", king.name, king.age, king.height);
	/* pointer to structure variable */

	struct person* someone;
	
	someone = &prince;
	//someone = (struct person*)malloc(sizeof(struct person));

	

	/*	
		Indirect member operator 
		(structure pointer operator) 

		struct  :  ' .' 으로 member 접근
		pointer :  '->' 으로 member 접근 (indirection & member)
				   == (* ptr ).member
	*/

	someone->age = 1001;
	printf("%s %d\n", someone->name, (*someone).age);




	/* Structure declaration in a function */
	
	// in main()
	struct book
	{
		char title[MAX];
		float price;
	};



	/* No tag */

	struct {
		int height;
		int width;
	} square1, square2;


	square1.height = 5;
	square2.width = 6;

	
	/* 
		typedef and structure 
		- 자료형처럼 사용
	*/

	typedef struct person newface;
	
	newface queen;				

	typedef struct person person;

	person p4;		// == struct person p4;


	typedef struct {
		char name[MAX];
		char place[MAX];
		float rating;
	} restaurant;

	restaurant menji;


	return 0;

}