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

	adminList[0] = Admin("AD001", "James", 123456789, "Johor", 123456789, "TC001", "Elite", "abc123");
	adminList[1] = Admin("AD002", "Jenny", 123456789, "Johor", 123456789, "TC001", "Elite", "abc123");
	adminList[2] = Admin("AD003", "Rose", 123456789, "Johor", 123456789, "TC001", "Elite", "abc123");
	adminList[3] = Admin("AD004", "Mary", 123456789, "Johor", 123456789, "TC001", "Elite", "abc123");
	adminList[4] = Admin("AD005", "Sam", 123456789, "Johor", 123456789, "TC001", "Elite", "abc123");
	adminList[5] = Admin("HR006", "John", 123456789, "Johor", 123456789, "TC001", "Elite", "abc123");

	return adminList;
}


