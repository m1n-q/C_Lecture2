#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*
	Union and Structure
*/

struct personal_owner
{
	char rrn1[7];		// Regident Registration Number
	char rrn2[8];		// ex: 970212-1041711
};

struct company_owner
{
	char crn1[4];		// Company Registration Number
	char crn2[3];		// ex: 111-22-33333
	char crn3[6];

};

union data
{
	struct personal_owner	po;
	struct company_owner	co;
};

struct car_data
{
	char model[15];
	int status;		// 0 = personal, 1 = company
	union data ownerinfo;   
};

void print_car(struct car_data car)
{
	printf("============================================\n");
	printf("Model : %s, Owner : ",car.model);
	if (car.status == 0)
		printf("%s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
	else
		printf("%s-%s-%s\n", car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
	printf("============================================\n");

}

int main()
{	
	struct personal_owner ming = { "970212","1041711" };
	struct company_owner samsung = { "110","01","12088" };

	struct car_data samcar = { "Benz",1, .ownerinfo.co = samsung };
	struct car_data mycar = {
		.model = "Bentley",	
		.status = 0, 
		.ownerinfo.po = ming
	};

	print_car(samcar);
	print_car(mycar);


	return 0;
	
}