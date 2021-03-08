#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define LEN 30

struct name_count {
	char first[LEN];
	char last[LEN];
	int num;
	//int *arr;
};

/*
	구조체의 대입, 복사를 이용한 예제!!!
	파라미터로, 원본을 복사해와서, 
	함수 안에서 do sth 한 후,
	그걸 다시 원본으로 복사!!!!

	-> 복사할 땐 pointer member 조심...... "값" 복사여두 pointer의 값은 주소자나..   
	-> 복사니까 메모리 많이 차지하겠지?
*/


struct name_count receive_input();
struct name_count count_characters(struct name_count);
void show_result(const struct name_count);
char* s_gets(char* st, int n);


//void test(struct name_count);

int main()
{	
	struct name_count yours = { "Z","s", };
	//yours.arr = (int*)malloc(sizeof(int) * 2);

	yours = receive_input();
	yours = count_characters(yours);
	show_result(yours);

	/*yours.arr = (int*)malloc(sizeof(int) * 2);
	test(yours);*/

	


	return 0;

}

struct name_count receive_input()
{
	struct name_count nc;
	printf("Input your first name:\n>> ");
	scanf("%[^\n]%*c", &nc.first);


	printf("Input your last name:\n>> ");
	scanf("%[^\n]%*c", &nc.last);
	
	return nc;
}
struct name_count count_characters(struct name_count arg)
{
	arg.num = strlen(arg.first) + strlen(arg.last);
	return arg;
}
void show_result(const struct name_count nc)
{
	printf("Hi, %s %s. Your name has %d characters.\n",
		nc.first, nc.last, nc.num);
}





//void test(struct name_count tester)
//{
//	
//	tester.num = 12345;
// *tester.arr = 500;
//
//}