#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include "Apartment.h"
#include "SortSystem.h"
#include "SortingFactory.h"
#include "SearchSystem.h"
#include "ExcelFormatCSV.h"
using namespace std;

class ManagementSystem
{
private:
	vector<Apartment> apartmentList;
	SortingType sortingType;
	OrderType orderType;

	void add(Apartment newApartment, int index);
	vector<string> toStringList();
public:
	ManagementSystem();
	~ManagementSystem();
	void selectionSort(SortingType sortingType, OrderType orderType);
	void add(Apartment newApartment);
	int remove(string key);
	vector<Apartment> search(string key);
	void merge(vector<Apartment> newList, SortingType sortingType, OrderType orderType);
	void readFile(string link);
	bool writeFile(string fileName);
	string toString();
	
};

