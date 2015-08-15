#include "stdio.h"
#include "signal.h"
#include "stdlib.h"
#define n 1000000
void sieve();
void display();
void display2();
int max;
int main (int argc, char * argv[])
{

	max = 0;
	signal(SIGINT,SIG_IGN);
	signal(SIGINT, display);
	signal(SIGQUIT, display2);
	sieve();
	
	return 0;
}


void sieve()
{

	long i=2;
	long j = 0;
	long u = 0;
	int Table[n];
	
		    
	for (; i < n; i++) //sets all numbers to 'prime'
		Table[i]=1;

	for (i = 2 ; i <n;i++) //weeds out nonprime
	{
		if ( Table[i])
		{	
			for (j=i; i*j <n;j++)
				Table[i*j]=0;
		}
			u =2;
			while(u < n && u <i)
			{ 
				if (Table[u] && u > max)
			  	{
					max = u;
					
					
				}
				u++;	   
			}
		
	}


}




void display()
{
		printf("%d\n", max);
}
void display2()
{

	printf("%d\n", max);
	exit(1);
	
}
