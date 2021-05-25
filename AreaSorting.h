#pragma once
#include "ISorting.h"
class AreaSorting :
    public ISorting
{
public:
    int compare(Apartment, Apartment);
};

