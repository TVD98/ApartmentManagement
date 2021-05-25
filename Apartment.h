#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <list>
#include <map>
#include "Vehicle.h"
#include "Helper.h"
using namespace std;

enum ApartmentType
{
	ONE_BEDROOM = 0, TWO_BEDROOMS = 1, THREE_BEDROOMS = 2
};


static const string apartmentTypeStrings[] = { "1 phong", "2 phong", "3 phong" };
static const map<string, ApartmentType> apartmentTypeDict = { {"1 phong", ApartmentType::ONE_BEDROOM}, {"2 phong", ApartmentType::TWO_BEDROOMS},
{"3 phong", ApartmentType::THREE_BEDROOMS} };
static const map<string, bool> registrationDict = { {"Yes", true}, {"No", false} };

class Apartment
{
public:
	string id;
	double area;
	ApartmentType type;
	string leader;
	vector<string> members;
	bool vehicleRegistration;
	Vehicle *vehicle;
	double waterPrice;

	Apartment(string, double, ApartmentType, string, vector<string>, bool, Vehicle*, double);
	Apartment(const Apartment& a);
	Apartment(string info);
	Apartment();
	string toString();
	string toFormatString();
	string getBuilding();
	int getFloor();
	int getApartmentNumber();
	bool contains(string key);
	~Apartment();
};

