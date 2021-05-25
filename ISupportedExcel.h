#pragma once
#include "Helper.h"
#include<fstream>
#include <codecvt>
#include <iostream>
using namespace std;

class ISupportedExcel {
public:
	virtual vector<string> readFile(string link) = 0;
	virtual bool writeFile(string link, vector<string> input, vector<string> columnsName) = 0;
};