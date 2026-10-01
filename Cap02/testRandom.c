#include <stdio.h>

extern long random();

int main()
{
	long rand = random();
	printf("%ld\n", rand);

	return 0;
}
