#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include <sstream> 
#include <chrono>
#include "Tutor.h"

Tutor* headTutor = new Tutor;
Tutor* tailTutor = new Tutor;

int sizeOfTutorLinkedList = 0;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

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

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

// Ask the user to key in the tutor details
void registerNewTutor(){
	 string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
	 int phone, rating, ic;
	 double hourlyPayRate, experience;

     cout << "Please enter the following details to register a new tutor." << endl;
     cout << string(20, '=') << endl;
		
	 //convert int to string
	 stringstream stream;
	 stream << ::sizeOfTutorLinkedList + 1;
	 string str;
	 stream >> str;

	 if (::sizeOfTutorLinkedList < 10) {
		 tutorId = "TR00" + str;
	 }
	 else {
		 tutorId = "TR0" + str;
	 }
	 cout << "Tutor Id : " << tutorId << endl;
     cout << "Tutor Name : ";
	 cin >> name;
     //getline(cin, name);
     cout << "IC : ";
	 while (!(cin >> ic)) {
		 cout << "IC : ";
		 cin.clear();
		 cin.ignore(22, '\n');
	 }
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Field of study : ";
	 cin >> fieldOfStudy;
     //getline(cin, fieldOfStudy);
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Address : ";
     getline(cin, address);
     cout << "Phone Number : ";
	 while (!(cin >> phone)) {
		 cout << "Phone Number : ";
		 cin.clear();
		 cin.ignore(22, '\n');
	 }
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Tuition Center Code : ";
     getline(cin, tuitionCenterCode);
     cout << "Tuition Center Name : ";
     getline(cin, tuitionCenterName);
     cout << "Subject Code : ";
     getline(cin, subjectCode);
     cout << "Subject Name : ";
     getline(cin, subjectName);
     cout << "Password : ";
     getline(cin, password);
     cout << "Hourly Pay Rate : ";
	 while (!(cin >> hourlyPayRate)) {
		 cout << "Hourly Pay Rate : ";
		 cin.clear();
		 cin.ignore(22, '\n');
	 }
     cout << "Experince of teaching : ";
	 while (!(cin >> experience)) {
		 cout << "Experince of teaching : ";
		 cin.clear();
		 cin.ignore(22, '\n');
	 }
	 cout << "Rating : ";
	 while (!(cin >> rating)) {
		 cout << "Rating : ";
		 cin.clear();
		 cin.ignore(22, '\n');
	 }

	 //get current date
	 char currDate[10];
	 time_t t = time(NULL);
	 struct tm tm = *localtime(&t);
	 sprintf(currDate, "%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	 dateJoined = convertToString(currDate, 10);

	 Tutor* newTutor = addNewTutor(tutorId, name, ic, fieldOfStudy, address, phone, dateJoined, "NULL", tuitionCenterCode, tuitionCenterName, subjectCode, 
		 subjectName, password, hourlyPayRate, experience, rating);
	 saveTutor(newTutor);

	 cout << endl << "Added new tutor successfully" << endl << endl;
 }

// Generate tutor record every time the system is being compiled so the action has been done wouldn't affect it
void generateTutorRecord() {
	headTutor = tailTutor = NULL;
	Tutor* newTutor;
	
	newTutor = addNewTutor("TR001", "James", 123456789, "Biomedical", "Johor", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 4.0, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR002", "Micheal", 123456789, "Physics", "Kuala Lumpur", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 5.5, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR003", "Andy", 123456789, "Applied Maths", "Kuala Lumpur", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 9.0, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR004", "Julie", 123456789, "Applied Maths", "Penang", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 8.7, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR005", "Andrew", 123456789, "Applied Maths", "Penang", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 12.4, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR006", "John", 123456789, "Applied Maths", "Penang", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 12.4, 10.0, 4);
	saveTutor(newTutor);

	newTutor = addNewTutor("TR076", "Jessic", 123456789, "Applied Maths", "Penang", 123456789, "12/03/2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 12.4, 10.0, 4);
	saveTutor(newTutor);
}

void displayAllTutors() {
	//display records by page
	Tutor *current = headTutor;
	int chunk = 3; //prefer row for display per page
	int totalPage = 0;
	if (sizeOfTutorLinkedList <= 3) {
		totalPage = 1;
	}
	else if (sizeOfTutorLinkedList > 3) {
		totalPage = (sizeOfTutorLinkedList / chunk) + 1;
	}
	else {
		totalPage = (sizeOfTutorLinkedList / chunk);
	}

	int page = 1;
	int choose = 0;
	int length = 0;
	do {
		int tmpRow = (page*chunk) - chunk; //start index
		if (page != totalPage) {
			length = page * chunk;
		}
		else {
			length = sizeOfTutorLinkedList;
		}

		for (int i = tmpRow; i < length; i++) {
			cout << "TutorId" << "\t\t" << " : " << current->tutorId << endl;
			cout << "TutorName" << "\t" << " : " << current->name << endl;
			cout << "IC" << "\t\t" << " : " << current->ic << endl;
			cout << "FieldOfStudy" << "\t" << " : " << current->fieldOfStudy << endl;
			cout << "Address" << "\t\t" << " : " << current->address << endl;
			cout << "Phone" << "\t\t" << " : " << current->phone << endl;
			cout << "DateJoined" << "\t" << " : " << current->dateJoined << endl;
			cout << "DateTerminated" << "\t" << " : " << current->dateTerminated << endl;
			cout << "TuitionCenterCode" << ": " << current->tuitionCenterCode << endl;
			cout << "TuitionCenterName" << ": " << current->tuitionCenterName << endl;
			cout << "SubjectCode" << "\t" << " : " << current->subjectCode << endl;
			cout << "SubjectName" << "\t" << " : " << current->subjectName << endl;
			cout << "HourlyPayRate" << "\t" << " : " << current->hourlyPayRate << endl;
			cout << "Experience" << "\t" << " : " << current->experience << endl;
			cout << "Rating" << "\t\t" << " : " << current->rating << endl;
			cout << string(50, '=') << endl;
			current = current->nextAddress;
		}

		if (totalPage == 1) {
			cout << "You have reached end of the page." << endl;
			return;
		}
		else {
			cout << "1. Next " << endl;
			if (page != 1) {
				cout << "2. Previous " << endl;
				cout << "3. First Page " << endl;
				cout << "4. Last Page " << endl;
			}
			cout << "0. Back to Menu " << endl;

			cout << "Enter your choice : ";
			cin >> choose;
			if (page == 1) {
				//check whether the user's input is valid, until get expected input
				while (cin.fail() || choose < -1 || choose > 1) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input!" << endl;
					cout << "Enter your choice : ";
					cin >> choose;
				}
			}

			switch (choose) {
			case 0:
				break;
			case 1:
				if (page < totalPage) {
					system("cls");
					page++;
					break;
				}
				else if (page == totalPage) {
					cout << "You have reached end of the page." << endl;
					return;
				}
			case 2:
				if (page >= 1) {
					system("cls");
					page--;
					break;
				}
			case 3:
				system("cls");
				page = 1;
				break;
			case 4:
				system("cls");
				page = totalPage;
				break;
			}
		}
	} while (choose != 0);
}

//function to split nodes of the doubly linked list into 2 halves
void split(Tutor* startNode, Tutor** a, Tutor** b) {
	Tutor* slow = startNode;
	Tutor* fast = startNode->nextAddress;

	while (fast != NULL) {
		fast = fast->nextAddress;
		if (fast != NULL) {
			slow = slow->nextAddress;
			fast = fast->nextAddress;
		}
	}

	*b = slow->nextAddress;
	slow->nextAddress = NULL;
}

//recursive function to merge nodes of two sorted lists into a single sorted list
Tutor* sortTutorByAddress(Tutor* a, Tutor* b) {
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	if (a->address < b->address) {
		a->nextAddress = sortTutorByAddress(a->nextAddress, b);
		a->nextAddress->prevAddress = a;
		a->prevAddress = NULL;
		return a;
	}else {
		b->nextAddress = sortTutorByAddress(a, b->nextAddress);
		b->nextAddress->prevAddress = b;
		b->prevAddress = NULL;
		return b;
	}
}

void mergeSortTutorByAddress(Tutor** startNode) {
	if (*startNode == NULL || (*startNode)->nextAddress == NULL) {
		return;
	}

	//split list into a and b sublist
	Tutor* a = *startNode;
	Tutor* b = NULL;
	split(*startNode, &a, &b);

	//recursively sort the sublists
	mergeSortTutorByAddress(&a);
	mergeSortTutorByAddress(&b);

	//merge the two sorted lists
	*startNode = sortTutorByAddress(a, b);

}

//Display the records that categorized by location
void displayAllTutorsByLocation() {
	auto t1 = high_resolution_clock::now();
	//sort the tutors based on address
	mergeSortTutorByAddress(&headTutor);

	//display records by page
	Tutor *current = headTutor;
	int chunk = 3; //prefer row for display per page
	int totalPage = 0;
	if (sizeOfTutorLinkedList <= 3) {
		totalPage = 1;
	}
	else if (sizeOfTutorLinkedList > 3) {
		totalPage = (sizeOfTutorLinkedList / chunk) + 1;
	}
	else {
		totalPage = (sizeOfTutorLinkedList / chunk);
	}

	int page = 1;
	int choose = 0;
	int length = 0;
	do {
		int tmpRow = (page*chunk) - chunk; //start index
		if (page != totalPage) {
			length = page * chunk;
		}
		else {
			length = sizeOfTutorLinkedList;
		}

		for (int i = tmpRow; i < length; i++) {
			cout << "TutorId" << "\t\t" << " : " << current->tutorId << endl;
			cout << "TutorName" << "\t" << " : " << current->name << endl;
			cout << "IC" << "\t\t" << " : " << current->ic << endl;
			cout << "FieldOfStudy" << "\t" << " : " << current->fieldOfStudy << endl;
			cout << "Address" << "\t\t" << " : " << current->address << endl;
			cout << "Phone" << "\t\t" << " : " << current->phone << endl;
			cout << "DateJoined" << "\t" << " : " << current->dateJoined << endl;
			cout << "DateTerminated" << "\t" << " : " << current->dateTerminated << endl;
			cout << "TuitionCenterCode" << ": " << current->tuitionCenterCode << endl;
			cout << "TuitionCenterName" << ": " << current->tuitionCenterName << endl;
			cout << "SubjectCode" << "\t" << " : " << current->subjectCode << endl;
			cout << "SubjectName" << "\t" << " : " << current->subjectName << endl;
			cout << "HourlyPayRate" << "\t" << " : " << current->hourlyPayRate << endl;
			cout << "Experience" << "\t" << " : " << current->experience << endl;
			cout << "Rating" << "\t\t" << " : " << current->rating << endl;
			cout << string(50, '=') << endl;
			current = current->nextAddress;
		}

		if (totalPage == 1) {
			cout << "You have reached end of the page." << endl;
			return;
		}
		else {
			cout << "1. Next " << endl;
			cout << "2. Previous " << endl;
			cout << "3. First Page " << endl;
			cout << "4. Last Page " << endl;

			cout << "Enter your choice : ";
			cin >> choose;

			switch (choose) {
			case 0:
				break;
			case 1:
				if (page < totalPage) {
					system("cls");
					page++;
					break;
				}
				else if (page == totalPage) {
					cout << endl;
					cout << "You have reached end of the page." << endl << endl;
					auto t2 = high_resolution_clock::now();
					duration<double, std::milli> ms_double = t2 - t1;
					std::cout << "Execution time : " << ms_double.count() << "ms\n";
					system("pause");
					return;
				}
			case 2:
				if (page >= 1) {
					system("cls");
					page--;
					break;
				}
			case 3:
				system("cls");
				page = 1;
				break;
			case 4:
				system("cls");
				page = totalPage;
				break;
			}
		}
	} while (choose != 0);
}



string splitStr(string s, string del) {
	int start = 0;
	int end = s.find(del);
	while (end != -1) {
		cout << s.substr(start, end - start) << endl;
		start = end + del.size();
		end = s.find(del, start);
	}
	return s.substr(start, end - start);
}

string toUpper(string s) {
	for (int i = 0; i < (s.length() - 3); i++) {
		s[i] = toupper(s[i]);
	}

	return s;
}

Tutor* middle(Tutor* startNode, Tutor* endNode) {
	if (startNode == NULL) {
		return NULL;
	}

	Tutor* slow = startNode;
	Tutor* fast = startNode->nextAddress;

	while (fast != endNode) {
		fast = fast->nextAddress;
		if (fast != endNode) {
			slow = slow->nextAddress;
			fast = fast->nextAddress;
		}
	}

	return slow;
}

// Modify tutor record by ID
void modifyTutorRecord() {
	system("cls");
	int id;
	cout << "Please enter the tutor's ID that you want to modify : TR";
	cin >> id;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!" << endl;
		cout << "Please enter correct tutor ID, only number is required : TR";
		cin >> id;
	}
	
	if (::sizeOfTutorLinkedList == 0) {
		cout << "There is no record, cannot modify!" << endl;
		return;
	}
	
	//before using binary search, need to sort first
	sortTutorById();
	//binary search
	do {
		//find middle
		Tutor* mid = middle(headTutor, tailTutor);
		if (stoi(splitStr(mid->tutorId, "TR")) == id) {
			int modiCho = 99;
			while (modiCho != 0)
			{
				system("cls");
				cout << "Information of the tutor you can modify is as follows:" << endl;
				cout << "1.TutorId" << "\t\t" << " : " << mid->tutorId << endl;
				cout << "2.TutorName" << "\t" << " : " << mid->name << endl;
				cout << "3.IC" << "\t\t" << " : " << mid->ic << endl;
				cout << "4.FieldOfStudy" << "\t" << " : " << mid->fieldOfStudy << endl;
				cout << "5.Address" << "\t\t" << " : " << mid->address << endl;
				cout << "6.Phone" << "\t\t" << " : " << mid->phone << endl;
				cout << "7.DateTerminated" << "\t" << " : " << mid->dateTerminated << endl;
				cout << "8.TuitionCenterCode" << ": " << mid->tuitionCenterCode << endl;
				cout << "9.TuitionCenterName" << ": " << mid->tuitionCenterName << endl;
				cout << "10.SubjectCode" << "\t" << " : " << mid->subjectCode << endl;
				cout << "11.SubjectName" << "\t" << " : " << mid->subjectName << endl;
				cout << "12.HourlyPayRate" << "\t" << " : " << mid->hourlyPayRate << endl;
				cout << "13.Experience" << "\t" << " : " << mid->experience << endl;
				cout << "14.Rating" << "\t\t" << " : " << mid->rating << endl;
				cout << "15.Passowrd" << "\t\t" << " : " << mid->password << endl;

				//ask choice
				cout << endl << "Enter correct number to modify corresponding information, enter 0 if you don't want to modify." << endl;
				cout << endl << "Please enter your choice : ";
				//read choice from user
				cin >> modiCho;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//check whether the user's input is valid, until get expected input
				while (cin.fail() || modiCho < 0 || modiCho > 15) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Invalid Input!" << endl;
					cout << "Please enter your choice again : ";
					cin >> modiCho;
				}

				//execute chosen function according to user's choice
				switch (modiCho)
				{
				case 0:
					system("cls");
					return;
				case 1:
				{
					system("cls");
					string tutorId;
					cout << "Please enter New Tutor Id : ";
					getline(cin, tutorId);
					mid->tutorId = tutorId;
				}
				break;
				case 2:
				{
					system("cls");
					string tutorName;
					cout << "Please enter New Tutor Name : ";
					getline(cin, tutorName);
					mid->name = tutorName;
				}
				break;
				case 3:
				{
					system("cls");
					int ic;
					cout << "Please enter New ic : ";
					while (!(cin >> ic)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << endl << "Please enter New ic : ";
					}
					mid->ic = ic;
				}
				break;
				case 4:
				{
					system("cls");
					string temp;
					cout << "Please enter New Field of study : ";
					getline(cin, temp);
					mid->fieldOfStudy = temp;
				}
				break;
				case 5:
				{
					system("cls");
					string temp;
					cout << "Please enter New Address : ";
					getline(cin, temp);
					mid->address = temp;
				}
				break;
				case 6:
				{
					system("cls");
					int temp;
					cout << "Please enter New phone number : ";
					while (!(cin >> temp)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << endl << "Please enter New phone number : ";
					}
					mid->phone = temp;
				}
				break;
				case 7:
				{
					system("cls");
					string temp;
					cout << "Please enter termitated Date (format is DD-MM-YYYY): ";
					getline(cin, temp);
					mid->dateTerminated = temp;
				}
				break;
				case 8:
				{
					system("cls");
					string temp;
					cout << "Please enter New Tuition Center Code : ";
					getline(cin, temp);
					mid->tuitionCenterCode = temp;
				}
				break;
				case 9:
				{
					system("cls");
					string temp;
					cout << "Please enter New Tuition Center Name : ";
					getline(cin, temp);
					mid->tuitionCenterName = temp;
				}
				break;
				case 10:
				{
					system("cls");
					string temp;
					cout << "Please enter New Subject Code : ";
					getline(cin, temp);
					mid->subjectCode = temp;
				}
				break;
				case 11:
				{
					system("cls");
					string temp;
					cout << "Please enter New Subject Name : ";
					getline(cin, temp);
					mid->subjectName = temp;
				}
				break;
				case 12:
				{
					double temp;
					cout << "Please enter New Hourly Pay Rate : ";
					while (!(cin >> temp)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << endl << "Please enter New Hourly Pay Rate : ";
					}
					mid->hourlyPayRate = temp;
				}
				break;
				case 13:
				{
					double temp;
					cout << "Please enter New Experince of teaching : ";
					while (!(cin >> temp)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << endl << "Please enter New Experince of teaching : ";
					}
					mid->experience = temp;
				}
				break;
				case 14:
				{
					int temp;
					cout << "Please enter New Rating : ";
					while (!(cin >> temp)) {
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << endl << "Please enter New Rating : ";
					}
					mid->rating = temp;
				}
				break;
				case 15:
				{
					system("cls");
					string temp;
					cout << "Please enter New Password : ";
					getline(cin, temp);
					mid->password = temp;
				}
				break;
				default:
					cout << "no choice";
					break;
				}
			}

			return;
		}
		else if (stoi(splitStr(mid->tutorId, "TR")) < id) {
			headTutor = mid->nextAddress;
		}
		else {
			tailTutor = mid;
		}
	} while (tailTutor != NULL || tailTutor != headTutor);
}

