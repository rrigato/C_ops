
#include "stdio.h"

void arguement_change ( char *, char *, char *, int, char * []);
int main ( int argc, char * argv [])
{

	char * second= argv[0];
	printf ("%s\n", argv[0]);
	printf ("%c", second[3]);
	int i = 0;
	while ((*(second + i)) != '\0')
	{i ++;}
	printf ("%d \n", i);
	//char * first = NULL, second = NULL, third = NULL;
	//arguement_change (&first, &second, &third);
	
	
}

void arguement_change ( char * first, char * second, char * third, int argc, char * argv[])
{
	
}
