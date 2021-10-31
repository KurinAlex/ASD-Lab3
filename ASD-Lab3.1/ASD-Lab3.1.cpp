#include <iostream>
#include <cstdlib>
#include <ctime>

#include "LinearSearch.h"
#include "BinarySearch.h"
#include "helpers.h"

const int N = 1000;
const int MIN_RAND = -2000;
const int MAX_RAND = 2000;
const int ITERATIONS_NUMBER = 10000;

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
	LinearSearch* linear_search = new LinearSearch(array, N, target);
	BinarySearch* binary_search = new BinarySearch(array, N, target);

	std::cout << "Searching " << target << " in array:\n";
	std::cout << linear_search->search_name << ": " << linear_search->Execute() << '\n';
	std::cout << binary_search->search_name << ": " << binary_search->Execute() << '\n';
	std::cout << '\n';

	std::cout << "Execution time comparison:\n";
	linear_search->ExecuteAndCalculateTime(ITERATIONS_NUMBER);
	binary_search->ExecuteAndCalculateTime(ITERATIONS_NUMBER);

	std::cin.get();
	return 0;
}