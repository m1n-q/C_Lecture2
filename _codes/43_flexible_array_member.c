#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>;


int main()
{	
	/*
		Flexible array member
		- last member
		- array w/o len
		- dynamic allocation to structure
	*/

	struct flex {
		size_t count;		// 4 bytes
		double average;		// 8 bytes
		double values[];	// Flexible array member 



		// 4 + 8 + ?	=   ?

		// 8(padding) + 8 + 0 = 16	
		// why 0 ?

	};

	const size_t n = 3;


	/*
		Member pointer가 아니구 Structure pointer

		- member에 대한 동적할당이 아닌 structure 자체 동적할당

	*/

	struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf == NULL) exit(1);
	

	printf("Flexible array member\n\n");

	printf("Sizeof struct flex : %zd\n", sizeof(struct flex));		// 16
	printf("	Sizeof *pf : %zd\n", sizeof(*pf));					// 16
	printf("   Sizeof malloc() : %zd\n\n", (sizeof(struct flex) + n * sizeof(double)));		// 16 + (3 * 8)


	printf("%lld\n", (long long)pf);
	printf("%lld\n", (long long)& (pf->count) );
	printf("%zd\n", sizeof(pf->count));		// padded. 4 to 8 
	printf("%lld\n\n", (long long)& (pf->average) );           //  count ( padded  ) | average


	printf("Address of pf->values : %lld\n", (long long)& (pf->values));
	printf("  Value of pf->values : %lld\n", (long long)(pf->values));	// pf->values == 배열명 == 첫원소주소
	printf("   Size of pf->values : %zd\n", sizeof(&pf->values));		// No memory size!

	
	

	printf("\n");



	pf->count = n;
	pf->values[0] = 1.1;
	pf->values[1] = 2.1;
	pf->values[2] = 3.1;

	pf->average = 0.0;

	for (unsigned i = 0; i < pf->count; ++i)
		pf->average += pf->values[i];
	pf->average /= (double)pf->count;

	printf("Average = %f\n", pf->average);



	/*
		차이 1: pointer 만큼 size 차지. 
		차이 2: 추가 메모리가 heap 어딘가에.
	*/
	/*
	struct nonflex
	{
		size_t count;
		double average;
		double* values;		// Use malloc()

	};


	struct nonflex nf;
	nf.values = (double*)malloc(sizeof(double) * n);
	*/

	/*

	struct flex* pf2 = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
	if (pf2 == NULL) exit(1);

	*pf2 = *pf1;		// Don't copy flexible members, use memcpy()


	*/
	return 0;

	
}