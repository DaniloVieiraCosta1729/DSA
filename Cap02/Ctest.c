#include <stdio.h>

#define SIZE_SOURCE 1000

void swap(int * x, int * y);
void selectionSort(int * list, int size);

int main()
{
	int nums[SIZE_SOURCE] = {0};

	FILE * numsFile = fopen("numbers.bin", "r");
	fread(nums, sizeof(int), SIZE_SOURCE, numsFile);

	for(int i = 0; i < 30; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");

	selectionSort(nums, SIZE_SOURCE);

	for(int i = 0; i < 30; i++)
	{
		printf("%d  ", nums[i]);
	}
	printf("\n");
	

	fclose(numsFile);

	FILE * sortedFile = fopen("csortResult.txt","w");

	for(int i = 0; i < SIZE_SOURCE; i++)
	{
		fprintf(sortedFile, "%d\n", nums[i]);
	}

	fclose(sortedFile);

	return 0;
}

void selectionSort(int * list, int size)
{
	int j = 0;
	for(int i = 0; i < size - 1; i++)
	{
		j = i + 1;
		while((j > 0) && list[j - 1] > list[j])
		{
			swap(list + (j - 1), list + j);
			j--;
		}
	}
}

void swap(int * x, int * y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
