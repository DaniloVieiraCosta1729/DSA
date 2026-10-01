#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern long random();

int power(int b, int e)
{
	int result = 1;
	for(int i = 0; i < e; i++)
	{
		result *= b;
	}

	return result;
}

int pseudoPrime(int random)
{
	// little fermat`s theorem: if a is natural and p is prime, then a^p is congruent to a module p.
	// let's use this theorem to find a number bigger than the random() that satisfy this condition and then we multiply this number by the random and after we calculate the residue of it's division by 1000. 
	// the reason for that is: the random function, in reality, simply gives me the residue by 1000 of the current microssecond return by the syscall gettimeofday, since each step takes less than 1 micro second (maybe something about 300 or 400 nano seconds per step) the randomness are failing, I mean, the random() is return a sequence of 2 or 3 numbers with the same value and the next is the next natural number... So if i calculate an pseudo prime the code will slow down a bit and the randomnes will comeback.
	
	usleep(1400);

	int p = ((3 * random) % 20) + 1;
	int a = 2; 
	while(1)
	{
		if((power(a, p) % p) == a)
		{
			return p;
		}

		p++;
	}

}

int main(int c, char * args[])
{
	if(c != 2)
	{
		printf("Usage: %s <SIZE_ARRAY_RANDOM>\n", args[0]);
		return -1;
	}

	int size = atoi(args[1]);

	int * randomList = malloc(size * sizeof(int));


	for(int i = 0; i < size; i++)
	{
		int r = random();
		randomList[i] = (r * r * pseudoPrime(r)) % 1000;
	}

	FILE * numbersFile = fopen("numbers.bin", "w");
	fwrite(randomList, sizeof(int), size, numbersFile);

	free(randomList);
	fclose(numbersFile);

	return 0;
}
