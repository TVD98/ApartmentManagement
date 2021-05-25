#include "AreaSorting.h"

int AreaSorting::compare(Apartment a1, Apartment a2)
{
	if (a1.area > a2.area)
		return 1;
	else if (a1.area < a2.area)
		return -1;
	return 0;
}
