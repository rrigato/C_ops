#include "fcntl.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
//#include "cstring"

void error_handle ( char *, char *);
void no_switches (char *);
void with_switches (char *, char *);

int main ( int argc, char * argv [ ])
{
	char * file_name = NULL;
	char * switches = NULL;
	if (argc ==2)
	{	
		file_name = argv[1];
	}
	else if (argc==3)
	{
		switches = argv[1];
		file_name = argv[2];

	}
	else
	{
		printf("Invalid number of arguements");
		exit(1);
	}
	int file_descriptor = open(file_name, O_RDONLY);
	if (file_descriptor >0)
	{
		char * file_holder = NULL ;
		file_holder = (char*)malloc(1000);
		int buffer_size = 999;

		while ((read(file_descriptor, file_holder, buffer_size)) > 0)
		{	if (argc==2)
			{
				no_switches(file_holder);
			}
			else if (argc ==3)
			{
				with_switches(file_holder, switches);
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

void with_switches(char * file_holder, char * switches)
{
	int i = 0;
	int line_counter =1;
	if ((switches[1]== 'n' || switches[2] == 'n' || switches[3] == 'n'))
	{
		printf("     1  ");
		line_counter++;
	}
	while (file_holder[i] != '\0')
	{

		//checks if any of elements 1-3 of second arguement have the switch of T
		//element 0 will not have a switch because that has the dash for the option
		if ( file_holder[i] == '\t' && (switches[1] =='T' || switches[2] == 'T' ||switches[3] =='T'))
			printf ("^I");
		else 

		{
			//checks file_holder[i] read in for escape clause and prints a $ if E is selected as an option BEFORE the 
			//escape clause is shown on the screen
			if(file_holder[i] == '\n' && (switches[1]== 'E' || switches[2] == 'E' || switches[3] == 'E'))
					{ printf("$");}
			printf("%c", file_holder[i]);
			//checks file_holder[i] read in for escape clause and prints line number AFTER the line is returned
			if (file_holder[i] == '\n' && (switches[1]== 'n' || switches[2] == 'n' || switches[3] == 'n'))
				{ 
					if(file_holder[i+1] == '\0')
					{
					//prevents extra number at the end
					}
					else
					{
						
						printf("     %d  ", line_counter); line_counter++;
					}				
				}
		}
		i++;
		
	}

}

void no_switches(char * file_holder)
{
	int i = 0;
	while (file_holder[i] != '\0')
	{
		printf("%c", file_holder[i]);
		i++;
	}

}
