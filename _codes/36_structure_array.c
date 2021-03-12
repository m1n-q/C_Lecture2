#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSG1 "Input a book title or press [enter] to stop.\n>>"
#define MSGA "Input the autor.\n>>"
#define MSGP "Input the price.\n>>"
#define MAX	50
#define CAP	10

typedef struct 
{
	char title[MAX];
	char author[MAX];
	float price;
} Book;

char* gets_nonl(char*, int, FILE *);

int main()
{	
	Book booklist[CAP];
	unsigned bcnt = 0;


	for (int i = 0; i < CAP; i++)
	{
		printf(MSG1);
		gets_nonl(booklist[i].title, MAX, stdin);
		
		if (booklist[i].title[0] == '\0')	break;
		
		
		printf(MSGA);
		gets_nonl(booklist[i].author, MAX, stdin);
		
		
		printf(MSGP);
		scanf("%f", &booklist[i].price);
		
		while (getchar() != '\n');	/* clear '\n'  */
		
		bcnt++;
	}
	

	if (bcnt) printf("\nThe list of books:\n");
	else printf("\nNO INPUTS\n");
		
	

	for (int i = 0; i < bcnt; i++)
	{
		printf("\"%s\" written by %s : $%.1f\n",
			booklist[i].title, booklist[i].author, booklist[i].price);
	}
	

	// ret ? 
	// printf("%p\n","abc");
	// printf("%p\n",booklist[0].author);
	// printf("%p\n",gets_nonl(booklist[0].author,MAX,stdin));

	return 0;

}

char* gets_nonl(char* _Buffer, int _Maxcount, FILE* _Stream)
{
	char* ret = fgets(_Buffer, _Maxcount, _Stream);
	int i= 0;
	while (1)
	{
		if (*(_Buffer + i) == '\n')
		{
			*(_Buffer + i) = '\0';
			break;
		}
		i++;
	}
	
	/*char* find;
	if (ret)
	{
		find = strchr(_Buffer, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n');
	}*/


	return ret;
}