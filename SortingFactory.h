#pragma once
#include "IndexSorting.h"
#include "AreaSorting.h"

class SortingFactory
{
public:
	static ISorting* sortingFromType(SortingType type) {
		switch (type)
		{
		case AREA:
			return new AreaSorting();
		case ID:
			return new IndexSorting();
		default:
			return new AreaSorting();
		}
	}

	static ISorting* sortingFromInt(int selection) {
		switch (selection)
		{
		case 1:
			return new AreaSorting();
		case 2:
			return new IndexSorting();
		default:
			return new AreaSorting();
		}
	}
};

