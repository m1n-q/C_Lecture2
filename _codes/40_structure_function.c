#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define LEN 30

struct name_count {
	char first[LEN];
	char last[LEN];
	int num;
	
};

/*
	구조체의 포인터를 이용한 예제!!!!
	포인터를 통해 함수 안에서 원본 변경하기!!

	40'1 과 비교
*/

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(struct name_count*);
char* s_gets(char* st, int n);

int main()
{	

	struct name_count yours;

	receive_input(&yours);
	count_characters(&yours);
	show_result(&yours);
	
	
	

	


	return 0;

}
/*
	scanf("%[^\n]%*c", );
	%[^\n] :  \n 을 만날때까지 문자열 scan	// ^ : cap operator
	%*c	   :   c 를 하나 무시

*/



// nc의 duration?


void receive_input(struct name_count* nc)		// nc points yours!
{
	printf("Input your first name:\n>> ");
	scanf("%[^\n]%*c", nc->first);
	//s_gets

	printf("Input your last name:\n>> ");
	scanf("%[^\n]%*c", nc->last);

	printf("%p\n", &nc);

}
void count_characters(struct name_count* nc)
{
	nc->num = strlen(nc->first) + strlen(nc->last);
	printf("%p\n", &nc);
}
void show_result(struct name_count* nc) 
{
	printf("Hi, %s %s. Your name has %d characters.\n",
		nc->first, nc->last, nc->num);
	printf("%p\n", &nc);
}
char* s_gets(char* st, int n)
{
	char* __cdecl ret = fgets(st, n, stdin);;
	char* find;
	if (ret)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		
		else 
			while (getchar() != '\n');
	}
	return ret;
}

