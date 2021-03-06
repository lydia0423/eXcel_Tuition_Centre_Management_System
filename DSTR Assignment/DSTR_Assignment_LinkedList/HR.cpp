#include <iostream>
#include <string>
#include "HR.h"

int sizeOfHRLinkedList = 0;

HumanResourceManager* addNewHR(string hrId, string name, int ic, int phone, string password) {
	HumanResourceManager* newHR = new HumanResourceManager;

	newHR->hrId = hrId;
	newHR->name = name;
	newHR->ic = ic;
	newHR->phone = phone;
	newHR->password = password;
	newHR->nextAddress = NULL;
	newHR->prevAddress = NULL;

	return newHR;
}

void registerNewHR(HumanResourceManager* newHR) {
	if (headHR == NULL) {
		headHR = tailHR = newHR;
	}
	else {
		newHR->prevAddress = tailHR;
		tailHR->nextAddress = newHR;
		tailHR = newHR;
	}
	::sizeOfHRLinkedList++;
}

void generateNewHRRecord() {
	headHR = tailHR = NULL;

	HumanResourceManager* newHR = addNewHR("HR001", "Lisa", 12345678, 12345678, "lisa123");
	registerNewHR(newHR);
}

void displayAllHRs() {
	HumanResourceManager* current = headHR;

	cout << "HR Id" << "\t" << "HRName" << "\t" << "IC" << "\t" << "Phone" << endl;
	cout << string(70, '=') << endl;

	while (current != NULL) {
		cout << current->hrId << "\t\t" << current->name << "\t\t" << current->ic << "\t\t" << current->phone << endl;
		current = current->nextAddress;
	}

	cout << endl << "List is ended here!" << endl << endl;
}

int hrMenu() {
	system("cls");

	int choice = 99;
	while (choice != 0 && choice != -1)
	{
		//menu content
		cout << "\t----------Welcome to HR Menu----------" << endl << endl;
		cout << "The following actions are available for HR : " << endl << endl;
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
		cout << "11. Delete tutor's record by tutor's ID." << endl;
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
		case 11:
			system("cls");
			cout << "choice is 11";
			break;
		default:
			cout << "no choice";
			break;
		}
	}

}
