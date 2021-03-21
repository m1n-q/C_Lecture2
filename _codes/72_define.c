#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Preprocesser directive begins with # symbol 
	at the beginning of a line. (전처리 지시자)
*/

/*
	Macro
	- An instruction that represents a sequence of instruvtions 
	  in abbreviated form. (여러개를 하나의 명령어로 축약)
*/

/*
#define			SAY_HELLO		printf("Hello, World!");

Preprocessor	Macro (name)	body (or replacement list)
directive



Macro expansion : Macro -> body

compiler는 Macro name을 볼 수 없다.
*/

/*
	Object-like macros vs Function-like macros

#define ONE 1
#define SQUARE(X) X*X

*/

#define PI 3.141592		/* Symbolic, or manifest, constans */
#define GRAVITY 9.8

#define THREE 3
#define MESSAGE "The greatest glory in living lies not in never falling, \
but in rising every time we fall."

#define NINE THREE*THREE
#define SAY_HELLO printf("Hello, World!\n");
#define FORMAT "Number is %d.\n"

	# define WITH_BLANK 1

#define MY_CH 'Z'
#define MY_ST "Z"		// Z\0

#define LIMIT 20
const int LIM = 50;
static int arr1[LIMIT];
static int arr2[LIM];		// clang, C++
const int LIM2 = 2 * LIMIT;
//const int LIM3 = 2 * LIM;	// clang, C++



/*
	Tokens

#define SIX 3*2
#define SIX 3 * 2
#define SIX 3      *      2

문자열 ? 표현식 ?
	
	- "전처리기"가 어떻게 인식할지는 compiler 마다 다를 수 있다고 함

*/

/* 
	Redefining Constants

	- define : file scope
	- include 한 header file의 define 도 가져옴
	- Macro를 전부 알기 어려울 수 있음
*/

#define SIX 2*3
#define SIX 2*3

//#undef SIX
//#define SIX 2 * 3		// Token 단위로 봤을 때 다르면 Warning


int main()
{	
	int n = THREE;

	SAY_HELLO;						// NOTE: additional ';'
	n = NINE;
	
	SAY_HELLO
		n = NINE;					// NOTE: tab


	printf(FORMAT, n);
	printf("%s\n", MESSAGE);		// replaced
	printf("SAY_HELLO NINE\n");		// Not replaced


	return 0;

}