#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void arguement_change ( char *, char *, char *, int, char * []);
int cat_check ( char *);
int main ( int argc, char * argv [])
{
	//exits the program if three arguements are not provided
	//if (argc != 4)
	//	exit(1);
	// gets seperate pointers for each string to test which commands the user entered.
	char * first_arg = argv[1];
	char * second_arg = argv[2];
	char * third_arg = argv[3];

	//check to make sure command is cat
	if (!cat_check (first_arg))
		exit(1);
	FILE * fp = NULL;
	fp = fopen("MyQueue.cpp", r+);
	if (fp)
	{
		fscanf(
		fclose (fp);	

	}


	
	
}
int cat_check (char * first_arg)
{
	char CAT [] = "cat";
	if (!strcmp(first_arg, CAT))
		return 1;
	else return 0;
}

void arguement_change ( char * first, char * second, char * third, int argc, char * argv[])
{
	
}
