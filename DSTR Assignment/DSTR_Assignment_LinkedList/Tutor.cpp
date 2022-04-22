#include <iostream>
#include <string>
#include "Tutor.h"

int sizeOfTutorLinkedList = 0;

Tutor* addNewTutor(string tutorId, string name, int ic, string fieldOfStudy, string address, int phone, string dateJoined, string dateTerminated,
	string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, string password,
	double hourlyPayRate, double experience, int rating) {
	Tutor* newTutor = new Tutor;

	newTutor->tutorId = tutorId;
	newTutor->name = name;
	newTutor->ic = ic;
	newTutor->fieldOfStudy = fieldOfStudy;
	newTutor->address = address;
	newTutor->phone = phone;
	newTutor->dateJoined = dateJoined;
	newTutor->dateTerminated = dateTerminated;
	newTutor->tuitionCenterCode = tuitionCenterCode;
	newTutor->tuitionCenterName = tuitionCenterName;
	newTutor->subjectCode = subjectCode;
	newTutor->subjectName = subjectName;
	newTutor->password = password;
	newTutor->hourlyPayRate = hourlyPayRate;
	newTutor->experience = experience;
	newTutor->rating = rating;
	newTutor->nextAddress = NULL;
	newTutor->prevAddress = NULL;

	return newTutor;
}

// Ask the user to key in the tutor details
// void registerNewTutor(){
//     cout << "Please enter the following details to register a new tutor." << endl;
//     cout << string(20, '=') << endl;

//     cout << "Tutor Id : ";
//     getline(cin, tutorId);
//     cout << "Tutor Name : ";
//     getline(cin, name);
//     cout << "IC : ";
//     cin >> ic;
//     cout << "Field of study : ";
//     getline(cin, fieldOfStudy);
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     cout << "Address : ";
//     getline(cin, address);
//     cout << "Phone Number : ";
//     cin >> phone;
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');
//     cout << "Date Joined : ";
//     getline(cin, dateJoined);
//     cout << "Date Terminated : ";
//     getline(cin, dateTerminated);
//     cout << "Tuition Center Code : ";
//     getline(cin, tuitionCenterCode);
//     cout << "Tuition Center Name : ";
//     getline(cin, tuitionCenterName);
//     cout << "Subject Code : ";
//     getline(cin, subjectCode);
//     cout << "Subject Name : ";
//     getline(cin, subjectName);
//     cout << "Password : ";
//     getline(cin, password);
//     cout << "Hourly Pay Rate : ";
//     cin >> hourlyPayRate;
//     cout << "Experince of teaching : ";
//     cin >> experience;
// }

// Add tutor record into the linked list
void saveTutor(Tutor *newTutor) {
	if (headTutor == NULL) {
		headTutor = tailTutor = newTutor;
	}
	else {
		newTutor->prevAddress = tailTutor;
		tailTutor->nextAddress = newTutor;
		tailTutor = newTutor;
	}
	::sizeOfTutorLinkedList++;
}

// Generate tutor record every time the system is being compiled so the action has been done wouldn't affect it
void generateTutorRecord() {
	headTutor = tailTutor = NULL;
	Tutor* newTutor = addNewTutor("TR001", "James", 123456789, "Biomedical", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 5.0, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR002", "Micheal", 123456789, "Physics", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 5.0, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR003", "Andy", 123456789, "Applied Maths", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 5.0, 10.0, 4);
	saveTutor(newTutor);
}

// Display the records that categorized by location
void displayAllTutors() {
	Tutor *current = headTutor;

	cout << "TutorId" << "\t" << "TutorName" << "\t" << "IC" << "\t" << "FieldOfStudy" << "\t" << "Address" << "\t" << "Phone" << "\t"
		<< "DateJoined" << "\t" << "DateTerminated" << "\t" << "TuitionCenterCode" << "\t" << "TuitionCenterName"
		<< "\t" << "SubjectCode" << "\t" << "SubjectName" << "\t" << "HourlyPayRate" << "\t" << "Experience" << "\t" << "Rating" << endl;
	cout << string(182, '=') << endl;

	while (current != NULL) {
		cout << current->tutorId << "\t\t" << current->name << "\t\t" << current->ic << "\t\t" << current->fieldOfStudy << "\t\t"
			<< current->address << "\t\t" << current->phone << "\t\t" << current->dateJoined << "\t\t" << current->dateTerminated
			<< "\t\t" << current->tuitionCenterCode << "\t\t" << current->tuitionCenterName << "\t\t" << current->subjectCode
			<< "\t\t" << current->subjectName << "\t\t" << current->hourlyPayRate << "\t\t" << current->experience << "\t\t" << current->rating << endl;
		current = current->nextAddress;
	}

	cout << endl << "List is ended here!" << endl << endl;
}

// Modify =tutor record (only telephone number, date terminated, tuition center code and name)
void modifyTutorRecord();

// Search =tutor based on their tutor id
void searchTutorById();

// Search tutor based on the rating given by student
void searchTutorByRating();

// Search tutor based on the subject teaching
void searchTutorBySubject();

// Sort tutor by using tutor id
void sortTutorById();

// Sort tutor by using rating give
void sortTutorByRating();

// Sort tutor based on the hourly pay rate
void sortTutorByHourlyPayRate();

// View profile
void viewProfile();

// Delete the tutor record after 6 months termination (only HR can do it)
void deleteTutorRecord();