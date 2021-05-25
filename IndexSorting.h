#pragma once
#include "ISorting.h"
class IndexSorting :
    public ISorting
{
public:
    int compare(Apartment, Apartment);
};

