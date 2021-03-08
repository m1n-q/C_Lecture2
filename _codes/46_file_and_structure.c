#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define LEN 101

struct book
{
	char name[LEN];
	char author[LEN];
};

void print_books(const struct book* books, int n);
void write_books(const char* filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);




int main()
{

	struct book my_books[3];
	//struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
	my_books[0] = (struct book){ "Momo", "MIN" };
	my_books[1] = (struct book){ "The Odyssey", "Homer" };
	my_books[2] = (struct book){ "Holmes", "Conan doil" };

	int bookcnt = 3;
	print_books(my_books, bookcnt);
	write_books("NEWFILE.txt", my_books, bookcnt);
	//struct book* new_books = read_books("NEWFILE.txt", &bookcnt);

	struct book* newbooks;
	newbooks = (struct book*)malloc(sizeof(struct book) *(bookcnt));
	read_books2("NEWFILE.TXT", &newbooks, &bookcnt);


	return 0;

}


void print_books(const struct book *books, int n)
{
	for (int i = 0; i < n; i++)
		//printf("\"%s\" written by %s\n", (books+i)->name, (books+i)->author);
		printf("\"%s\" written by %s\n", books[i].name, (*(books + i)).author);



	// books[i].name
	// (books+i)->name
	// (*(books+i)).name

}

void write_books(const char* filename, const struct book* books, int n)
{
	FILE* fw;
	fw = fopen(filename, "w");

		
	printf("\nWriting FILE.\n");

	fprintf(fw, "%d", n);
	fputs("\n", fw);
	for (int i = 0; i < n; i++)
	{
		fputs((books+i)->name, fw);
		fputs("\n", fw);
		fputs((books+i)->author, fw);
		fputs("\n", fw);

	}
	fclose(fw);
	printf("DONE\n\n");
	

}

struct book* read_books(const char* filename, int* n)
{	


	printf("Press any key to read data from a file.\n");

	if (_getch()) printf("\n");
	else exit(1);
	
	FILE* fr;
	struct book* newbooks;
	
	fr = fopen(filename, "r");
	fscanf(fr, "%d\n", n);		//%d%*c

	newbooks = (struct book*)malloc(sizeof(struct book) * (*n));

	for (int i = 0; i < *n; i++)
	{
		fscanf(fr,"%[^\n]%*c", &((newbooks + i)->name));
		fscanf(fr, "%[^\n]%*c", &((newbooks + i)->author));
		printf("Book %d : \"%s\" written by \"%s\"\n",
			i + 1, (newbooks + i)->name, (newbooks + i)->author);
	}
	
	return newbooks;
	


}
void read_books2(const char* filename, struct book** books_dptr, int* n)
{

	printf("Press any key to read data from a file.\n");

	if (_getch()) printf("\n");
	else exit(1);

	FILE* fr;
	

	fr = fopen(filename, "r");
	fscanf(fr, "%d\n", n);

	
	char buffer[LEN];
	for (int i = 0; i < *n; i++)
	{

		fscanf(fr, "%[^\n]%*c", buffer);
		strcpy( ((*books_dptr)[i]).name, buffer);
		fscanf(fr, "%[^\n]%*c", buffer);
		strcpy( ((*books_dptr)[i]).author, buffer);
		printf("Book %d : \"%s\" written by \"%s\"\n",
			i + 1, ((*books_dptr)[i]).name, ((*books_dptr)[i]).author);
	}

}
