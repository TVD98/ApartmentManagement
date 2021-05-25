#pragma once
#include <string>
#include <stdio.h>
#include <map>
#include "Helper.h"
using namespace std;

enum VehicleType
{
	CAR = 0, MOTOBIKE = 1
};

static const string vehicleTypeStrings[] = { "Car", "Motobike" };
static const map<string, VehicleType> vehicleTypeDict = { {"Car", VehicleType::CAR}, {"Motobike", VehicleType::MOTOBIKE} };

class Vehicle
{
private:
	VehicleType type;
	string licensePlates;
public:
	Vehicle(VehicleType, string);
	Vehicle(string info);
	~Vehicle();
	string toString();
	string toFormatString();
};

