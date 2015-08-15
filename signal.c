
#include "stdio.h"

#define n 100000000
void sieve();
int main (int argc, char * argv[])
{
	printf("%d\n", n);
	return 0;
}

void sieve ()
{
	int table[n];
	int z = 0;
	for (; z< n; z++)
		table[n] = 1;
	int i=2;
	int j = 0;
	int k =0;
	int n_square = (*int)sqrt((*double)n);
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
