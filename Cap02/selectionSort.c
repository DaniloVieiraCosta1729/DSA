#include <stdio.h>
#include <stdlib.h>

void swap(int * x, int * y);
void selectionSort(int * list, size_t length);
void printArray(const int * list, size_t length);
int * createList(size_t length);

int main(int argc, char * arguments[])
{
	if(argc < 2)
	{
		printf("usage: \n%s <number> <number> ...\n", arguments[0]);
		return -1;
	}

	int * numbers = createList(argc - 1);

	for(int i = 1; i < argc; i++)
	{
		numbers[i - 1] = atoi(arguments[i]);
	}

	selectionSort(numbers, argc - 1);

	printArray(numbers, argc - 1);

	free(numbers);

	return 0;
}

void swap(int * x, int * y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void selectionSort(int * list, size_t length)
{
	int min, j;
	for(int i = 0; i < length - 1; i++)
	{
		j = i + 1;
		min = i;
		for(j; j < length; j++)
		{
			if(list[j] < list[min])
			{
				min = j;
			}
		}

		swap(&list[min], &list[i]);
	}
}

void printArray(const int * list, size_t length)
{
	for(size_t i = 0; i < length; i++)
	{
		printf("%d\t", list[i]);
	}

	printf("\n");
}

int * createList(size_t length)
{
	int * result = malloc(length * sizeof(int));

	return result;
}








