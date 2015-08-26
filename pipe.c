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

    // right here, there are two processes - parent will read from pipe
    if ( pid > 0 )                                  // parent will exec av[2]
    {
        close( thepipe[0] );                        // parent doesn't write

        if ( dup2( thepipe[1], 0 ) == -1 )
            oops( "Could not redirect stdin", 3 );

        close( thepipe[1] );                        // stdin duped, close pipe
        execlp( av[1], av[1], NULL );
        oops( av[1], 4 );
    }
