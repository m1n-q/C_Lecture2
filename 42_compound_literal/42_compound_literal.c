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
		초기화 ( != 대입 )
	*/
	struct book book_to_read = { "MOMO", "shin", 11.25f };	


	
	
	/*
		대입하는 방법.
	*/

	// 0
	//book_to_read = { "MOMO", "shin", 11.25f };  // Error : 대입 != 초기화 

	
	// 1,  번거롭다.
	strcpy(book_to_read.title, "Harry Porter");
	strcpy(book_to_read.author, "Rowling");
	book_to_read.price = 20.3f;
	

	// 2, 번거롭다. 메모리 차지.
	struct book tmp = { "Harry Porter", "Rowling", 20.3f };
	book_to_read = tmp;


	// 3, Compound literal : Temporary structure values, 다양한 자료형 literal의 묶음.
	
	book_to_read = (struct book) { "Harry Porter", "Rowling", 20.3f };
									
	
	
	
	
	/*  L-value ! 메모리 주소를 가진다. */



	// area를 위해 rec1을 생성하는 번거로움..
	struct rectangle rec1 = { 1.0, 2.0 };
	double area, area2;
	area = rect_area(rec1);		
	printf("%f\n", area);
	
	

	// Literal을 바로 arguments로 !
	area = rect_area((struct rectangle) { 1.0, 2.0 });
	printf("%f\n", area);



	// L-value, 주소 가져올 수 있음, 메모리 공간 차지!
	area = rect_area_ptr(&(struct rectangle) { 1.0, 2.0 });		
	printf("%f\n", area);

	
	return 0;

}