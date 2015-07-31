#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int option(char *);
void echo_option( int, char *);
void a_option (char *);
void erase(char *, char *);
void iuclc_option(int, char *);
int main(int argc, char * argv[])
{
	if (argc !=2 && argc!= 3)
	{
		printf("stty: invalid number of arguements \n");
		printf("Try 'stty--help' for more information.\n");
		exit(1);
	}
	
	char * option_check = argv[1];
	int return_value = 0;
	
	return_value = option(option_check);
	switch(return_value){
		case 1:
			echo_option(return_value, option_check);
			break;
		case 2:
			echo_option(return_value, option_check);
			break;
		case 3:
			a_option(option_check);
			break;
		case 4:
			{
				char * new_erase_key = argv[2];
				erase(option_check, new_erase_key);
				break;
			}
		default:
			iuclc_option(return_value, option_check);
			break;
	
	}
	return 0;
}




//  returns 1 if echo, 2 if -echo, 3 if -a, 4 if erase, 5 if iuclc, 6 if -iuclc
//prints an error otherwise 
int option(char * option_check)
{

	int selected = 0;	
	char echo[] = "echo";
	char dash_echo[] = "-echo";
	char a[] = "-a";
	char erase[] = "erase";
	char iuclc[] = "iuclc";
	char dash_iuclc[] = "-iuclc";

	if (strcmp(option_check, echo) == 0)
	{
		selected += 1;
		printf("%d\n", selected);
	}
	if (strcmp(option_check, dash_echo) == 0)
	{
		selected += 2;
		printf("%d\n", selected);
	}
	if (strcmp(option_check, a) == 0)
	{
		selected += 3;
		printf("%d\n", selected);
	}
	if (strcmp(option_check, erase) == 0)
	{
		selected += 4;
		printf("%d\n", selected);
	}
	
	if (strcmp(option_check, iuclc) == 0)
	{
		selected += 5;
		printf("%d\n", selected);
	}
	if (strcmp(option_check, dash_iuclc) == 0)
	{
		selected += 6;
		printf("%d\n", selected);
	}
	if (selected == 0 )
	{
		printf("stty: invalid arguement %s\n", option_check);
		printf("Try 'stty--help' for more information.\n");
		exit(1);
	}
	return selected;
}


void echo_option( int value, char * option_name)
{
	printf("%d\n", value);
}

void a_option (char * option_name)
{
	printf("3\n");
}
void erase(char * option_name, char * new_key)
{
	printf("4\n");
}

void iuclc_option(int value, char * option_name)
{
	printf("%d\n",value);
}
