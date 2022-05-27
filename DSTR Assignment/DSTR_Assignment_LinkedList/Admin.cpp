#include <iostream>
#include <string>
#include "Admin.h"

int sizeOfAdminLinkedList = 0;

int adminMenu() {
	system("cls");
	int choice = 99;

	while (choice != 0 && choice != -1)
	{
		//menu content
		cout << "\t----------Welcome to Admin Menu----------" << endl << endl;
		cout << "The following actions are available for administrator : " << endl << endl;
		//function introduction
		cout << "1. Display all tutors' record." << endl;
		cout << "2. Display all tutors' record according to tutor's Location." << endl;
		cout << "3. Search tutor's record by tutor's ID." << endl;
		cout << "4. Search tutor's record by tutor's Overall Performance." << endl;
		cout << "5. Search tutor's record by tutor's Teaching Subject." << endl;
		cout << "6. Sort and display all tutor's record by tutor's ID." << endl;
		cout << "7. Sort and display all tutor's record by tutor's Overall Performance." << endl;
		cout << "8. Sort and display all tutor's record by tutor's Hourly Pay Rate." << endl;
		cout << "9. Add a record for new tutor." << endl;
		cout << "10. Modify tutor's record by tutor's ID." << endl;
		cout << "0. Logout and Go back to Login interface." << endl;
		cout << "-1. Quit the whole system." << endl;
		//ask choice
		cout << endl << "Please enter correct number to select what action do you want : ";

		//read choice from user
		cin >> choice;
		//check whether the user's input is valid, until get expected input
		while (cin.fail() || choice < -1 || choice > 10) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Please enter a correct number to select what action do you want : ";
			cin >> choice;
		}

		//execute chosen function according to user's choice
		switch (choice)
		{
		case -1:
			system("cls");
			cout << "Quiting the system, thank you for using!" << endl;
			return choice;
		case 0:
			system("cls");
			return choice;
		case 1:
			system("cls");
			cout << "choice is 1";
			//displayAllTutors();
			break;
		case 2:
			system("cls");
			cout << "choice is 2";
			break;
		case 3:
			system("cls");
			cout << "choice is 3";
			break;
		case 4:
			system("cls");
			cout << "choice is 4";
			break;
		case 5:
			system("cls");
			cout << "choice is 5";
			break;
		case 6:
			system("cls");
			cout << "choice is 6";
			break;
		case 7:
			system("cls");
			cout << "choice is 7";
			break;
		case 8:
			system("cls");
			cout << "choice is 8";
			break;
		case 9:
			system("cls");
			cout << "choice is 9";
			break;
		case 10:
			system("cls");
			cout << "choice is 10";
			break;
		default:
			cout << "no choice";
			break;
		}
	}
}

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