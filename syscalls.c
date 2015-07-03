#include "fcntl.h"
#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
//#include "cstring"

int main ( int argc, char * argv [ ])
{
	char * something = argv[1];
	char * file_holder = NULL ;
	file_holder = (char*)malloc(1000);
	int buffer_size = 999;
	int file_descriptor = read(something, O_RDONLY);
	if (file_descriptor >0)
	{
	printf("file open");
	while (read(file_descriptor, file_holder, buffer_size) > 0)
		{	
			int i =0;
			while (file_holder != '\0')
			{
				printf("%c", file_holder[i]);
				i++;
			}
		}
	}
	free(file_holder);	
}