// Search =tutor based on their tutor id
void searchTutorById() {
	auto t1 = high_resolution_clock::now();
	string tutorId;

	cout << "Please enter a Tutor Id : ";
	cin >> tutorId;

	string upperId = toUpper(tutorId);
	int id = stoi(splitStr(upperId, "TR"));

	do{
		//find middle
		Tutor* mid = middle(headTutor, tailTutor);

		if (mid == NULL) {
			cout << "The provided Tutor Id is not match with the record." << endl;
		}
		
		if (stoi(splitStr(mid->tutorId, "TR")) == id) {
			system("cls");
			cout << "TutorId" << "\t\t" << " : " << mid->tutorId << endl;
			cout << "TutorName" << "\t" << " : " << mid->name << endl;
			cout << "IC" << "\t\t" << " : " << mid->ic << endl;
			cout << "FieldOfStudy" << "\t" << " : " << mid->fieldOfStudy << endl;
			cout << "Address" << "\t\t" << " : " << mid->address << endl;
			cout << "Phone" << "\t\t" << " : " << mid->phone << endl;
			cout << "DateJoined" << "\t" << " : " << mid->dateJoined << endl;
			cout << "DateTerminated" << "\t" << " : " << mid->dateTerminated << endl;
			cout << "TuitionCenterCode" << ": " << mid->tuitionCenterCode << endl;
			cout << "TuitionCenterName" << ": " << mid->tuitionCenterName << endl;
			cout << "SubjectCode" << "\t" << " : " << mid->subjectCode << endl;
			cout << "SubjectName" << "\t" << " : " << mid->subjectName << endl;
			cout << "HourlyPayRate" << "\t" << " : " << mid->hourlyPayRate << endl;
			cout << "Experience" << "\t" << " : " << mid->experience << endl;
			cout << "Rating" << "\t\t" << " : " << mid->rating << endl;
			break;
		}else if (stoi(splitStr(mid->tutorId, "TR")) < id) {
			headTutor = mid->nextAddress;
		}else{
			tailTutor = mid;
		}	
	} while (tailTutor != NULL || tailTutor != headTutor);

	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	std::cout << "Execution time : " << ms_double.count() << "ms\n";
}

