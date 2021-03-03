#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 31


struct book
{
	char title[MAXTITL];
	char author[MAXAUTL];
	//char* title;		// Not recommended
	//char* author;		// Not recommended
	float price;

};

struct rectangle
{
	double width;
	double height;
};

double rect_area(struct rectangle r)
{
	return r.width * r.height;
}

double rect_area_ptr(struct rectangle* r)
{
	return r->width * r->height;
}


int main()
{	

	/* 
		�ʱ�ȭ ( != ���� )
	*/
	struct book book_to_read = { "MOMO", "shin", 11.25f };	


	
	
	/*
		�����ϴ� ���.
	*/

	// 0
	//book_to_read = { "MOMO", "shin", 11.25f };  // Error : ���� != �ʱ�ȭ 

	
	// 1,  ���ŷӴ�.
	strcpy(book_to_read.title, "Harry Porter");
	strcpy(book_to_read.author, "Rowling");
	book_to_read.price = 20.3f;
	

	// 2, ���ŷӴ�. �޸� ����.
	struct book tmp = { "Harry Porter", "Rowling", 20.3f };
	book_to_read = tmp;


	// 3, Compound literal : Temporary structure values, �پ��� �ڷ��� literal�� ����.
	
	book_to_read = (struct book) { "Harry Porter", "Rowling", 20.3f };
									
	
	
	
	
	/*  L-value ! �޸� �ּҸ� ������. */



	// area�� ���� rec1�� �����ϴ� ���ŷο�..
	struct rectangle rec1 = { 1.0, 2.0 };
	double area, area2;
	area = rect_area(rec1);		
	printf("%f\n", area);
	
	

	// Literal�� �ٷ� arguments�� !
	area = rect_area((struct rectangle) { 1.0, 2.0 });
	printf("%f\n", area);



	// L-value, �ּ� ������ �� ����, �޸� ���� ����!
	area = rect_area_ptr(&(struct rectangle) { 1.0, 2.0 });		
	printf("%f\n", area);

	
	return 0;

}