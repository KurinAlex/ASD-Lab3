#pragma once
#include "Search.h"

class BinarySearch : public Search
{
public:
	BinarySearch(int* array, int size, int target);

	virtual int Execute() override;

private:
	int binary_search(int first_index, int last_index);
};