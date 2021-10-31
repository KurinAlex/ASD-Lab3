#include <iostream>
#include <cstdlib>
#include <ctime>

#include "helpers.h"

const int N = 1000;
const int MIN_RAND = -2000;
const int MAX_RAND = 2000;

void GenerateSortedArray(int* array, int size, int rand_min, int rand_max)
{
	int range = rand_max - rand_min + 1;

	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % range + rand_min;
	}
}

void BubbleSort(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(&array[j], &array[j + 1]);
			}
		}
	}
}

int LinearSearch(int* array, int size, int target)
{
	for (int i = 0; i < size; i++)
	{
		if (array[i] == target)
		{
			return i;
		}
	}
	return -1;
}

int BinarySearch(int* array, int start_index, int last_index, int target)
{
	if (start_index > last_index)
	{
		return -1;
	}

	int middle_index = (start_index + last_index) / 2;
	if (array[middle_index] > target)
	{
		return BinarySearch(array, start_index, middle_index - 1, target);
	}
	if (array[middle_index] < target)
	{
		return BinarySearch(array, middle_index + 1, last_index, target);
	}
	return middle_index;
}

int main()
{
	srand(time(NULL));

	int* array = new int[N];

	GenerateSortedArray(array, N, MIN_RAND, MAX_RAND);
	OutputArray(array, N, "Array");

	BubbleSort(array, N);
	OutputArray(array, N, "Sorted array");

	int target = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
	std::cout << "Results of searching " << target << " in sorted array:\n";
	std::cout << "Linear search: " << LinearSearch(array, N, target) << '\n';
	std::cout << "Binary search: " << BinarySearch(array, 0, N - 1, target) << '\n';

	std::cin.get();
	return 0;
}