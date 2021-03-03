#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define LEN 101

struct book
{
	char name[LEN];
	char author[LEN];
};

void print_books(const struct book books[], int n);
//void print_books(const struct book *books, int n)

int main()
{	
	struct book my_books[3];	
	//struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
	my_books[0] = (struct book){ "Momo", "MIN" };
	my_books[1] = (struct book){ "The Odyssey", "Homer" };
	my_books[2] = (struct book){ "Holmes", "Conan doil" };

	print_books(my_books, 3);
	


	return 0;

}

void print_books(const struct book books[], int n)
//void print_books(const struct book *books, int n)
{
	for (int i = 0; i < n; i++)
		//printf("\"%s\" written by %s\n", (books+i)->name, (books+i)->author);
		printf("\"%s\" written by %s\n", books[i].name, (*(books + i)).author);

	

		// books[i].name
		// (books+i)->name
		// (*(books+i)).name

}