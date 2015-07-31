#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int option(char *);
int main(int argc, char * argv[])
{
	if (argc !=2 && argc!= 3)
	{
		printf("stty: invalid number of arguements \n");
		printf("Try 'stty--help' for more information.\n");
		exit(1);
	}
	
	char * option_check = argv[1];
	option(option_check);
	return 0;
}

//adds 10 to the return value if it is has a dash
// otherwise returns 1 if echo, 2 if a, 3 if erase, 4 if iuclc 
int option(char * option_check)
{

	int selected = 0;	
	char echo[] = "echo";
	char a[] = "-a";
	char erase[] = "erase";
	char iuclc[] = "iuclc";
	char dash ='-';
	if (option_check[0] == dash)
	{
		selected += 10;
		printf("%d\n", selected);
	}
	if (strstr(option_check, echo) != NULL)
	{
		selected += 1;
		printf("%d\n", selected);
	}
	if (strstr(option_check, a) != NULL)
	{
		selected += 2;
		printf("%d\n", selected);
	}
	if (strstr(option_check, erase) != NULL)
	{
		selected += 3;
		printf("%d\n", selected);
	}
	
	if (strstr(option_check, iuclc) != NULL)
	{
		selected += 4;
		printf("%d\n", selected);
	}
	if (selected == 0 || selected ==10)
	{
		printf("stty: invalid arguement %s\n", option_check);
		printf("Try 'stty--help' for more information.\n");
		exit(1);
	}
	return selected;
}

