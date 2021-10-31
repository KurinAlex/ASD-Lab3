#include "BinarySearch.h"

BinarySearch::BinarySearch(int* array, int size, int target)
{
	m_array = array;
	m_size = size;
	m_target = target;
	search_name = "Binary search";
}

int BinarySearch::binary_search(int first_index, int last_index)
{
	if (first_index > last_index)
	{
		return -1;
	}

	int middle_index = (first_index + last_index) / 2;
	if (m_array[middle_index] > m_target)
	{
		return binary_search(first_index, middle_index - 1);
	}
	if (m_array[middle_index] < m_target)
	{
		return binary_search(middle_index + 1, last_index);
	}
	return middle_index;
}

int BinarySearch::Execute()
{
	return binary_search(0, m_size - 1);
}