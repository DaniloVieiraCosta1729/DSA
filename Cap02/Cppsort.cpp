#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define SIZE 1000

void selectionSort(std::vector<int>& list, int size)
{
	int j;
	for(int i = 0; i < size - 1; i++)
	{
		j = i + 1;
		while((j > 0) && (list[j - 1] > list[j]))
		{
			std::swap(list[j-1], list[j]);
			j--;
		}
	}
}

int main()
{
	std::ifstream numsFile("numbers.bin", std::ios::binary);

	std::vector<int> nums(1000);

	numsFile.read(reinterpret_cast<char *>(nums.data()), SIZE * sizeof(int));

	selectionSort(nums, SIZE);

	for(int i = 0; i < 30; i++)
	{
		std::cout << nums[i] << std::endl;
	}

	return 0;
}
