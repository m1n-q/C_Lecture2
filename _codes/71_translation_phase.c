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
		
		-compiler가 compile 하기 편한 구조로 번역해주는 과정
	*/

	/*
		International characters
		- 컴파일러가 이해할 수 있도록 번역
	*/
	
	puts("안녕하세요? 한글입니다.\n");

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

		"" 안의 문자열도 translate 된다!
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

		"" 안의 문자열은 translate 하지 않는다!
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
	
		Token : 글자의 그룹/ compile의 기본 단위
	*/
	
	int/*a variable to count a number*/n = 1;
	
	// 주석이 공백 한칸으로 번역되어 int n = 1;
	
	
	
	
	
	return 0;

}