#pragma once
#include <iostream>
#include <ctime>

class Search
{
public:
	Search(int* array, int size, int target);

	const char* GetSearchName();
	float ExecuteAndCalculateTime(int iterations_number);
	virtual int Execute() = 0;

protected:
	int* m_array;
	int m_size;
	int m_target;
	const char* m_search_name;
};