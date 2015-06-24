#include "stdio.h"
int main (int num_args, int array_arguements [])
{
	while (num_args--)
		{
			printf("%s", array_arguements[num_args]);
		}
		
	printf("Hello World!\n");
}
