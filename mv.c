#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"

void arg_check(int);
void error_handle( char *, char *);
void file_check( char *);
void directory_check (char *);
int main(int argc, char * argv[])
{
	arg_check(argc);
	char * original_file = argv[1];
	file_check(original_file);
	char * target_destination = argv[2];
	directory_check(target_destination);
	
	return 0;
}


void arg_check(int argc)
{
	if (argc != 3)
	{
		printf("mv: incorrect number of arguements\n");
		printf("Try '--mv help' for more information\n" );
		exit(1);
	}
}

void file_check(char * original_file)
{
	int file_descriptor = 0;
	file_descriptor = open(original_file, O_RDONLY);
	if(file_descriptor == -1)
	{
		perror(original_file);
		exit(1);
	}
	else 
	{
		close(file_descriptor);
	}

}
void directory_check( char * target_destination)
{

}
