#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Programming written in C

	Translating
	Preprocessing
	
	Compiling

	Linking

	Executable

*/





int main()
{	
	/*
		Translating phase
		
		-compiler�� compile �ϱ� ���� ������ �������ִ� ����
	*/

	/*
		International characters
		- �����Ϸ��� ������ �� �ֵ��� ����
	*/
	
	puts("�ȳ��ϼ���? �ѱ��Դϴ�.\n");

	/*
		Trigraph Secuences
		- Some keyboards don't provide all the symbols used in C.
		- Three-character sequences

		Trigraph		Replacement
		??=				#
		??/				\
		??'				^
		??(				[
		??)				]
		??!				|
		??<				{
		??>				}
		??-				~

		/Zc	: trigraphs

		"" ���� ���ڿ��� translate �ȴ�!
	*/

	int arr[3] = { 1,2,3 };
	// printf("arr??(0??) == %d\n", arr??(0??));
	//printf("arr[0] == %d\n", arr[0]);

	/*
		Digraphs
		- Two-character sequences

		Digraph			Equivalent
		<:				[
		:>				]
		<%				{
		%>				}
		%:				#

		"" ���� ���ڿ��� translate ���� �ʴ´�!
	*/

	printf("arr<:1:> == %d\n", arr<:1:>);

	/*
		Two physical lines vs One logical line 
		\ + enter
	*/
	
	printf("This is very very very very very very very very \
very very long long long long long long long long long long line.\n ");
	
	
	
	/*
		Tokens
		- Groups seperated from each other by spaces, tabs, or line breaks
		Whitespace characters -> a single space
	
		Token : ������ �׷�/ compile�� �⺻ ����
	*/
	
	int/*a variable to count a number*/n = 1;
	
	// �ּ��� ���� ��ĭ���� �����Ǿ� int n = 1;
	
	
	
	
	
	return 0;

}