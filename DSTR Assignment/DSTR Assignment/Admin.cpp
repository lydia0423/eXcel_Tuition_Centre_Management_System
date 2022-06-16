#include <iostream>
#include <string>
#include "Admin.h"
#include "Tutor.h"

Admin::Admin() {}

Admin::Admin(string adminId, string name, int ic, string address, int phone, string tuitionCenterCode, string tuitionCenterName, string password)
{
	this->adminId = adminId;
	this->name = name;
	this->address = address;
	this->phone = phone;
	this->tuitionCenterCode = tuitionCenterCode;
	this->tuitionCenterName = tuitionCenterName;
	this->password = password;
}

Admin* generateNewAdmin() {
	Admin* adminList = new Admin[6];

	adminList[0] = Admin("AD001", "James", 123456789, "Penang", 45643211, "TC001", "Elite", "abc123");
	adminList[1] = Admin("AD002", "Jenny", 453345344, "Johor", 1236789, "TC002", "Sunny", "abc123");
	adminList[2] = Admin("AD003", "Rose", 323257874, "Kuala Lumpur", 4534123, "TC003", "Future", "abc123");
	adminList[3] = Admin("AD004", "Mary", 123757788, "Malacca", 12123123, "TC004", "Better", "abc123");
	adminList[4] = Admin("AD005", "Sam", 764564562, "Perlis", 554456, "TC005", "Study", "abc123");
	adminList[5] = Admin("HR001", "John", 985545644, "Penang", 54645645, "TC001", "Elite", "abc123");

	return adminList;
}


