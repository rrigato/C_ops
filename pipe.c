#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"

#define oops( m, x ) { perror(m); exit(x); }

int main( int ac, char* av[] )
{
    int thepipe[2],			    // two file descriptors
        newfd,                                      // useful for pipes
        pid,                                        // and the pid
	thepipe2[2],
	pid2;
	
    if ( ac != 4 )
    {
        fprintf( stderr, "usage: pipe cmd1 cmd2\n" );
        exit(1);
    }

    if ( pipe( thepipe ) == -1 )                    // get a pipe
        oops( "Cannot get a pipe", 1 );
	

    // now we have a pipe, now let's get two processes
    if ( ( pid = fork() ) == -1 )                   
        oops( "Cannot fork", 2 );


    if ( pid > 0 )                                  
    {
        close( thepipe[0] );                        

        if ( dup2( thepipe[1], 0 ) == -1 )
            oops( "Could not redirect stdin", 3 );

        close( thepipe[1] );                        // stdin duped, close pipe
        execlp( av[1], av[1], NULL );
        oops( av[1], 4 );
    }

	int process_return
	else
	{
	
		if ( pipe( thepipe2 ) == -1 )                    // get a pipe
			oops( "Cannot get a pipe", 1 );
		if (pid2 = fork()  ==-1)
		        oops( "Cannot fork", 2 );
		if (pid2 > 0)
		{
			close( thepipe[1]);   
			close( thepipe2[0]);

			if ( dup2( thepipe[0], 0 ) == -1 )
			    oops( "Could not redirect stdin", 3 );
			close( thepipe[0] ); 
			
			if ( dup2( thepipe2[1], 0 ) == -1 )
			    oops( "Could not redirect stdin", 3 );
			    
			close(thepipe2[1]);

                       // stdin duped, close pipe
			execlp( av[2], av[2], NULL );
			oops( av[1], 4 );
		}
		else
		{
			close(thepipe2[1]);
			if ( dup2( thepipe2[0], 0 ) == -1 )
				oops( "Could not redirect stdin", 3 );
				
			close( thepipe[0] );                        
			execlp( av[3], av[3], NULL );
			oops( av[1], 4 );
		}
/* 	    if ( ( pid2 = fork() ) == -1 )                   
		oops( "Cannot fork", 2 );
		if (pid2 >0)
		{
		    close( thepipe[0] );                            

		    if ( dup2( thepipe[1], 1 ) == -1 )
			oops( "could not redirect stdout", 4 );

		    close( thepipe[1] );                            
		    execlp( av[2], av[2], NULL );
		    oops( av[1], 5 );
		} */
	} 
    return 0;
}

