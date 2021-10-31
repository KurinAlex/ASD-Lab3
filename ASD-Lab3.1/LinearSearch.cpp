#include "LinearSearch.h"

LinearSearch::LinearSearch(int* array, int size, int target)
{
	m_array = array;
	m_size = size;
	m_target = target;
	search_name = "Linear search";
}

int LinearSearch::Execute()
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_array[i] == m_target)
		{
			return i;
		}
	}
	return -1;
}