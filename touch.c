#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/time.h"
#include "sys/types.h"
#include "utime.h"
#include "time.h"

//int touch_check ( char *);
int touch_options( char *);
void change_both (char *);
void change_access(char*);
void change_mod(char*);
int main ( int argc, char * argv [])
{
	/*char * arg_0 = argv[0];
	if (touch_check(arg_0))
	{
		//good to proceed with the program
		printf("good to go");
	}
	else
	{
		printf("Error improper system command\n");
		exit(1);
	}*/
	char * option_check = NULL;
	char * file_name = NULL;
	option_check = argv[1];
	int options = 0;
	if (argc ==1)
	{
		printf("touch: missing file operand\n");
		printf("Try 'touch --help' for more information\n");
		exit(1);
	}
	if (option_check[0] =='-')
	{
		options = touch_options(option_check);
		if (options ==1)
		{
			file_name = argv[3];
		}
		else
		{
			file_name = argv[2];
		}
	}
	else
	{
		option_check = NULL;
		file_name = argv[1];
	}
	if (argc ==2)
	{
		int file_descriptor = 0;
		//two inefficient syscalls to check and see if the file exists
		if ((file_descriptor= open(file_name, O_RDONLY))==-1)
		{
			int Create = 0;
			// sets the file to rw-rw-r-- by default
			Create = creat(file_name, 0664);
			if (Create == -1)
			{
				printf("Could not create a new file");
				exit(1);
			}
			else 
			{
				//printf("file created\n");
				//A new file was created
			}
		}
		else 
		{
			change_both(file_name);	
		}
		close (file_descriptor);	
	}
	else if (argc ==3)
	{
		if (options == 3)
		{
			change_both(file_name);
		}
		else if (options ==5)
		{
			change_access(file_name);
		}
		else if(options==6)
		{
			change_mod(file_name);
		}
	
	}
	return 0;
}
void change_both (char * path)
{


	int time = 0;	
	time = utime(path, NULL);
	if (time == -1 )
	{
		printf("Error: unable to modifiy access and modification time.\n");
		exit(1);
	}
	else 
	{
		//function changed both the access and modification time to current time.
	}
}
void change_access(char * second_arg)
{
	struct utimbuf current_time;
	current_time.actime = 1000000;
	current_time.modtime;
	
}
void change_mod(char * second_arg)
{
	struct utimbuf current_time;
	current_time.actime;
	current_time.modtime= 1000000;
	

	
}

int touch_options(char * second_arg)
{
	int i = 0;
	int result = 0;
	while (second_arg[i] != '\0')
	{
		i++;
	}
	if (i ==4)
	{
		if (	   (second_arg[1] =='m'||second_arg[2]=='m' || second_arg[3] == 'm')
			&& (second_arg[1] =='t'||second_arg[2]=='t' || second_arg[3] == 't')
			&& (second_arg[1] =='a'||second_arg[2]=='a' || second_arg[3] == 'a')    )
		{
			result =1;
			return result;
		}
		else
		{
			printf("improper options");
			exit(1);
		}

	}
	else if (i==3)
	{
		if (	   (second_arg[1] =='m'||second_arg[2]=='m')
			&& (second_arg[1] =='t'||second_arg[2]=='t')	)
		{
			result =2; return result;
		}

		else if (	  (second_arg[1] =='m'||second_arg[2]=='m')
				&&(second_arg[1] =='a'||second_arg[2]=='a')	)
		{
			result =3; return result;
		}

		else if (	  (second_arg[1] =='a'||second_arg[2]=='a')
				&&(second_arg[1] =='t'||second_arg[2]=='t')	)
		{
			result =4; return result;
		}
	}
	else if (i==2)
	{
		if ( second_arg[1] =='a')
		{
			result =5; return result;
		}
		else if ( second_arg[1] =='m')
		{
			result = 6; return result;
		}

		else if ( second_arg[1] =='t')
		{
			result = 7; return result;
		}

		
	}
}
/*
int touch_check (char * arg_0)
{
	char compare [] = "./touch";
	if (!strcmp(arg_0, compare) ==0)
		return 1;
	return 0;
}*/
