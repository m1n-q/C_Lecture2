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
	const zip q = 8;		// const const int zip -> error 안나게 하도록 중복 허락!

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
		- file scope로 선언 (전역)
		- header에 넣어주기 
	*/



	/*
		volatile
		- DO NOT OPTIMIZE	( compiler가 건들지 마라. )
		  (ex : hardward clock )
	*/

	volatile int vi = 1;		// volatile location
	volatile int* pvi = &vi;	

	int i1 = vi;

	// ..

	int i2 = vi;



	/*
		compiler가 vi 값이 변하지 않을거라고 판단,
		vi를 읽어오는 대신
		임시 저장(cache)된 vi를 i2에 대입해서 최적화 시도할 수도 있음.
		
		--> volatile로 막아버리기 !
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
	//par[0] += 8;		// ar, par이 접근하는 곳은 같으니 같은 연산이지만, 
						// 다른 식별자를 통해 접근하기에
						// compiler 입장에서는 최적화 안해줌.
	

	restar[0] += 3;		// 동적할당 받은 이 메모리를,
	restar[0] += 5;		// 이 수단으로만 접근할거라는 restrict 선언
	//restar[0] += 8;	// compiler가 이렇게 최적화를 해줄 수 있음



	return 0;

}