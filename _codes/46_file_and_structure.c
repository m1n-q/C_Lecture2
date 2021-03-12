#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

#define LEN 101

struct book
{
    char title[LEN];
    char author[LEN];
};

void print_books(struct book* bookarr, int bookcnt) ;
void write_books(char * filename, struct book* bookarr, int bookcnt);


struct book* read_books(char* filename, int* bookcnt);
void read_books2(char* filename, struct book** barr_ptr, int* bookcnt);



int main()
{
    int bookcnt = 3;

    struct book* my_books = (struct book*)malloc(sizeof(struct book) * bookcnt);
    struct book* your_books = (struct book*)malloc(sizeof(struct book) * bookcnt);
    (*my_books) = (struct book) {"Momo","Minkyu"};
    *(my_books+1) = (struct book) {"Title","Author"};
    my_books[2] =(struct book) {"What","Whom"};
    print_books(my_books,bookcnt);

    write_books("TEST",my_books,bookcnt);
    int temp;

    if (scanf("%d",&temp) == 0) exit(1);

    // my_books = read_books("TEST",&bookcnt);
    read_books2("TEST",&my_books,&bookcnt);
    print_books(my_books,bookcnt);
    
  

    return 0;


    
// int ( n)

// void ( int *n) 

// struct book* ( struct book* )

// void ( struct book** )

}

void print_books(struct book* bookarr,int bookcnt)
{
    for (int i = 0; i<bookcnt; i++)
    {
        printf("Book %d : \"%s\" written by \"%s\"\n",  i+1,bookarr[i].title,(bookarr+i)->author);
    }

}

void write_books(char * filename, struct book* bookarr, int bookcnt)
{
    FILE* fw = fopen(filename, "w");
    if (fw == NULL) exit(1);

    fprintf(fw,"%d\n",bookcnt);

    for (int i = 0;i < bookcnt; i++)
    {
        fprintf(fw,"%s\n%s\n",bookarr[i].title,bookarr[i].author);
    }
    fclose(fw);
}

struct book* read_books(char* filename, int* bookcnt)
{
    FILE* fr = fopen(filename, "r");


    fscanf(fr,"%d%*c",bookcnt);
    struct book* ret_books = (struct book*)malloc(sizeof(struct book) *(* bookcnt));

    for (int i = 0; i < *bookcnt; i++)
    {
        fscanf(fr,"%s\n%s\n",ret_books[i].title, ret_books[i].author);
    }

    fclose(fr);
    return ret_books;
}

void read_books2(char* filename, struct book** barr_ptr, int* bookcnt)
{ 
    /* SOL 1 */

    FILE* fr = fopen(filename, "r");


    fscanf(fr,"%d%*c",bookcnt);
    struct book* ret_books = (struct book*)malloc(sizeof(struct book) *(* bookcnt));

    for (int i = 0; i < *bookcnt; i++)
    {
        fscanf(fr,"%s\n%s\n",ret_books[i].title, ret_books[i].author);
    }

    fclose(fr);

    // *barr_ptr = ret_books;		// *barr_ptr = my_books = struct book*
    // barr_ptr = &ret_books;   // same? 


    /* SOL 2 */
    
    // FILE* fr = fopen(filename, "r");


    // fscanf(fr,"%d%*c",bookcnt);
    

    // for (int i = 0; i < *bookcnt; i++)
    // {
    //     fscanf(fr,"%s\n%s\n",(*(*barr_ptr+i)).title, (*(*barr_ptr+i)).author);
    // }

    // fclose(fr);

    

}