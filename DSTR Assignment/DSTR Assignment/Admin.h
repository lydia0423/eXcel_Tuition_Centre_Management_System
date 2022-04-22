#pragma once
#include <iostream>

using namespace std;

struct Admin {
	string adminId, name, address, tuitionCenterCode, tuitionCenterName, password;
	int ic, phone;
	Admin(string adminId, string name, int ic, string address, int phone, string tuitionCenterCode, string tuitionCenterName, string password);
};

void registerNewAdmin();

void generateNewAdmin();

void displayAllAdmins();

