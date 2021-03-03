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



struct car_data
{
	char model[15];
	int status;		// 0 = personal, 1 = company
	union {
		struct personal_owner	po;
		struct company_owner	co;
	};
};

void print_car(struct car_data car)
{
	printf("============================================\n");
	printf("Model : %s, Owner : ", car.model);
	if (car.status == 0)
		printf("%s-%s\n", car.po.rrn1, car.po.rrn2);
	else
		printf("%s-%s-%s\n", car.co.crn1, car.co.crn2, car.co.crn3);
	printf("============================================\n");

}

int main()
{
	struct personal_owner ming = { "970212","1041711" };
	struct company_owner samsung = { "110","01","12088" };

	struct car_data samcar = { "Benz",1, .co = samsung };
	struct car_data mycar = {
		.model = "Bentley",
		.status = 0,
		.po = ming
	};

	print_car(samcar);
	print_car(mycar);


	/* Example 2*/

	struct Vector2D
	{
		union {
			struct { double x, y; };
			struct { double i, j; };
			struct { double arr[2]; };
		};

	};
	
	struct Vector2D v2 = { 3.14, 2.99 };

	
	printf("%.2f %.2f\n", v2.x, v2.y);
	printf("%.2f %.2f\n", v2.i, v2.j);
	printf("%.2f %.2f\n", v2.arr[0], v2.arr[1]);

	/* 배열의 장점 ?  for 문 가능 !*/
	for (int d = 0; d < 2; d++)
		printf("%.2f ", v2.arr[d]) ;
	
	return 0;

}