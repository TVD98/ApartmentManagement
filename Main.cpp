#pragma once
#include <iostream>
#include <stdio.h>
#include "AreaSorting.h"
#include "ManagementSystem.h"
#include "ExcelFormatCSV.h"
#include "UIClient.h"

using namespace std;

int main(void) {
	// management system
	ManagementSystem system = ManagementSystem();
	// read file
	system.readFile("input.csv");

	// create apartment list to merger
	Apartment a1 = Apartment("P4.04-02\t49\t1 phong\tTuong\tCuong,Duong\tYes\tMotobike:74321\t90");
	Apartment a2 = Apartment("P4.04-03\t88\t2 phong\tTien\tLoc,Tung\tYes\tMotobike:63721\t65");
	vector<Apartment> listToMerger;
	listToMerger.push_back(a1);
	listToMerger.push_back(a2);

	int selection;
	do {
		selection = UIClient::mainMenu();
		switch (selection)
		{
			// sap xep
		case 1:
		{
			// chon tieu chi sap xep
			int selectionSortingType = UIClient::selectionSortingType();
			// chon kieu sap xep
			int selectionOrderType = UIClient::selectionOrderType();
			// sap xep
			SortingType sortingType = sortingTypeDict.find(selectionSortingType)->second;
			OrderType orderType = orderTypeDict.find(selectionOrderType)->second;
			system.selectionSort(sortingType, orderType);
			// in danh sach can ho da sap xep
			cout << "Danh sach sau khi sap xep:" << endl;
			cout << system.toString() << endl;
		}
		break;
		// them can ho moi
		case 2:
		{
			string info = UIClient::enteringApartment();
			system.add(Apartment(info));
			cout << "Danh sach sau them can ho:" << endl;
			cout << system.toString() << endl;
		}
		break;
		// xoa can ho theo tu khoa
		case 3:
		{
			cout << "Xoa can ho theo tu khoa:" << endl;
			string key = UIClient::enteringString("Nhap tu khoa");
			int count = system.remove(key);
			cout << "Da xoa " + to_string(count) + " can ho. Danh sach sau khi xoa:" << endl;
			cout << system.toString() << endl;
		}
		break;
		// Lay thong tin can ho theo tu khoa
		case 4:
		{
			cout << "Lay thong tin can ho theo tu khoa" << endl;
			string key = UIClient::enteringString("Nhap tu khoa");
			vector<Apartment> apartments = system.search(key);
			cout << "Thong tin cua " + to_string(apartments.size()) + " can ho" << endl;
			for (Apartment item : apartments) {
				cout << item.toString() << endl;
			}
		}
		break;
		// merger
		case 5:
		{
			cout << "Merger 1 danh sach can ho moi vao he thong:" << endl;
			// chon tieu chi sap xep
			int selectionSortingType = UIClient::selectionSortingType();
			// chon kieu sap xep
			int selectionOrderType = UIClient::selectionOrderType();
			// merger
			SortingType sortingType = sortingTypeDict.find(selectionSortingType)->second;
			OrderType orderType = orderTypeDict.find(selectionOrderType)->second;
			system.merge(listToMerger, sortingType, orderType);
			cout << "Danh sach can ho sau khi merger:" << endl;
			cout << system.toString() << endl;
		}
		break;
		// xuat file excel
		case 6:
		{
			cout << "Xuat danh sach can ho ra file excel:" << endl;
			string fileName = UIClient::enteringString("Nhap ten file");
			system.writeFile(fileName);
			cout << "Xuat file thanh cong. Vui long kiem tra tep tin." << endl;
		}
		break;
		default:
			break;
		}
	} while (selection != 7);


	return 0;
}