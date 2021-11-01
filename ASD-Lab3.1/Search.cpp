#include "Search.h"

Search::Search(int* array, int size, int target)
{
	m_array = array;
	m_size = size;
	m_target = target;
	m_search_name = "";
}

const char* Search::GetSearchName()
{
	return m_search_name;
}

float Search::ExecuteAndCalculateTime(int iterations_number)
{
	clock_t start = clock();
	for (int i = 0; i < iterations_number; i++)
	{
		Execute();
	}
	clock_t end = clock();

	return (float)(end - start) / CLOCKS_PER_SEC;
}