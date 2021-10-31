#pragma once
#include <iostream>
#include <ctime>

class Search
{
public:
	Search();

	void ExecuteAndCalculateTime(int iterations_number);
	virtual int Execute() = 0;

public:
	const char* search_name;

protected:
	int* m_array;
	int m_size;
	int m_target;
};