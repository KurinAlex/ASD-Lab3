#include <iostream>
#include <cstdlib>
#include <ctime>

#include "helpers.h"

const int N = 200;

void GenerateArray(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = i + 1;
	}
}

void ShuffleArray(int* array, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		int j = rand() % (i + 1);
		Swap(&array[i], &array[j]);
	}
}

int Compare(int a, int b)
{
	int _a = a;
	int sum_a = 0;
	while (_a > 0)
	{
		sum_a += _a % 10;
		_a /= 10;
	}

	int _b = b;
	int sum_b = 0;
	while (_b > 0)
	{
		sum_b += _b % 10;
		_b /= 10;
	}

	if (sum_a == sum_b)
	{
		return a - b;
	}
	return sum_a - sum_b;
}

void SelectionSort(int* array, int size, int (*compare)(int, int))
{
	for (int i = 0; i < size - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (compare(array[min], array[j]) > 0)
			{
				min = j;
			}
		}
		Swap(&array[i], &array[min]);
	}
}

int main()
{
	srand(time(NULL));

	int* array = new int[N];

	GenerateArray(array, N);
	OutputArray(array, N, "Array");

	ShuffleArray(array, N);
	OutputArray(array, N, "Shuffled array");

	SelectionSort(array, N, Compare);
	OutputArray(array, N, "Sorted by sum of number's digits array");

	std::cin.get();
	return 0;
}