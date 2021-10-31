#include "BinarySearch.h"

BinarySearch::BinarySearch(int* array, int size, int target) : Search(array, size, target)
{
	m_search_name = "Binary search";
}

int BinarySearch::binarySearch(int first_index, int last_index)
{
	if (first_index > last_index)
	{
		return -1;
	}

	int middle_index = (first_index + last_index) / 2;
	if (m_array[middle_index] > m_target)
	{
		return binarySearch(first_index, middle_index - 1);
	}
	if (m_array[middle_index] < m_target)
	{
		return binarySearch(middle_index + 1, last_index);
	}
	return middle_index;
}

int BinarySearch::Execute()
{
	return binarySearch(0, m_size - 1);
}