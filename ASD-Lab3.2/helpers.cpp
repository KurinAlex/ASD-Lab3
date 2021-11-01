#include <iostream>

#include "helpers.h"

void OutputArray(int* array, int size, const char* array_name)
{
	std::cout << array_name << ":\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n";
}

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}