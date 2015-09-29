#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT 10000000
typedef enum { FALSE, TRUE} boolean;



int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int w = 0;
	int x = 0;
	int sum = 0;
	int prime_one = 0;
	int prime_two = 0;
	int proved = FALSE;
	int prime_count = 0;
	static char primes_list[COUNT];
	primes_list[0] = TRUE;
	primes_list[1] = TRUE;

	for(i = 2; i < COUNT; i++)
	{
		primes_list[i] = TRUE;
	}

	//sieve of eratosthenes for list of primes
	for(i = 2; i*i < COUNT; i++)
	{
		if( primes_list[i] == TRUE)
		{
			for(j = i; j*i < COUNT; j++)
			{
				primes_list[j*i] = FALSE;
			}
		}
	}

	//count the number of primes
	for(i = 0; i < COUNT; i++)
	{
		if(primes_list[i] == TRUE)
		prime_count++;
	}


	//clean list of primes
	int *primes = malloc(sizeof(int)*prime_count);
	j = 0;
	for(i = 0; i < COUNT; i++)
	{
		if(primes_list[i] == TRUE)
		{
			primes[j] = i;
			j++;
		}
	}

	FILE *fp = fopen("goldbach.txt", "w");
	if(fp == NULL)
	{
		exit(1);
	}

	//goldbach
	for(i= 4; i < COUNT; i = i + 2)
	{
		float ratio = i / (float)COUNT;
		int c = ratio * 25;



		proved = FALSE;
		for(j = 1; j < i && proved == FALSE; j++)
		{
			sum = 0;


			x = 1;
			while( x < i )
			{
				if( primes[x] >= i )
				{
					x--;
					break;
				}
				x++;
			}

			//for(k = 1; k < i && proved == FALSE && k < prime_count; k++)
			for(k = x; k > 0; k--)
			{
				sum = primes[j] + primes[k];
				if(sum == i)
				{
					proved = TRUE;
					//printf("%d = %d + %d\n", i, primes[j], primes[k] );
					//fprintf(fp, "%d%s%d%s%d\n", i, " = ", primes[j], " + ", primes[k]);
				}
			}
		}
		if(proved == FALSE)
		{
			printf("failed to find solution\n");
			free(primes);
			exit(1);
		}

		printf("%3.2f%% [", (ratio*100) );

		for(w = 0; w < c; w++)
		{
			printf("=");
		}

		printf("]\n\033[F\033[J");
		
	}

	printf("%3.2f%% [", 100.00);

	for(w = 0; w < 25; w++)
	{
		printf("=");
	}

	printf("\nGoldbach demonstrated yo\n");
	printf("Output dumped to goldbach.txt\n");
	fclose(fp);
	free(primes);
}
