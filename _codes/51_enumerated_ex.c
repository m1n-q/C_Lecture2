#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


enum spectrum { red, orange, yellow, green, blue };
const char* colors[] = { "red","orange","yellow","green","blue" };

#define LEN 30

int main()
{
	enum spectrum color;

	char input[LEN] = { 0, };
	bool founded = 0;
	
	while (fscanf(stdin, "%[^\n]%*c", input))
	{


		for (color = red; color <= blue; color++)
		{
			if (strcmp(colors[color], input) == 0)
			{
				//goto found;
				founded = true;
				break;
			}
			else; // for문은 다 돌아야지.
				  // flag 이럴 때 쓰는겨 !

		}



	//found:
	if (founded)
		switch (color)
		{
		case red:
			puts("Red roses");		// add \n
			break;
		case orange:
			puts("Orange naranja");		
			break;
		case yellow:
			puts("YELLAH!");
			break;
		case green:
			puts("Green Bean");
			break;
		case blue:
			puts("Blue ocean, keep going!");
			break;
		}
	else 
		printf("NO COLOR NAMED %s, TRY AGAIN\n", input);
	founded = false;
		//if (!strcmp(colors[red], input))
		//	printf("Red roses\n");
		//else if (!strcmp(colors[orange], input))
		//	printf("Orange juice\n");
		//else if (!strcmp(colors[yellow], input))
		//	printf("Yellow generation\n");
		//else if (!strcmp(colors[green], input))
		//	printf("Green bean\n");
		//else if (!strcmp(colors[blue], input))
		//	printf("Blue ocean\n");
		//else
		//	printf("NO COLOR NAMED %s, TRY AGAIN\n", input);


		


	} 
	
	return 0;

}