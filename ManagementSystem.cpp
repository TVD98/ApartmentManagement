#include "ManagementSystem.h"

ManagementSystem::ManagementSystem()
{
	sortingType = SortingType::NONE;
	orderType = OrderType::ASC;
}

ManagementSystem::~ManagementSystem()
{
}

void ManagementSystem::add(Apartment newApartment)
{
	// danh sach chua sap xep thi them vao cuoi danh sach
	if (sortingType == SortingType::NONE) {
		apartmentList.push_back(newApartment);
		return;
	}
	// tim vi tri de them phan tu moi
	ISorting* sorting = SortingFactory::sortingFromType(sortingType);
	int indexToAdd = SearchSystem::search(apartmentList, 0, apartmentList.size() - 1, newApartment, sorting);
	this->add(newApartment, indexToAdd);
}

void ManagementSystem::add(Apartment newApartment, int index)
{
	apartmentList.insert(apartmentList.begin() + index, newApartment);
}

vector<string> ManagementSystem::toStringList()
{
	vector<string> result;
	for (Apartment a : apartmentList) {
		result.push_back(a.toFormatString());
	}
	return result;
}

int ManagementSystem::remove(string key)
{
	vector<int> indexsToRemove = SearchSystem::search(apartmentList, key);
	for (int i = 0; i < indexsToRemove.size(); i++)
	{
		apartmentList.erase(apartmentList.begin() + indexsToRemove[i] - i);
	}
	return indexsToRemove.size();
}

vector<Apartment> ManagementSystem::search(string key)
{
	vector<Apartment> apartments;
	vector<int> indexsBySearch = SearchSystem::search(apartmentList, key);
	for (int i = 0; i < indexsBySearch.size(); i++)
	{
		apartments.push_back(apartmentList[indexsBySearch[i]]);
	}
	return apartments;
}

void ManagementSystem::merge(vector<Apartment> newList, SortingType sortingType, OrderType orderType)
{
	// ghep mang moi vo cuoi mang cu
	apartmentList.insert(apartmentList.end(), newList.begin(), newList.end());
	ISorting* sorting = SortingFactory::sortingFromType(sortingType);
	SortSystem::mergeSort(apartmentList, 0, apartmentList.size() - 1, sorting, orderType);
}

void ManagementSystem::readFile(string link)
{
	ISupportedExcel* excel = new ExcelFormatCSV();
	vector<string> result = excel->readFile(link);
	result.erase(result.begin());
	for (string info : result) {
		apartmentList.push_back(Apartment(info));
	}
}

bool ManagementSystem::writeFile(string fileName)
{
	string link = fileName + ".csv";
	vector<string> columnsName = { "So can ho", "Dien tich", "Loai can ho", "Chu ho", "Thanh vien",
	"Gui xe", "Thong tin xe", "Tien nuoc" };
	ISupportedExcel* excel = new ExcelFormatCSV();
	vector<string> input = toStringList();
	return excel->writeFile(link, input, columnsName);
}

string ManagementSystem::toString()
{
	string result = "";
	for (int i = 0; i < apartmentList.size(); i++) {
		result += "[" + to_string(i) + "]:" + apartmentList[i].toString() + "\n";
	}
	return result;
}

void ManagementSystem::selectionSort(SortingType sortingType, OrderType orderType)
{
	if (this->sortingType == sortingType && this->orderType == orderType)
		return;
	ISorting* sorting = SortingFactory::sortingFromType(sortingType);
	SortSystem::selectionSort(apartmentList, sorting, orderType);
	this->sortingType = sortingType;
	this->orderType = orderType;
}
