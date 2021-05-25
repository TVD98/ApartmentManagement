#pragma once
#include "Helper.h"
#include <iostream>
using namespace std;
class UIClient {
public:
	static string enteringApartment() {
		string info;
		vector<string> columnsName = { "So can ho", "Dien tich", "Loai can ho (1, 2, hoac 3 phong)", "Ten chu ho", 
			"Ten cac thanh vien (ten cach nhau dau ',')", "Dang ki gui xe (dien 'Yes' hoac 'No')", 
			"Thong tin xe ('Car:1234', khong dang ki gui xe thi de trong)", "Tien nuoc" };
		cout << "Nhap thong tin cua can ho:" << endl;
		for (string item : columnsName) {
			info += enteringString(item) + "\t";
		}
		info.pop_back();
		return info;
	}

	static string enteringString(string columnName) {
		string temp = "";
		cout << columnName << ": ";
		getline(cin, temp);
		return Helper::trim(temp);
	}

	static int selectionSortingType() {
		string title = "Chon tieu chi sap xep";
		vector<string> columnsName = { "Theo dien tich", "Theo so can ho" };
		return selectionMenu(title, columnsName);
	}

	static int selectionOrderType() {
		string title = "Chon kieu sap xep";
		vector<string> columnsName = { "Tang dan", "Giam dan" };
		return selectionMenu(title, columnsName);
	}

	static void selectionMenuForm(string title, vector<string> arr) {
		cout << title << endl;
		for (int i = 0; i < arr.size(); i++) {
			cout << "\t" << (i + 1) << " " << arr[i] << "." << endl;
		}
	}

	static int selectionMenu(string title, vector<string> columnsName) {
		string temp = "";
		selectionMenuForm(title, columnsName);
		temp = enteringString("Nhap lua chon");
		return atoi(temp.c_str());
	}

	static int mainMenu() {
		string title = "Tac vu chinh cua chuong trinh";
		vector<string> columnsName = { "Sap xep", "Them can ho", "Xoa cac can ho theo tu khoa", 
			"Lay thong tin cac can ho theo tu khoa", "Ghep danh sach can ho moi", "Xuat danh sach ra file Excel", 
			"Thoat" };
		return selectionMenu(title, columnsName);
	}
};