#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

void oops( int, int ); 

int main( int ac, char* av[] )
{
    int thepipe[2],			    
        newfd,                                     
        pid,                                        
	thepipe2[2],
	pid2;
	
    if ( ac != 4 )
    {
        fprintf( stderr, "usage: pipe cmd1 cmd2\n" );
        exit(1);
    }

    if ( pipe( thepipe ) == -1 )                    
        oops( "Cannot get a pipe", 1 );
	

    if ( ( pid = fork() ) == -1 )                   
        oops( "Cannot fork", 2 );


    if ( pid == 0 )                                  
    {
        close( thepipe[0] );                        

        if ( dup2( thepipe[1], 1 ) == -1 )
            oops( "Could not redirect stdout", 3 );

        close( thepipe[1] );                        
        execlp( av[1], av[1], NULL );
        oops( av[1], 4 );
    }

		if ( pipe( thepipe2 ) == -1 )                    
			oops( "Cannot get a pipe", 1 );

		pid2 = fork();
		if (pid2 ==-1)
		        oops( "Cannot fork", 2 );
		if (pid2 == 0)
		{
			close( thepipe[1]);   
			if ( dup2( thepipe[0], 0 ) == -1 )
			    oops( "Could not redirect stdin", 3 );
			close( thepipe[0] ); 
			
			close( thepipe2[0]);
			if ( dup2( thepipe2[1], 1 ) == -1 )
			    oops( "Could not redirect stdout", 3 );
			close(thepipe2[1]);
			
			execlp( av[2], av[2], NULL );
			oops( av[1], 4 );
		}
		else
		{
			close(thepipe[0]);
			close(thepipe[1]);
			close(thepipe2[1]);
			if ( dup2( thepipe2[0], 0 ) == -1 )
				oops( "Could not redirect stdin", 3 );
				
			close( thepipe[0] );                        
			execlp( av[3], av[3], NULL );
			oops( av[1], 4 );
		}

    return 0;
}

void oops (int m, x)
{ 
	perror(m); 
	exit(x); 
}
