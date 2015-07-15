/*You need to pass a time_t data type to the utime system call in order to change
the access and modification times. If you pass NULL to utime it will change both to the 
current time.
*/
#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/time.h"
#include "sys/types.h"
#include "sys/stat.h"
#include "utime.h"
#include "time.h"


int touch_options( char *);
void change_both (char *);
void change_access(char*);
void change_mod(char*);
void custom_time( char *, char *, int);
int main ( int argc, char * argv [])
{
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

	if (argc==2)
	{
		option_check = NULL;
		file_name = argv[1];
	}
	else if (argc ==3)
	{
		file_name = argv[2];
	}
	else if (argc ==4)
	{
		file_name = argv[3];
	}
	
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
			if (argc ==2)
			{
				change_both(file_name);	
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
			else if (argc ==4)
			{
				char * time_arg = argv[2];
				custom_time(time_arg, file_name, options);
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
void change_access(char * path)
{

	//struct with two time_t members to make the sys call to utime
	struct utimbuf current_time;
	struct stat original_info;
        if ( stat( path, &original_info ) != -1 )
        {
		//gets the current mod time from the stat struct to make sure mod time isnt changed
		//and applies it to the current_time utimbuf struct that 
		//will be used in the utime syscall
		 current_time.modtime = original_info.st_mtime; 
        }
	else 
	{
		printf("unable to open file");
		exit(1);
	}
	time_t epoch_seconds;
	time(&epoch_seconds);
	int time = 0;	
	//The mod and access times are time_t datatypes
	current_time.actime= epoch_seconds;
	//have to pass a reference to a utimbuf struct
	time = utime(path, &current_time);
	if (time == -1 )
	{
		printf("Error: unable to modifiy access time.\n");
		exit(1);
	}
	else 
	{
		//function changed both the access and modification time to current time.
	}
}
void change_mod(char * path)
{
	//struct with two time_t members to make the sys call to utime
	struct utimbuf current_time;
	struct stat original_info;
        if ( stat( path, & original_info ) != -1 )
        {
		//gets the current mod time from the stat struct to make sure mod time isnt changed
		//and applies it to the current_time utimbuf struct that 
		//will be used in the utime syscall
		 current_time.actime = original_info.st_atime; 
        }
	else 
	{
		printf("unable to open file");
		exit(1);
	}
	time_t epoch_seconds;
	time(&epoch_seconds);
	int time = 0;	
	//The mod and access times are time_t datatypes
	current_time.modtime= epoch_seconds;
	//have to pass a reference to a utimbuf struct
	time = utime(path, &current_time);
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
void custom_time(char * time_arg, char * file_name, int options)
{
		struct tm time_struct;
		char  month[3];
		char day[3];
		char hour[3];
		char minutes[3];
		month[0] = time_arg[0]; month[1] = time_arg[1];
		day[0] = time_arg[2]; day[1] = time_arg[3];
		hour[0] = time_arg[4]; hour[1] = time_arg[5];
		minutes[0] = time_arg[6]; minutes[1] = time_arg[7];
		time_struct.tm_year = 115;
		time_struct.tm_min = atoi(minutes);
		time_struct.tm_hour = atoi(hour);
		time_struct.tm_mday = atoi(day);
		time_struct.tm_mon = atoi(month);
		struct utimbuf current_time;
		if (options == 1 || options ==7)
		{
			current_time.actime = mktime(&time_struct);
			current_time.modtime = mktime(&time_struct);
		}
		else if (options == 2)
		{
			current_time.modtime = mktime(&time_struct);
			struct stat original_info;
			if ( stat( file_name, & original_info ) != -1 )
			{
				//gets the current mod time from the stat struct to make sure mod time isnt changed
				//and applies it to the current_time utimbuf struct that 
				//will be used in the utime syscall
				current_time.actime = original_info.st_atime; 
			}
			else 
			{
				printf("unable to open file");
				exit(1);
			}
		}
		else if (options == 4)
		{
			current_time.actime = mktime(&time_struct);
			struct stat original_info;
			if ( stat( file_name, &original_info ) != -1 )
			{
				//gets the current mod time from the stat struct to make sure mod time isnt changed
				//and applies it to the current_time utimbuf struct that 
				//will be used in the utime syscall
				 current_time.modtime = original_info.st_mtime; 
			}
			else 
			{
				printf("unable to open file");
				exit(1);
			}
			
		}
		int Time = utime(file_name, &current_time);
		if (Time == -1 )
		{
			printf("Error: unable to modifiy access and modification time.\n");
			exit(1);
		}
		else 
		{
			//function changed both the access and modification time to current time.
			printf("might of worked");
		}		
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
