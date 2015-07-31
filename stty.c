#include "stdio.h"
#include "stdlib.h"
int option(char *);
int main(int argc, char * argv[])
{
	char * option_check = argv[1];
	option(option_check);
	return 0;
}

int option(char * option_check)
{
	return 1;
}
