#include <stdio.h>
#include <stdlib.h>

void printAll(int * list, int length);
void swap(int * a, int * b);
int selectionSort(int * list, int length);

int main(int size, char * arguments[])
{
	if(size < 2)
	{
		printf("Usage: %s <number1, number2, ...>\n", arguments[0]);
		return -1;
	}

	int * numbers = malloc(sizeof(int) * (size - 1));

	for(int i = 0; i < size - 1; i++)
	{
		*(numbers + i) = atoi(arguments[i + 1]);
	}

	printAll(numbers, size - 1);

	printf("After sorting:\n");
 	int totalSwaps = selectionSort(numbers, size - 1);
	printAll(numbers, size - 1);
	printf("The total number of swaps: %d\n", totalSwaps);

	free(numbers);

	return 0;
}

void printAll(int * list, int length)
{
	printf("Sequence:  ");
	for(int i = 0; i < length; i++)
	{
		printf("%d  ", *(int *)(list + i));
	}

	printf("\n");

}

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int selectionSort(int * list, int length)
{
	int j, moves;
	moves = 0;

	for(int i = 0; i < length - 1; i++)
	{
		j = i + 1;

		while((j > 0) && (list[j - 1] > list[j]))
		{
			swap((list + j - 1), (list + j));
			j--;
			moves++;
		}
	}

	return moves;
}











