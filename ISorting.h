#pragma once
#include "Apartment.h"

enum SortingType
{
	NONE, AREA, ID
};

static const map<int, SortingType> sortingTypeDict = { {1, SortingType::AREA}, {2, SortingType::ID} };

class ISorting
{
public:
	virtual int compare(Apartment, Apartment) = 0;
};

