#include "stdio.h"
#include "stdlib.h"

void arguement_change ( char *, char *, char *, int, char * []);
int cat_check ( char *);
int main ( int argc, char * argv [])
{
	//exits the program if three arguements are not provided
	if (argc != 3)
		exit(1);
	// gets seperate pointers for each string to test which commands the user entered.
	char * first_arg = argv[1];
	char * second_arg = argv[2];
	char * third_arg = argv[3];
	printf("%s \n", first_arg);
	if (! cat_check (first_arg))
		exit(1);
	printf("%s \n", first_arg);
	
	
}
int cat_check (char * first_arg)
{
	if (first_arg =="cat")
		return 1;
	else return 0;
}

void arguement_change ( char * first, char * second, char * third, int argc, char * argv[])
{
	
}
