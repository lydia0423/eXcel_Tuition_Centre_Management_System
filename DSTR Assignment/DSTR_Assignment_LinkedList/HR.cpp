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

void hrMenu() {
	cout << "----------Welcome to Admin Menu----------" << endl;
	cout << "The following actions are available for administrator : " << endl;

	cout << "Display all tutors' record";
	cout << "Display all tutors' record according to tutor's Location";
	cout << "Search tutor's record by tutor's ID";
	cout << "Search tutor's record by tutor's Overall Performance";
	cout << "Search tutor's record by tutor's Teaching Subject";
	cout << "Sort and display all tutor's record by tutor's ID";
	cout << "Sort and display all tutor's record by tutor's Overall Performance";
	cout << "Sort and display all tutor's record by tutor's Hourly Pay Rate";
	cout << "Add a record for new tutor";
	cout << "Modify tutor's record by tutor's ID";
	cout << "Delete tutor's record by tutor's ID";

	//void viewProfile()

	cout << "Please enter correct number according to the followingselect the function you want to use";
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
