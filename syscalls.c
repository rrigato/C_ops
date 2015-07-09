#include "fcntl.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
//#include "cstring"

void error_handle ( char *, char *);

int main ( int argc, char * argv [ ])
{
	char * something = argv[1];

	int file_descriptor = open(something, O_RDONLY);
	if (file_descriptor >0)
	{
		char * file_holder = NULL ;
		file_holder = (char*)malloc(1000);
		int buffer_size = 999;

		while ((read(file_descriptor, file_holder, buffer_size)) > 0)
		{	
			int i =0;
			while (file_holder[i] != '\0')
			{
				printf("%c", file_holder[i]);
				i++;
			}
		}
		free(file_holder);
	}
	else
	{
		if (argc ==2)
		{
			error_handle("Unable to open file: ", argv[1]);
		}
		else if (argc ==3)
		{
			error_handle("Unable to open file: ", argv[2]);
		}
	}

	return 0;
		
}
//handles error if unable to open file
//then exits the program
void error_handle (char * words, char * error_arg)
{
	printf( "%s\n", words);
	perror(error_arg); 
	exit(1);
}
//exits error handle
