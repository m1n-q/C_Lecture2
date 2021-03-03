#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 81

struct namect
{
	char* fname;	// Use malloc()
	char* lname;	// Use malloc()
	int letters;
};

void getinfo(struct namect*);		// allocate
void makeinfo(struct namect*);
void showinfo(struct namect*);
void cleanup(struct namect*);		// free()


int main()
{	
	/*
		pointer member에 입력받기.

		Dangerous usage
	*/

	//struct namect p = { "Minkyu", "Shin" };		// text segment
	//// poitner가 "Minkyu", "Shin" 상수의 첫주소를 가리키는 중
	//
	//printf("%s %s\n", p.fname, p.lname);

	////int f1 = scanf("%[^\n]%*c", p.lname);	// scanf : 해당 주소에 입력받은 값을 저장      (p.lname이 가리키는 주소)
	//										// p.lname = "Shin"의 주소, Error!!!!!!	(Read only)

	
	/*
		pointer member에 입력받기.
	 
		Recommended usage
		
		1. 입력값 임시 저장
		2. 포인터 동적할당
		3. 할당받은 공간에 입력값 복사

	*/

	//char temp[LEN] = { 0, };
	//int f2 = scanf("%[^\n]%*c", temp);		// ret flag?
	//p.fname = (char*)malloc(strlen(temp) + 1);	// + null character
	//if (p.fname != NULL)
	//	strcpy(p.fname, temp);
	//printf("%s %s\n", p.fname, p.lname);


	/* Problem */


	//struct namect person = { "ORIGIN", "BASE", };		// if initialized ?
	struct namect person;
	
	


	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);


	return 0;

}


void getinfo(struct namect* st_ptr)
{
	char temp[LEN] = { 0, };

	printf("Input first name.\n>>");
	//scanf("%[^\n]%*c", st_ptr->fname);		// if initialized ?
	
	scanf("%[^\n]%*c", temp);					// ret flag?
	st_ptr->fname = (char*)malloc(strlen(temp) + 1);
	if (st_ptr->fname != NULL)
		strcpy(st_ptr->fname, temp);



	printf("Input last name.\n>>");
	//scanf("%[^\n]%*c", st_ptr->lname);		// if initialized ?

	scanf("%[^\n]%*c", temp);
	st_ptr->lname = (char*)malloc(strlen(temp) + 1);
	if (st_ptr->lname != NULL)
		strcpy(st_ptr->lname, temp);

}
void makeinfo(struct namect* st_ptr)
{
	st_ptr->letters = strlen(st_ptr->fname) + strlen(st_ptr->lname);
}
void showinfo(struct namect* st_ptr)
{
	printf("Hi, %s %s. Your name has %d characters.\n",
		st_ptr->fname, st_ptr->lname , st_ptr->letters);
	
}
void cleanup(struct namect* st_ptr)
{
	free(st_ptr->fname);
	free(st_ptr->lname);
}