// Search tutor based on the subject teaching
void searchTutorBySubject() {
	if (headTutor == NULL) {
		system("cls");
		cout << "Empty list! Cannot do searching!" << endl;
		system("pause");
		return;
	}
	else {
		system("cls");
		Tutor* current = headTutor;
		int matchNo = 0;
		//ask and read searched subject from user
		string subjectKey;
		cout << "Please enter a substring of subject that you want to search: ";
		getline(cin, subjectKey);
		//while (cin.fail()) {
		   // cin.clear();
		   // cin.ignore(numeric_limits<streamsize>::max(), '\n');
		   // cout << "Invalid Input!" << endl;
		   // cout << "Please enter correct substring of subject that you want to search: ";
		   // cin >> subjectKey;
		//}
		while (current != NULL) {
			if (current->subjectName.find(subjectKey) != string::npos) {
				matchNo = matchNo + 1;
				cout << "Record of No." << matchNo << " Tutor matches the condition is as following : " << endl;
				cout << "TutorId" << "\t\t" << " : " << current->tutorId << endl;
				cout << "TutorName" << "\t" << " : " << current->name << endl;
				cout << "IC" << "\t\t" << " : " << current->ic << endl;
				cout << "FieldOfStudy" << "\t" << " : " << current->fieldOfStudy << endl;
				cout << "Address" << "\t\t" << " : " << current->address << endl;
				cout << "Phone" << "\t\t" << " : " << current->phone << endl;
				cout << "DateJoined" << "\t" << " : " << current->dateJoined << endl;
				cout << "DateTerminated" << "\t" << " : " << current->dateTerminated << endl;
				cout << "TuitionCenterCode" << ": " << current->tuitionCenterCode << endl;
				cout << "TuitionCenterName" << ": " << current->tuitionCenterName << endl;
				cout << "SubjectCode" << "\t" << " : " << current->subjectCode << endl;
				cout << "SubjectName" << "\t" << " : " << current->subjectName << endl;
				cout << "HourlyPayRate" << "\t" << " : " << current->hourlyPayRate << endl;
				cout << "Experience" << "\t" << " : " << current->experience << endl;
				cout << "Rating" << "\t\t" << " : " << current->rating << endl;
				cout << string(50, '=') << endl;	
			}
			current = current->nextAddress;
		}
		if (matchNo == 0) {
			cout << endl << "There is no subject contains this substring.";
		}
		else {
			cout << endl << "These are all records that match searching condition.";
		}

		return;	
	}
}

