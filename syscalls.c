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
	int tab = 0;
	int line_num =0;
	int doller_sign =0;
	if (switches[1]=='T'|| switches[2]=='T'||switches[3]=='T')
		tab =1;
	if (switches[1]=='E'|| switches[2]=='E'||switches[3]=='E')
		doller_sign = 1;
	if (switches[1]=='n'|| switches[2]=='n'||switches[3]=='n')
		line_num = 1;
	int i = 0;
	while (file_holder[i] != '\0')
	{
		if (tab && (file_holder[i] =='\t'))
		{			
			printf("^I");
		}
		if (doller_sign && (file_holder[i] =='\n'))
		{
			printf("$\n");
		
		}
		if (line_num && (file_holder[i] =='\n'))
		else
		{	
			printf("%c", file_holder[i]);
		}
		i++;
	}

}
