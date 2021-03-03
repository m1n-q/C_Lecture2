#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int temp(int a)
{
	return 0;
}

int (*g(int a))(int)
{
	return temp;
}

int main()
{	
	/*
		*  indicates a pointer 
		() indicates a function
		[] indicates an array
		
	
	*/

	/*
		Deciphering Complex Declaration
		- Always read declaration from the inside out.
		- When there's a choice, always favor [], () over *. 
	*/

	/*
		1. �̸�(�ĺ���) ã��
		2. �켱���� : [],() -> *
	*/


	int* ap[10];	// 1. ap
					// 2. [10] : �迭!
					// 3. *	   : �����Ϳ� ����!

	typedef int* pint;
	pint ap2[10];	// pint 10��¥�� �迭 ? pint = int pointer!

	
	float* fp(float);	// 1. fp
						// 2. () : �Լ���! float parmeter��!
						// 3. *  : �����͸� ��ȯ�ϴ�!



	typedef float* pfloat;
	pfloat fp2(float);	// pfloat�� ��ȯ�ϴ� �Լ� ? pfloat = float pointer


	void (*pf)(int);
	/*
			1			1. *  : pointer to	  // () �� ������ �켱����!
	  	        2		2. () : function with int paramter
	  3					3.void: returnting void
	*/

		
	int* (*x[10])(void);
	/*		  1			  1. [] : array of
		  2				  2. *  : pointers to
					3	  3. () : functions with void arguments
	  4					  4. () : returning pointer to int
	
	*/

	/* A function can't return an array */

	// int f(int)[];  //Wrong

	/* But it can return a pointer to an array */
	
	int(*f(int))[];

	

	/* A function can't return a function */
	
	//int g(int)(int);	//Wrong

	/* But it can return a pointer to a function */
	
	int (*g(int))(void);

	/* An array of functions aren't possible */

	//int a[10](int);	//Wrong

	/* But an array of function pointers are possible */

	int* (*x2[10])(void);

	/* using typedef to simplify declaration */

	typedef int* FCN(void);
	typedef FCN* FCN_PTR;
	typedef FCN_PTR FCN_PTR_ARRAY[10];

	FCN_PTR_ARRAY x3;


	/* More example */

	int board[6][4];	// an array of arrays of int
	int** ptr;

	int* risks[10];		// A 10-element array of pointers to int
	int(*rusk)[10];		// A pointer to an array of 10 ints

	int* off[3][4];		// 3 x 4 array of pointers to int 
	int(*uff)[3][4];	// A pointer to 3 x 4 array of ints
	int(*uof[3])[4];	// An 3-element array of pointers to 4-elements arrays of int

	char* fump(int);		// function returning pointer to char
	char (*frump)(int);		// pointer to a function that returns char
	char (*flump[3])(int);  // 3-elements array of pointers to function that returns  char

	typedef int arr5[5];
	typedef arr5* p_arr5;
	typedef p_arr5 arrp10[10];

	arr5 togs;
	p_arr5 p2;
	arrp10 arp;

	return 0;

}