// Sort tutor by using tutor id - insert sort
void sortTutorById() {
	if (headTutor == NULL) {
		system("cls");
		cout << "There is no element in List, cannot sort!" << endl;
	}
	else if(::sizeOfTutorLinkedList == 1) {
		system("cls");
		cout << "There is only 1 record, no need to sort!" << endl;
	}
	else {
		Tutor *p = headTutor->nextAddress, *q, *key;

		for (p = p->nextAddress; p != NULL; p = p->nextAddress)
		{
			key = p;
			for (q = p->prevAddress; q != headTutor; q = q->prevAddress)
			{

				if (stoi(splitStr(q->tutorId, "TR")) <= stoi(splitStr(key->tutorId, "TR")))
				{
					break;
				}
			}
			if (q->nextAddress != p)
			{
				if (key->nextAddress != NULL)
				{
					key->prevAddress->nextAddress = key->nextAddress;
					key->nextAddress->prevAddress = key->prevAddress;

					key->nextAddress = q->nextAddress;
					q->nextAddress->prevAddress = key;
					key->prevAddress = q;
					q->nextAddress = key;
				}
				else
				{
					key->prevAddress->nextAddress = NULL;

					key->nextAddress = q->nextAddress;
					q->nextAddress->prevAddress = key;
					key->prevAddress = q;
					q->nextAddress = key;
				}
			}
		}
	}
}

