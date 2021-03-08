#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define LEN 50

struct fortune
{
	char	bank_name[LEN];
	double	bank_saving;
	char	fund_name[LEN];
	double	fund_invest;
};

double sum(double, double);
double sum2(double*, double*);
double sum3(struct fortune);
double sum4(struct fortune*);
int main()
{	

	struct fortune my_fortune = {
		"Wells-Fargo",
		4032.27,
		"JPMorgan Chase",
		8543.94
	};

	printf("Total : $%.2f\n",
		sum(my_fortune.bank_saving, my_fortune.fund_invest));

	printf("Total : $%.2f\n",
		sum2(&my_fortune.bank_saving, &my_fortune.fund_invest));


	/* structure parameter */
	printf("Total : $%.2f\n",
		sum3(my_fortune));
	
	printf(my_fortune.bank_name);	// 함수의 parameter는 argument의 복사(대입)본!!
	printf("\n");

	/* structure pointer parameter*/
	printf("Total : $%.2f\n",
		sum4(&my_fortune));

	printf(my_fortune.bank_name);	// 함수의 parameter가 argument와 같은 주소 참조!!
	printf("\n");
	
	
	return 0;

}

double sum(double x, double y)
{
	return x + y;
}

double sum2(/* const */ double* x, /* const */ double* y)
{
	//*x = 0.0f;
	//*y = 0.0f;

	return *x + *y;
}

double sum3(struct fortune ft)		
{	
	/*	
		Call by value
		ft != my_fortune 
	*/

	strcpy(ft.bank_name, "CHANGED");
	return (ft.bank_saving + ft.fund_invest);
}

double sum4(/* const */ struct fortune* ft)		// member 원본 변경 방지.
{
	/*
		Call by pointer
		ft == &my_fortune,
		*ft == my_fortune
	*/

	strcpy(ft->bank_name, "CHANGED");
	return (ft->bank_saving + ft->fund_invest);
}