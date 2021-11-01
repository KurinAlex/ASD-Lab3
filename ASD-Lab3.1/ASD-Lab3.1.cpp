#include <iostream>
#include <cstdlib>
#include <ctime>

#include "LinearSearch.h"
#include "BinarySearch.h"
#include "helpers.h"

const int N = 1000;
const int MIN_RAND = -2000;
const int MAX_RAND = 2000;
const int ITERATIONS_NUMBER = 100000;

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

int main()
{
	srand(time(NULL));

	int* array = new int[N];

	GenerateSortedArray(array, N, MIN_RAND, MAX_RAND);
	OutputArray(array, N, "Array");

	BubbleSort(array, N);
	OutputArray(array, N, "Sorted array");

	int target = rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND;
	Search* searches[] = { new LinearSearch(array, N, target), new BinarySearch(array, N, target) };

	std::cout << "Searching for " << target << " in array:\n\n";
	for (Search* search : searches)
	{
		std::cout << search->GetSearchName() << ":\n";
		std::cout << "- result: " << search->Execute() << '\n';
		std::cout << "- time of " << ITERATIONS_NUMBER << " executions: "
			<< search->ExecuteAndCalculateTime(ITERATIONS_NUMBER) << " sec\n\n";
	}

	std::cin.get();
	return 0;
}