//recursive function to merge nodes of two sorted lists into a single sorted list
Tutor* sortTutorByHourlyPayRate(Tutor* a, Tutor* b) {
	if (a == NULL) {
		return b;
	}

	if (b == NULL) {
		return a;
	}

	if (a->hourlyPayRate <= b->hourlyPayRate) {
		a->nextAddress = sortTutorByAddress(a->nextAddress, b);
		a->nextAddress->prevAddress = a;
		a->prevAddress = NULL;
		return a;
	}
	else {
		b->nextAddress = sortTutorByAddress(a, b->nextAddress);
		b->nextAddress->prevAddress = b;
		b->prevAddress = NULL;
		return b;
	}
}

// Sort tutor based on the hourly pay rate
void mergeSortTutorByHourlyPayRate() {
	auto t1 = high_resolution_clock::now();
	if (headTutor == NULL || (headTutor)->nextAddress == NULL) {
		return;
	}

	//split list into a and b sublist
	Tutor* a = headTutor;
	Tutor* b = NULL;
	split(headTutor, &a, &b);

	//recursively sort the sublists
	mergeSortTutorByAddress(&a);
	mergeSortTutorByAddress(&b);

	//merge the two sorted lists
	headTutor = sortTutorByHourlyPayRate(a, b);

	displayAllTutors();

	cout << endl << endl;
	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	std::cout << "Execution time : " << ms_double.count() << "ms\n";
}


