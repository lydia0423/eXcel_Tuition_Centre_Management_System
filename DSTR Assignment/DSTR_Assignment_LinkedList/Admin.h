#pragma once
#include <iostream>
#define ADMIN_H 

using namespace std;

struct Admin {
	string adminId, name, address, tuitionCenterCode, tuitionCenterName, password;
	int ic, phone;
	Admin* nextAddress;
	Admin* prevAddress;
}*headAdmin, *tailAdmin;

Admin* addNewAdmin(string adminId, string name, int ic, string address, int phone, string tuitionCenterCode, string tuitionCenterName, string password);

void registerNewAdmin(Admin* newAdmin);

void generateNewAdmin();

void displayAllAdmins();

int adminMenu();