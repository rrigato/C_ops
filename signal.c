#include "stdio.h"
#include "signal.h"
#include "stdlib.h"
#include "math.h"
#define n 100000000
void sieve();
void display(int);
void display2(int);
int main (int argc, char * argv[])
{
	printf("%d\n", n);
	int Continue = 1;
	signal(SIGINT,SIG_IGN);
	signal(SIGINT, display);
	signal(SIGQUIT, display2);
	sieve();
	
	return 0;
}

void sieve ()
{
	int table[n];
	int z = 0;
	for (; z< n; z++)
		table[z] = 1;
	int i=2;
	int j = 0;
	int k =0;
	int n_square = sqrt(n);
	for (; i < n_square; i++)
	{
		if (table[i])
		{
			j = i*i;
			do
			{
				table[j] = 0;
				
				k++;
				
				j = (i*i)+(i*k);
			}while(j<n);
		}
	}
	
}

void display(int signum)
{
	if (signum ==2)
	printf("It worked\n");
}
void display2(int signum)
{
	if (signum==3)
	{
	printf("It worked\n");
	exit(1);
	}
}
