#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#define size 256

char** parse( char*  );
void run (char * []);
int main ()
{
	char input[size];
	signal(SIGINT, SIG_IGN);

	char  Stop[] = "quit\n" ;
	
	char** Command  = NULL; 
	int i,z;
	printf( " > "); 
	while(fgets(input, size, stdin) && strcmp(input, Stop))
	{	
		printf( " > "); 
		Command = parse(input);
		run(Command);
		 i =0;
		 z= 0;
/* 		for (; Command[i][0] != '\0'; i++)
			printf("%s\n" Command[i]);  */ //should print out array of c strings
//		 z =0
//		for (; Command[z][0] != '\0'; z++)
//			free(Command[z])
		free(Command);
		
		
	}
	return 0;
}

void run(char * Arglist[])
{
	int fork_return;
	int wait_value;
	fork_return = fork();
	if (fork_return == -1)
		{
			perror("You forked up!");
			exit(1);
		}
	else if (fork_return ==0)
		{
			execvp(Arglist[1], Arglist);
			perror("execvp failed");
			exit(1);
		}
	else 
	{
		wait(&wait_value);
	}
		
	
}

char** parse( char* str )
{
    char *token;
    char tokens[256];
    char** args = malloc( 256 );    
    int i = 0;
       
    strcpy( tokens, str );
    
    args[i] = strtok( tokens, " " );
    
    while( args[i] )
    {
    
        i++;
        args[i] = strtok(NULL, " ");
    } 
 
    return args;
}
