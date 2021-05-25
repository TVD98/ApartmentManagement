#include "IndexSorting.h"

int IndexSorting::compare(Apartment a1, Apartment a2)
{
    int compareByBuilding = a1.getBuilding().compare(a2.getBuilding());
    if (compareByBuilding == 0) {
        int compareByFloor = a1.getFloor() - a2.getFloor();
        if (compareByFloor == 0) {
            int compareByNumber = a1.getApartmentNumber() - a2.getApartmentNumber();
            if (compareByNumber < 0)
                return -1;
            return 1;
        }
        if (compareByFloor < 0)
            return -1;
        return 1;
    }
    return compareByBuilding;
}
