#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()
{	
	/*
		Object : value를 저장할 수 있는 memory 공간
	

		Identifier : Names for variables, functions , ...
	*/

	int var_name = 3;	// creates an object called 'var_name'
						// 변수의 이름을 통해 접근하는 메모리 공간 -> Object
						// 변수의 이름 -> Identifier

	
	int* pt = &var_name; // pt is an identifier.
	*pt = 1;			 // *pt is not an identifier. *pt designates an object.
						 // 메모리 공간을 의미하니까 identifier ?
						 // 연산자 * 붙은 expression !

	
	int arr[100];	// arr is an identifier. Is arr an object? X (그 자체가 메모리 공간 갖는게 아님. 첫 ㅇ원소 주소일 뿐)

	arr[0] = 7;		// arr[0] is an object.	( 메모리 공간에 접근 가능 )
					// arr[0] is an expression.
					
					// ***** 왜 OBJECT ? 


	/*
		L-value is an expression 'referring' to an object!

		L-value : left side of assignment
		R-value : right side, variable, constant, expressions
	

		L-Value 는 오브젝트다ㅓ...? 참조 or 식별자 아닌가요
	*/


	var_name = 3;		//	 modifiable L-value. 
						//   변수 명 : 메모리 공간을 REFER !!!! 공간 자체 아님!


	pt = &var_name;
	int* ptr = arr;		// arr : identifier, not an object.
	*pt = 7;			// *pt is not an identifier
						//	but an modifiable L-value expression. 


	int* ptr2 = arr + 2 * var_name;	// address r-value.
	*(arr + 2 * var_name) = 456;	// l-value expression



	const char* str = "Constant string";	// str is a modifiable l-value
	str = "Second string";	 // "Constant string" = "Second string" -> impossible
						     //	-> object X

	//str[0] = 'A';		// Error
	//puts(str);

	char str2[] = "String in an array";		// 배열은 참조가 아니라 자기 메모리 공간 확보됨
											// str2이 그 메모리 공간에 대한 identifier
	str2[0] = 'A';	// OK
	//puts(str2);

	/*
		Identifier have scope.
		Objects have storage duration.
		Variables and functions have one of the following linkages :
			external linkage, internal linkage, or no linkage.
	
	*/



	return 0;

}