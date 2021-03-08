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
		pointer member�� �Է¹ޱ�.

		Dangerous usage
	*/

	//struct namect p = { "Minkyu", "Shin" };		// text segment
	//// poitner�� "Minkyu", "Shin" ����� ù�ּҸ� ����Ű�� ��
	//
	//printf("%s %s\n", p.fname, p.lname);

	////int f1 = scanf("%[^\n]%*c", p.lname);	// scanf : �ش� �ּҿ� �Է¹��� ���� ����      (p.lname�� ����Ű�� �ּ�)
	//										// p.lname = "Shin"�� �ּ�, Error!!!!!!	(Read only)

	
	/*
		pointer member�� �Է¹ޱ�.
	 
		Recommended usage
		
		1. �Է°� �ӽ� ����
		2. ������ �����Ҵ�
		3. �Ҵ���� ������ �Է°� ����

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