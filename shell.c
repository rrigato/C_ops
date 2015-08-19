#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#include "unistd.h"
#define SIZE 256

char** parse( char* );
void run (char **);
int main ()
{
	char input[SIZE];
	signal(SIGINT, SIG_IGN);

	char  Stop[] = "quit\n" ;
	
	char** Command  = NULL; 
	printf( " > "); 
	while(fgets(input, SIZE-1, stdin) && strcmp(input, Stop))
	{
		int i = 0;
		for (; input[i] != '\n';i++); //replaces newline character
		
		if (input[i] == '\n')
			input[i] = '\0';
		printf(" %s \n", input); 


		for (i =0; i != 20; i++)
			printf("%d \n", input[i]);
	
			
		Command = parse(input);
		
			printf("%s\n", Command[0]);
printf("%s\n", Command[1]);
	return 0;
		run(Command);
		free(Command);
		printf( " > "); 
		Command = NULL;
	}
	return 0;
}

void run(char ** Arglist )
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

		execvp(Arglist[0], Arglist);
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
