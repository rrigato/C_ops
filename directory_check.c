#include "stdlib.h"
#include "stdio.h"
#include "fcntl.h"
#include "sys/stat.h"
#include "unistd.h"
#include "string.h"
int main(int argc, char * argv[]) 
{
	char * target_destination = argv[1];
	struct stat information;
	int system_check = 0;
	system_check = stat(target_destination, &information);
	if(system_check != -1)
	{
		if (S_ISDIR(information.st_mode))
		{
			printf("It registers as a directory\n");
		}
		else
		{
			printf("not a directory\n");
		}
	}

	return 0;
}
