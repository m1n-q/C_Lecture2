#define _CRT_SECURE_NO_WARNINGS

// WINDOWS X //
#include <stdio.h>
#include <stdalign.h>	// c++ style alignas, alignof


int main()
{	
#ifdef __clang_major__
	printf("clang dtected version %d.%d\n", __clang_major__, __clang_minor__);
#endif

#ifdef __GNUC__
	// note that clang 3.7 declares itself as a gcc 4.2"
	printf("gcc detected version %d.%d\n", __GNUC__, __GNUC_MINOR__);
#endif // __GNUC__

	printf("Alignment of char = %zu\n", alignof(char));			// 메모리에 align할 최소 byte 간격
	printf("alignof(float[10]) = %zu\n", alignof(float[10]));	// 각 원소 align 간격
	printf("alignof(struct{char c; int n;}) = %zu\n",
		alignof(struct { char c; int n; }));					// 각 멤버 align 간격

	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	char cz;
	//char alignas(double) cz;
	//char alignas(16) cz;
	
	printf("char alignment: %zd\n", alignof(char));
	printf("double alignment: %zd\n", alignof(double));


	/*
		double의 주소 % 8 = ?
		double이 8의 배수 메모리에 align(줄맞춤) 되는 것!
	*/

	printf("&dx : %p %lld\n", &dx, (long long)&dx % 8);
	printf("&ca : %p %lld\n", &ca, (long long)&ca % 8);
	printf("&cx : %p %lld\n", &cx, (long long)&cx % 8);
	printf("&dz : %p %lld\n", &dz, (long long)&dz % 8);
	printf("&cb : %p %lld\n", &cb, (long long)&cb % 8);
	printf("&cz : %p %lld\n", &cz, (long long)&cz % 8);
	//printf("&cz : %p %lld\n", &cz, (long long)&cz % 16);
	
	unsigned char alignas(long double) c_arr[sizeof(long double)];
	
	
	
	return 0;

}