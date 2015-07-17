#include "fcntl.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/stat.h"
void error_handle (char * words, char * error_arg);
int main ( int argc, char * argv [ ])
{
	if (argc !=3)
	{
		printf ("chmod: missing operand \n");
		printf("Try 'chmod --help' for more information\n");
		exit (1);
	}
	char * permission_change = argv[1];
	int value = atoi(permission_change);
	char * file_name = argv[2];
	int outcome = 0;
	outcome = chmod(file_name, value);
	if (outcome == -1 )
		error_handle("Error reading argument: ", file_name);
	//The system call worked 
	
}

void error_handle (char * words, char * error_arg)
{
	printf( "%s\n", words);
	perror(error_arg); 
	exit(1);
}
