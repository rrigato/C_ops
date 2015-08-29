#include "fcntl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "sys/stat.h"
#include "sys/types.h"
#include "unistd.h"
#include "time.h"
int main ()
{
		char time_fifo[] = "tmp_pipe2";

		if (mkfifo(time_fifo, 0666) == -1)
		{	
			perror("Fifo:");
		}
		time_t get_time;
		char *time_string = NULL;

		//printf("%s\n", time_string);  this prints
	
	
		int file_descriptor;
		int i = 0, counter = 0;
		while(1)
		{
					time(&get_time);
					time_string = ctime(&get_time);
					//printf("%s\n", time_string);
				 file_descriptor  = open(time_fifo, O_WRONLY);
				if (file_descriptor  == -1 )
					{
						perror("Unable to open named pipe");
						exit(1);
					}
/* 				counter  = sizeof(time_string);
				 i = 0;
				while(i < counter)
				{
					write(file_descriptor, (time_string + i* sizeof(char)) , sizeof(char));
					i++;
				} */
				 if (write(file_descriptor, time_string, strlen(time_string)+1) == -1 )
					{
						perror("Write error:");
						exit(1);
				
					} 
				sleep(1);
				if (close(file_descriptor) == -1)
				{
					perror("closing named pipe");
					exit(1);
				}

		}
		

	unlink(time_fifo);
	return 0;
}
