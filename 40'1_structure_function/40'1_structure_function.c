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
	����ü�� ����, ���縦 �̿��� ����!!!
	�Ķ���ͷ�, ������ �����ؿͼ�, 
	�Լ� �ȿ��� do sth �� ��,
	�װ� �ٽ� �������� ����!!!!

	-> ������ �� pointer member ����...... "��" ���翩�� pointer�� ���� �ּ��ڳ�..   
	-> ����ϱ� �޸� ���� �����ϰ���?
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