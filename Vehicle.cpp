#include "Vehicle.h"

Vehicle::Vehicle(VehicleType type, string licensePlates)
{
    this->type = type;
    this->licensePlates = licensePlates;
}

Vehicle::Vehicle(string info)
{
    vector<string> elements = Helper::split(info, ":");
    this->type = vehicleTypeDict.find(elements[0])->second;
    this->licensePlates = elements[1];
}

Vehicle::~Vehicle()
{
}

string Vehicle::toString()
{
    return "[" + toFormatString() + "]";
}

string Vehicle::toFormatString()
{
    return vehicleTypeStrings[type] + ":" + licensePlates;
}
