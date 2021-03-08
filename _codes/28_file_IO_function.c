#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

int main()
{	
	FILE* fp;
	char words[MAX] = { '\0' };

	const char* filename = "record.txt";



	if ((fp = fopen(filename, "a+")) == NULL)	// r+ : not creating
	{
		fprintf(stderr, "Can't open \"%s\" file. \n",filename);
		exit(EXIT_FAILURE);
	}





	/*
		fscanf(), fprintf()  vs  fgets(), fputs()
		
		"%s " : 단어 단위	 /		줄 단위

		return #items		 /		return pointer
	*/



	//while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
	//	fprintf(fp, "%s ", words);

	while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
		fputs(words, fp);



	rewind(fp);	/* go back to beggining of file */



	//while (fscanf(fp, "%30s", words) == 1)
	//	fprintf(stdout, "%s\n", words);
	void* check;
	while ((check =fgets(words, MAX, fp)) != NULL)	// EOF check : eof w/o char, fgets returns NULL pointer!
		fputs(words, stdout);



	return 0;

}