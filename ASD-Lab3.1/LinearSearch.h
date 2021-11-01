#pragma once
#include "Search.h"

class LinearSearch : public Search
{
public:
	LinearSearch(int* array, int size, int target);

	virtual int Execute() override;
};