#include "stdio.h"
#include "stdlib.h"
#include "signal.h"
#include "string.h"
#define size 256
int main ()
{
	char input[size];
	signal(SIGINT, SIG_IGN);

	char  Stop[] = "quit\n" ;

	
	while(fgets(input, size, stdin) && strcmp(input, Stop))
	{	
		
	}
	return 0;
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
