#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>



int main()
{	
	/*
		Object : value�� ������ �� �ִ� memory ����
	

		Identifier : Names for variables, functions , ...
	*/

	int var_name = 3;	// creates an object called 'var_name'
						// ������ �̸��� ���� �����ϴ� �޸� ���� -> Object
						// ������ �̸� -> Identifier

	
	int* pt = &var_name; // pt is an identifier.
	*pt = 1;			 // *pt is not an identifier. *pt designates an object.
						 // �޸� ������ �ǹ��ϴϱ� identifier ?
						 // ������ * ���� expression !

	
	int arr[100];	// arr is an identifier. Is arr an object? X (�� ��ü�� �޸� ���� ���°� �ƴ�. ù ������ �ּ��� ��)

	arr[0] = 7;		// arr[0] is an object.	( �޸� ������ ���� ���� )
					// arr[0] is an expression.
					
					// ***** �� OBJECT ? 


	/*
		L-value is an expression 'referring' to an object!

		L-value : left side of assignment
		R-value : right side, variable, constant, expressions
	

		L-Value �� ������Ʈ�٤�...? ���� or �ĺ��� �ƴѰ���
	*/


	var_name = 3;		//	 modifiable L-value. 
						//   ���� �� : �޸� ������ REFER !!!! ���� ��ü �ƴ�!


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

	char str2[] = "String in an array";		// �迭�� ������ �ƴ϶� �ڱ� �޸� ���� Ȯ����
											// str2�� �� �޸� ������ ���� identifier
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