#include <stdio.h>

#define SIZE_SOURCE 50

int main()
{
	int nums[SIZE_SOURCE] = {0};

	FILE * numsFile = fopen("numbers.bin", "r");
	fread(nums, sizeof(int), SIZE_SOURCE, numsFile);

	for(int i = 0; i < SIZE_SOURCE; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");

	fclose(numsFile);

	return 0;
}
