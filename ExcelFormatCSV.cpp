#include "ExcelFormatCSV.h"

vector<string> ExcelFormatCSV::readFile(string link)
{
	locale loc(locale(), new std::codecvt_utf8<char>);
	vector<string> data = vector<string>();
	string temp = "";
	fstream inData;
	try {
		inData.open(link, ios::in);
		inData.imbue(loc);
		getline(inData, temp); // doc theo dong, 
		while (temp != "") {
			replace(temp.begin(), temp.end(), ',', '\t');
			replace(temp.begin(), temp.end(), ';', ',');
			data.push_back(temp);
			getline(inData, temp);
		}
		inData.close();
		return data;
	}
	catch (exception e) {
		cout << "Error";
		return data;
	}
}

bool ExcelFormatCSV::writeFile(string link, vector<string> input, vector<string> columnsName)
{
	locale loc(std::locale(), new std::codecvt_utf8<char>);
	fstream outData;
	try {
		outData.open(link, ios::out);
		outData.imbue(loc);
		if (columnsName.size() > 0) { // kiem tra xem co tieu de cho tung cot Excel k.
			outData << Helper::arrayToString(columnsName, ",") << endl;
		}
		for (int i = 0; i < input.size(); i++) {
			string temp = input[i];
			replace(temp.begin(), temp.end(), ',', ';');
			replace(temp.begin(), temp.end(), '\t', ',');
			outData << temp << endl;
		}
		outData.close();
	}
	catch (exception e) {
		return false;
	}
	return true;
}
