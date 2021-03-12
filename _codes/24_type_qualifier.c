#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>



int main()
{	
	/*
		Qualified types
		const, volatile, restrict, _Atomic
	*/


	/*
		const
	*/


	//	C99 ideompotent
	const const const int n = 6;	// const int n = 6;

	typedef const int zip;
	const zip q = 8;		// const const int zip -> error �ȳ��� �ϵ��� �ߺ� ���!

	//const int i;		// NOT initialized
	//i = 12;				// ERROR

	const int j = 123;
	const int arr[] = { 1,2,3 };

	
	
	float f1 = 3.14f, f2 = 1.2f;

	const float* pf1 = &f1;		
	//*pf1 = 5.0f;	// Error
	pf1 = &f2;		// OK

	float* const pf2 = &f1;
	*pf2 = 5.0f;	// OK
	//pf2 = &f2;	// Error

	const float* const pf3 = &f1;
	//*pf3 = 5.0f;	// Error
	//pf3 = &f2;	// Error



	/*
		Global constant
		- file scope�� ���� (����)
		- header�� �־��ֱ� 
	*/



	/*
		volatile
		- DO NOT OPTIMIZE	( compiler�� �ǵ��� ����. )
		  (ex : hardward clock )
	*/

	volatile int vi = 1;		// volatile location
	volatile int* pvi = &vi;	

	int i1 = vi;

	// ..

	int i2 = vi;



	/*
		compiler�� vi ���� ������ �����Ŷ�� �Ǵ�,
		vi�� �о���� ���
		�ӽ� ����(cache)�� vi�� i2�� �����ؼ� ����ȭ �õ��� ���� ����.
		
		--> volatile�� ���ƹ����� !
	*/

	
	/*
		restrict (__restrict in VS)
		- SOLE initial means of accessing a data object
		- compiler can't check this restriction
	*/


	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* par = ar;

	int* __restrict restar = (int*)malloc(10 * sizeof(int));
	if (!restar) exit(1);


	ar[0] += 3;
	par[0] += 5;
	//par[0] += 8;		// ar, par�� �����ϴ� ���� ������ ���� ����������, 
						// �ٸ� �ĺ��ڸ� ���� �����ϱ⿡
						// compiler ���忡���� ����ȭ ������.
	

	restar[0] += 3;		// �����Ҵ� ���� �� �޸𸮸�,
	restar[0] += 5;		// �� �������θ� �����ҰŶ�� restrict ����
	//restar[0] += 8;	// compiler�� �̷��� ����ȭ�� ���� �� ����



	return 0;

}