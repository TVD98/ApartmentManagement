#include "Apartment.h"

Apartment::Apartment(string id, double area, ApartmentType type, string leader, vector<string> members, bool vehicleRegistration, Vehicle *vehicle, double waterPrice)
{
	this->id = id;
	this->area = area;
	this->type = type;
	this->leader = leader;
	this->members = members;
	this->vehicleRegistration = vehicleRegistration;
	this->vehicle = vehicle;
	this->waterPrice = waterPrice;
}

Apartment::Apartment(const Apartment& a)
{
	this->id = a.id;
	this->area = a.area;
	this->type = a.type;
	this->leader = a.leader;
	this->members = a.members;
	this->vehicleRegistration = a.vehicleRegistration;
	this->vehicle = a.vehicle;
	this->waterPrice = a.waterPrice;
}

Apartment::Apartment(string info)
{
	vector<string> elements = Helper::split(info, "\t");
	this->id = elements[0];
	this->area = atof(elements[1].c_str());
	this->type = apartmentTypeDict.find(elements[2])->second;
	this->leader = elements[3];
	this->members = Helper::split(elements[4], ",");
	this->vehicleRegistration = registrationDict.find(elements[5])->second;
	Vehicle* vehicle = NULL;
	if (!elements[6].empty()) {
		vehicle = new Vehicle(elements[6]);
	}
	this->vehicle = vehicle;
	this->waterPrice = atof(elements[7].c_str());
}

Apartment::Apartment()
{
}

string Apartment::toString()
{
	string value = "[Apartment: ";
	value += "id:" + id + ", area:" + to_string(area) + ", aparment type:" + apartmentTypeStrings[type] + ", leader:" + leader
		+ ", members:" + Helper::listToString(members) + ", vehicle register:" + Helper::boolToString(vehicleRegistration);
	if (vehicleRegistration)
		value += ", vehicle:" + vehicle->toString();
	value += ", water price:" + to_string(waterPrice) + "d]";
	return value;
}

string Apartment::toFormatString()
{
	string value = "";
	value += id + "\t" + to_string(area) + "\t" + apartmentTypeStrings[type] + "\t" + leader
		+ "\t" + Helper::arrayToString(members, ",") + "\t" + Helper::boolToString(vehicleRegistration) + "\t";
	if (vehicleRegistration)
		value += vehicle->toFormatString();
	value += "\t" + to_string(waterPrice);
	return value;
}

string Apartment::getBuilding()
{
	vector<string> result = Helper::split(id, ".");
	if (result.size() == 0)
		return "";
	return result[0];
}

int Apartment::getFloor()
{
	vector<string> result = Helper::split(id, ".");
	if (result.size() < 2)
		return 0;
	vector<string> result1 = Helper::split(result[1], "-");
	if (result1.size() == 0)
		return 0;
	return stoi(result1[0]);
}

int Apartment::getApartmentNumber()
{
	vector<string> result = Helper::split(id, ".");
	if (result.size() < 2)
		return 0;
	vector<string> result1 = Helper::split(result[1], "-");
	if (result1.size() < 2)
		return 0;
	return stoi(result1[1]);
}

bool Apartment::contains(string key)
{
	string tempKey = Helper::toLower(key);
	if (Helper::toLower(id).find(tempKey) != string::npos) {
		return true;
	}
	if (Helper::toLower(leader).find(tempKey) != string::npos) {
		return true;
	}
	if (Helper::toLower(Helper::arrayToString(members, ":")).find(tempKey) != string::npos) {
		return true;
	}
	return false;
}

Apartment::~Apartment()
{
}
