#include "Search.h"

Search::Search()
{
	search_name = "";
}

void Search::ExecuteAndCalculateTime(int iterations_number)
{
	clock_t start = clock();
	for (int i = 0; i < iterations_number; i++)
	{
		Execute();
	}
	clock_t end = clock();

	std::cout << "Execution time of " << search_name << " function " << iterations_number
		<< " times: " << (float)(end - start) / CLOCKS_PER_SEC << " seconds\n";
}