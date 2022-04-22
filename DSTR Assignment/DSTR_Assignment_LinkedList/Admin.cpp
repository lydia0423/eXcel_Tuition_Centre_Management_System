#include <iostream>
#include <string>
#include "Admin.h"

int sizeOfAdminLinkedList = 0;

Admin *addNewAdmin(string adminId, string name, int ic, string address, int phone, string tuitionCenterCode, string tuitionCenterName, string password) {
	Admin* newAdmin = new Admin;

	newAdmin->adminId = adminId;
	newAdmin->name = name;
	newAdmin->ic = ic;
	newAdmin->address = address;
	newAdmin->phone = phone;
	newAdmin->tuitionCenterCode = tuitionCenterCode;
	newAdmin->tuitionCenterName = tuitionCenterName;
	newAdmin->password = password;
	newAdmin->nextAddress = NULL;
	newAdmin->prevAddress = NULL;

	return newAdmin;
}

void registerNewAdmin(Admin *newAdmin) {
	if (headAdmin == NULL) {
		headAdmin = tailAdmin = newAdmin;
	}
	else {
		newAdmin->prevAddress = tailAdmin;
		tailAdmin->nextAddress = newAdmin;
		tailAdmin = newAdmin;
	}
	::sizeOfAdminLinkedList++;
}

void generateNewAdminRecord() {
	headAdmin = tailAdmin = NULL;

	Admin* newAdmin = addNewAdmin("AD001", "Julie", 123456789, "Serdang", 123456789, "TC001", "Elite", "julie123");
	registerNewAdmin(newAdmin);

	newAdmin = addNewAdmin("AD002", "Jessica", 123456789, "Cheras", 123456789, "TC002", "Super", "jessica123");
	registerNewAdmin(newAdmin);

	newAdmin = addNewAdmin("AD003", "Jenny", 123456789, "Puchong", 123456789, "TC003", "Sunflower", "jenny123");
	registerNewAdmin(newAdmin);
}

void displayAllAdmins() {
	Admin* current = headAdmin;

	cout << "AdminId" << "\t\t" << "AdminName" << "\t\t" << "IC" << "\t\t" << "Address" << "\t\t" << "Phone" << "\t\t"
		<< "TuitionCenterCode" << "\t\t" << "TuitionCenterCode" << endl;
	cout << string(100, '=') << endl;

	while (current != NULL) {
		cout << current->adminId << "\t\t" << current->name << "\t\t" << current->ic << "\t\t" << current->address
			<< "\t\t" << current->phone << "\t\t" << current->tuitionCenterCode << "\t\t" << current->tuitionCenterName << endl;
		current = current->nextAddress;
	}

	cout << endl << "List is ended here!" << endl << endl;
}