//int tutorMenu() {
//	system("cls");
//	int choice = 99;
//
//	while (choice != 0 && choice != -1)
//	{
//		//menu content
//		cout << "\t----------Welcome to Tutor Menu----------" << endl << endl;
//		cout << "The following actions are available for tutor : " << endl << endl;
//		//function introduction
//		cout << "1. View profile of yourself." << endl;
//		cout << "0. Logout and Go back to Login interface." << endl;
//		cout << "-1. Quit the whole system." << endl;
//		//ask choice
//		cout << endl << "Please enter correct number to select what action do you want : ";
//
//		//read choice from user
//		cin >> choice;
//		//check whether the user's input is valid, until get expected input
//		while (cin.fail() || choice < -1 || choice > 10) {
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//			cout << "Invalid Input!" << endl;
//			cout << "Please enter a correct number to select what action do you want : ";
//			cin >> choice;
//		}
//
//		//execute chosen function according to user's choice
//		switch (choice)
//		{
//		case -1:
//			system("cls");
//			cout << "Quiting the system, thank you for using!" << endl;
//			return choice;
//		case 0:
//			system("cls");
//			return choice;
//		case 1:
//			system("cls");
//			cout << "choice is 1";
//			break;
//		default:
//			cout << "no choice";
//			break;
//		}
//	}
//}

int adminMenu() {
	system("cls");
	int choice = 99;

	while (choice != 0 && choice != -1)
	{
		//menu content
		cout << "----------------------------Welcome to Admin Menu----------------------------" << endl << endl;
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
			displayAllTutors();
			break;
		case 2:
			system("cls");
			displayAllTutorsByLocation();
			break;
		case 3:
			system("cls");
			searchTutorById();
			cout << endl << endl;
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
			sortTutorById();
			displayAllTutors();
			break;
		case 7:
			system("cls");
			cout << "choice is 7";
			break;
		case 8:
			system("cls");
			mergeSortTutorByHourlyPayRate();
			break;
		case 9:
			system("cls");
			registerNewTutor();
			break;
		case 10:
			system("cls");
			modifyTutorRecord();
			break;
		default:
			cout << "no choice";
			break;
		}
	}
}