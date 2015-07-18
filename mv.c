#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "sys/stat.h"
#include "unistd.h"

void arg_check(int);
void error_handle( char *, char *);
void file_check( char *);
int directory_check (char *);
int is_file(char*);
int main(int argc, char * argv[])
{
	arg_check(argc);
	char * original_file = argv[1];
	file_check(original_file);
	char * target_destination = argv[2];
	int return_value =0;
	
	return_value = directory_check(target_destination);
	if (return_value)
	{
		int result = rename(original_file, target_destination);
		if (result ==-1)
		{
			perror(target_destination);
		}
	}
	else
	{
		int value = 0;
		value = link(original_file,target_destination);
		if(value != -1)
		{
			int unlinked =0;
			unlinked = unlink(original_file);
			if (unlinked == -1)
			{
				printf("Error: unable to remove file\n");
			}
		}
		else
		{
			printf("Error: unable to move file\n");
		}
	}
	
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

int directory_check( char * target_destination)
{
	struct stat information;
	int system_check = 0;
	system_check = stat(target_destination, &information);
	if(system_check != -1)
	{
		printf("%d\n", (int)information.st_mode);
		if (S_ISDIR(information.st_mode))
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
