#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#define size 256
int main ()
{
	char input[size];
	signal(SIGINT, SIG_IGN);
	fgets(input,size, stdin);
	printf("%s\n",input);
	return 0;
}
