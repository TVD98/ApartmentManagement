#pragma once
#include "Apartment.h"
#include "ISorting.h"
using namespace std;

class SearchSystem {
public:
    // tim kiem vi tri de them phan tu
    static int search(vector<Apartment> array, int left, int right, Apartment newApartment, ISorting* sorting)
    {
        if (right >= left) {
            int mid = left + (right - left) / 2;

            // If the element is present at the middle
            // itself
            if (sorting->compare(array[mid], newApartment) == 0)
                return mid;

            // If element is smaller than mid, then
            // it can only be present in left subarray
            if (sorting->compare(array[mid], newApartment) == 1)
                return search(array, left, mid - 1, newApartment, sorting);

            // Else the element can only be present
            // in right subarray
            return search(array, mid + 1, right, newApartment, sorting);
        }

        // We reach here when element is not
        // present in array
        return right + 1;
    }

    // tim kiem vi tri cac phan tu theo tu khoa
    static vector<int> search(vector<Apartment> array, string key) {
        vector<int> indexs;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i].contains(key)) {
                indexs.push_back(i);
            }
        }
        return indexs;
    }
};
