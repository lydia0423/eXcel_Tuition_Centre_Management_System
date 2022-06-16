#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <string>
#include <ctime>
#include <sstream>
#include <chrono>
#include "Tutor.h"


string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
int phone, rating, ic;
double hourlyPayRate, experience;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

Tutor::Tutor() {}

Tutor::Tutor(string tutorId, string name, int ic, string fieldOfStudy, string address, int phone, string dateJoined, string dateTerminated,
	string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, string password,
	double hourlyPayRate, double experience, int rating) {
	this->tutorId = tutorId;
	this->name = name;
	this->ic = ic;
	this->fieldOfStudy = fieldOfStudy;
	this->address = address;
	this->phone = phone;
	this->dateJoined = dateJoined;
	this->dateTerminated = dateTerminated;
	this->tuitionCenterCode = tuitionCenterCode;
	this->tuitionCenterName = tuitionCenterName;
	this->subjectCode = subjectCode;
	this->subjectName = subjectName;
	this->password = password;
	this->hourlyPayRate = hourlyPayRate;
	this->experience = experience;
	this->rating = rating;
}

// supporting function
string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

// form sample data
Tutor* generateTutorRecord() {
	Tutor* tutorList = new Tutor[7];

	tutorList[0] = Tutor("TR002", "James", 123456789, "Biomedical", "Johor", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 5, 10.0, 3);
	tutorList[1] = Tutor("TR001", "Micheal", 123456789, "Physics", "Kuala Lumpur", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 10, 10.0, 5);
	tutorList[2] = Tutor("TR004", "Andy", 123456789, "Applied Maths", "Penang", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 2, 10.0, 4);
	tutorList[3] = Tutor("TR003", "Cindy", 123456789, "Biomedical", "Kuala Lumpur", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 4, 10.0, 1);
	tutorList[4] = Tutor("TR006", "Wennie", 123456789, "Physics", "Kuala Lumpur", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 12.3, 10.0, 3);
	tutorList[5] = Tutor("TR005", "Jolin", 123456789, "Applied Maths", "Penang", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 11.8, 10.0, 4);
	tutorList[6] = Tutor("TR007", "Steve", 123456789, "Applied Maths", "Penang", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 19, 10.0, 5);

	return tutorList;
}

// add new tutor record
Tutor* addNewTutor(Tutor* oldList, int size) {
	
	//Create new array 
	Tutor* newList = new Tutor[size + 1];
	//Copy data
	for (int i = 0; i < size; i++) {
		newList[i] = oldList[i];
	}

	string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
	int phone, rating, ic;
	double hourlyPayRate, experience;

	cout << "Please enter the following details to register a new tutor." << endl;
	cout << string(20, '=') << endl;

	//convert int to string
	stringstream stream;
	stream << size + 1;
	string str;
	stream >> str;

	if (size < 10) {
		tutorId = "TR00" + str;
	}
	else {
		tutorId = "TR0" + str;
	}

	cout << "Tutor Id : " << tutorId << endl;
	cout << "Tutor Name : ";
	cin >> name;
	cout << "IC : ";
	while (!(cin >> ic)) {
		cout << "IC : ";
		cin.clear();
		cin.ignore(22, '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Field of study : ";
	getline(cin, fieldOfStudy);
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

	auto t1 = high_resolution_clock::now();
	newList[size] = Tutor(tutorId, name, ic, fieldOfStudy, address, phone, dateJoined, "NULL", tuitionCenterCode, tuitionCenterName, subjectCode, 
		subjectName, password, hourlyPayRate, experience, 0);

	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	std::cout << "Execution time : " << ms_double.count() << "ms\n";
	system("pause");

	return newList;
}

// Traverse and display
void displayAllTutors(Tutor tutorList[], int numberOfTutor){
	auto t1 = high_resolution_clock::now();
	//display records by page
	int chunk = 3; //prefer row for display per page
	int totalPage = 0;
	if (numberOfTutor <= 3) {
		totalPage = 1;
	}else if (numberOfTutor > 3) {
		totalPage = (numberOfTutor / chunk) + 1;
	}else {
		totalPage = (numberOfTutor / chunk);
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
			length = numberOfTutor;
		}

		for (int i = tmpRow; i < length; i++) {
			cout << "TutorId" << "\t\t" << " : " << tutorList[i].tutorId << endl;
			cout << "TutorName" << "\t" << " : " << tutorList[i].name << endl;
			cout << "IC" << "\t\t" << " : " << tutorList[i].ic << endl;
			cout << "FieldOfStudy" << "\t" << " : " << tutorList[i].fieldOfStudy << endl;
			cout << "Address" << "\t\t" << " : " << tutorList[i].address << endl;
			cout << "Phone" << "\t\t" << " : " << tutorList[i].phone << endl;
			cout << "DateJoined" << "\t" << " : " << tutorList[i].dateJoined << endl;
			cout << "DateTerminated" << "\t" << " : " << tutorList[i].dateTerminated << endl;
			cout << "TuitionCenterCode" << ": " << tutorList[i].tuitionCenterCode << endl;
			cout << "TuitionCenterName" << ": " << tutorList[i].tuitionCenterName << endl;
			cout << "SubjectCode" << "\t" << " : " << tutorList[i].subjectCode << endl;
			cout << "SubjectName" << "\t" << " : " << tutorList[i].subjectName << endl;
			cout << "HourlyPayRate" << "\t" << " : " << tutorList[i].hourlyPayRate << endl;
			cout << "Experience" << "\t" << " : " << tutorList[i].experience << endl;
			cout << "Rating" << "\t\t" << " : " << tutorList[i].rating << endl;
			cout << string(50, '=') << endl;
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

// merge function -- helper class
Tutor* mergeSortTutorByAddress(Tutor tutorList[], int startIndex, int middle, int endIndex, Tutor temp[]) {
	int i = startIndex; //starting index for left sub array
	int j = middle + 1; //starting index for right sub array
	int k = startIndex; //starting index for temporary array

	//to make sure always in the range of the array
	while (i <= middle && j <= endIndex) {
		if (tutorList[i].address <= tutorList[j].address) {
			temp[k] = tutorList[i]; // tutorList[i] is smaller than tutorList[j]
			i++;
			k++;
		}
		else {
			temp[k] = tutorList[j]; //tutorList[j] is smaller than tutorList[i]
			j++;
			k++;
		}
	}

	while (i <= middle) {
		temp[k] = tutorList[i]; // copy all elements from left sub array to temp as it is
		i++;
		k++;
	}

	while (j <= endIndex) {
		temp[k] = tutorList[j]; // copy all elements from right sub array to temp as it is
		j++;
		k++;
	}
	
	return temp;
}

// Sort tutor based on the hourly pay rate (merge sort)
void sortTutorByAddress(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]) {
	if (startIndex < endIndex) {
		int middle = (startIndex + endIndex) / 2;
		sortTutorByAddress(tutorList, 0, middle, temp);
		sortTutorByAddress(tutorList, middle + 1, endIndex, temp);
		mergeSortTutorByAddress(tutorList, startIndex, middle, endIndex, temp);
	}
};

// display grouped by location
void displayAllTutorsByLocation(Tutor tutorList[], int numberOfTutor) {
	auto t1 = high_resolution_clock::now();
	//sort the tutors based on branch
	int endIndex = numberOfTutor - 1;
	Tutor* temp = new Tutor[numberOfTutor];
	sortTutorByAddress(tutorList, 0, endIndex, temp);

	//display records by page
	int chunk = 3; //prefer row for display per page
	int totalPage = 0;
	if (numberOfTutor <= 3) {
		totalPage = 1;
	}else if (numberOfTutor > 3) {
		totalPage = (numberOfTutor / chunk) + 1;
	}else {
		totalPage = (numberOfTutor / chunk);
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
			length = numberOfTutor;
		}

		for (int i = tmpRow; i < length; i++) {
			cout << "TutorId" << "\t\t" << " : " << temp[i].tutorId << endl;
			cout << "TutorName" << "\t" << " : " << temp[i].name << endl;
			cout << "IC" << "\t\t" << " : " << temp[i].ic << endl;
			cout << "FieldOfStudy" << "\t" << " : " << temp[i].fieldOfStudy << endl;
			cout << "Address" << "\t\t" << " : " << temp[i].address << endl;
			cout << "Phone" << "\t\t" << " : " << temp[i].phone << endl;
			cout << "DateJoined" << "\t" << " : " << temp[i].dateJoined << endl;
			cout << "DateTerminated" << "\t" << " : " << temp[i].dateTerminated << endl;
			cout << "TuitionCenterCode" << ": " << temp[i].tuitionCenterCode << endl;
			cout << "TuitionCenterName" << ": " << temp[i].tuitionCenterName << endl;
			cout << "SubjectCode" << "\t" << " : " << temp[i].subjectCode << endl;
			cout << "SubjectName" << "\t" << " : " << temp[i].subjectName << endl;
			cout << "HourlyPayRate" << "\t" << " : " << temp[i].hourlyPayRate << endl;
			cout << "Experience" << "\t" << " : " << temp[i].experience << endl;
			cout << "Rating" << "\t\t" << " : " << temp[i].rating << endl;
			cout << string(50, '=') << endl;
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
				}else if (page == totalPage) {
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

// supporting function
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

// supporting function
string toUpper(string s) {
	for (int i = 0; i < (s.length() - 3); i++) {
		s[i] = toupper(s[i]);
	}

	return s;
}

// Search =tutor based on their tutor id
void searchTutorById(Tutor tutorList[], int startIndex, int endIndex, string tutorId) {
	 auto t1 = high_resolution_clock::now();

	 //convert small letter to capital letter
	 string upperId = toUpper(tutorId);
	 int id = stoi(splitStr(upperId, "TR"));
	 while (startIndex <= endIndex) { 
		 int middle = startIndex + (endIndex - startIndex) / 2;
		 if (stoi(splitStr(tutorList[middle].tutorId, "TR")) == id) {
			 system("cls");
			 cout << "TutorId" << "\t\t" << " : " << tutorList[middle].tutorId << endl;
			 cout << "TutorName" << "\t" << " : " << tutorList[middle].name << endl;
			 cout << "IC" << "\t\t" << " : " << tutorList[middle].ic << endl;
			 cout << "FieldOfStudy" << "\t" << " : " << tutorList[middle].fieldOfStudy << endl;
			 cout << "Address" << "\t\t" << " : " << tutorList[middle].address << endl;
			 cout << "Phone" << "\t\t" << " : " << tutorList[middle].phone << endl;
			 cout << "DateJoined" << "\t" << " : " << tutorList[middle].dateJoined << endl;
			 cout << "DateTerminated" << "\t" << " : " << tutorList[middle].dateTerminated << endl;
			 cout << "TuitionCenterCode" << ": " << tutorList[middle].tuitionCenterCode << endl;
			 cout << "TuitionCenterName" << ": " << tutorList[middle].tuitionCenterName << endl;
			 cout << "SubjectCode" << "\t" << " : " << tutorList[middle].subjectCode << endl;
			 cout << "SubjectName" << "\t" << " : " << tutorList[middle].subjectName << endl;
			 cout << "HourlyPayRate" << "\t" << " : " << tutorList[middle].hourlyPayRate << endl;
			 cout << "Experience" << "\t" << " : " << tutorList[middle].experience << endl;
			 cout << "Rating" << "\t\t" << " : " << tutorList[middle].rating << endl << endl;
			 system("pause");
			 auto t2 = high_resolution_clock::now();
			 duration<double, std::milli> ms_double = t2 - t1;
			 std::cout << "Execution time : " << ms_double.count() << "ms\n";
			 
			 break;
		 }else if (stoi(splitStr(tutorList[middle].tutorId, "TR")) < id) {
			 startIndex = middle + 1;
		 }else if(stoi(splitStr(tutorList[middle].tutorId, "TR")) > id){
			 endIndex = middle - 1;
		 }
		 else {
			 cout << "The provided Tutor Id is not match with the record." << endl << endl;
			 system("pause");
			 auto t2 = high_resolution_clock::now();
			 duration<double, std::milli> ms_double = t2 - t1;
			 std::cout << "Execution time : " << ms_double.count() << "ms\n";
			 system("pause");
		 }
	 }
 }

// Search tutor based on the subject teaching
void searchTutorBySubject(Tutor* tutorList, int size) {
	 system("cls");
	 //ask and read searched subject from user
	 string subjectKey;
	 cout << "Please enter a substring of subject that you want to search: ";
	 cin.clear();
	 cin.ignore(numeric_limits<streamsize>::max(), '\n');
	 getline(cin, subjectKey);
	 //while (cin.fail()) {
		// cin.clear();
		// cin.ignore(numeric_limits<streamsize>::max(), '\n');
		// cout << "Invalid Input!" << endl;
		// cout << "Please enter correct substring of subject that you want to search: ";
		// cin >> subjectKey;
	 //}
	 auto t1 = high_resolution_clock::now();

	 //searching
	 int suitNo = 0; //variable for recording how many tutors match condition
	 for (int i = 0; i < size; i++) {
		 if (tutorList[i].subjectName.find(subjectKey) != string::npos){
			 suitNo++;
			 cout << "No. " << suitNo << "record of tutor who meets search criteria is as follows : " << endl;
			 cout << "TutorId" << "\t\t" << " : " << tutorList[i].tutorId << endl;
			 cout << "TutorName" << "\t" << " : " << tutorList[i].name << endl;
			 cout << "IC" << "\t\t" << " : " << tutorList[i].ic << endl;
			 cout << "FieldOfStudy" << "\t" << " : " << tutorList[i].fieldOfStudy << endl;
			 cout << "Address" << "\t\t" << " : " << tutorList[i].address << endl;
			 cout << "Phone" << "\t\t" << " : " << tutorList[i].phone << endl;
			 cout << "DateJoined" << "\t" << " : " << tutorList[i].dateJoined << endl;
			 cout << "DateTerminated" << "\t" << " : " << tutorList[i].dateTerminated << endl;
			 cout << "TuitionCenterCode" << ": " << tutorList[i].tuitionCenterCode << endl;
			 cout << "TuitionCenterName" << ": " << tutorList[i].tuitionCenterName << endl;
			 cout << "SubjectCode" << "\t" << " : " << tutorList[i].subjectCode << endl;
			 cout << "SubjectName" << "\t" << " : " << tutorList[i].subjectName << endl;
			 cout << "HourlyPayRate" << "\t" << " : " << tutorList[i].hourlyPayRate << endl;
			 cout << "Experience" << "\t" << " : " << tutorList[i].experience << endl;
			 cout << "Rating" << "\t\t" << " : " << tutorList[i].rating << endl;
			 cout << endl;
		 }
	 }
	 //
	 if (suitNo == 0) {
		 cout << "There is no tutors matching the search criteria" << endl;
	 }

	 auto t2 = high_resolution_clock::now();
	 duration<double, std::milli> ms_double = t2 - t1;
	 std::cout << "Execution time : " << ms_double.count() << "ms\n";
	 system("pause");
}

// supporting function - Quick Sort by ID
void quickSort(Tutor* data, int start, int end) {
	 if (start < end) //execute when data can be divided
	 {
		 Tutor base = data[start]; //set first element as base
		 int low = start;
		 int high = end + 1;

		 while (start < end) {
			 //search ele is greater than base
			 while (low < end && stoi(splitStr(data[++low].tutorId, "TR")) <= stoi(splitStr(base.tutorId, "TR")));
			 //find ele less than base
			 while (high > start &&  stoi(splitStr(data[--high].tutorId, "TR")) >= stoi(splitStr(base.tutorId, "TR")));

			 if (low < high) //exchange if bigger one is under smaller one 
			 {
				 Tutor temp;
				 temp = data[low];
				 data[low] = data[high];
				 data[high] = temp;

			 }
			 else // stop after traversing all elements
			 {
				 break;
			 }
		 }
		 //exchange position of base and the first element under all greater elements(greater than base)
		 data[start] = data[high];
		 data[high] = base;
		 //recursive - divide list into 2 and do the above things again 
		 quickSort(data, start, high - 1); //element that all less than base
		 quickSort(data, high + 1, end); //element that all greater than base
	 }
 }

// Sort tutor by using tutor id
void sortTutorById(Tutor* tutorList, int size, int type) {
	 auto t1 = high_resolution_clock::now();
	 if (size == 0) {
		 cout << "There is no record, cannot sort!" << endl;
		 return;
	 }
	 else if (size == 1) {
		 cout << "There is only 1 record, cannot sort!" << endl;
		 return;
	 }
	 else {
		 quickSort(tutorList, 0, size - 1);
	 }

	 auto t2 = high_resolution_clock::now();
	 duration<double, std::milli> ms_double = t2 - t1;
	 //show the sortted data
	 if (type == 1) {
		 system("cls");
		 cout << "Operation done! The data is already sorted by ID." << endl;
		 std::cout << "Execution time : " << ms_double.count() << "ms\n";
		 system("pause");
	 }
	 else {
		 return;
	 }
	 

 }

// Modify tutor record by searching ID
void modifyTutorRecord(Tutor* tutorList, int curSize) {
	 //
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
	 
	 auto t1 = high_resolution_clock::now();
	 if (curSize == 0) {
		 cout << "There is no record, cannot modify!" << endl;
		 return;
	 }
	 else {
		 quickSort(tutorList, 0, curSize - 1);
	 }
	 //binary search
	 int startIndex = 0, endIndex = curSize - 1;
	 while (startIndex <= endIndex) {
		 int middle = startIndex + (endIndex - startIndex) / 2;
		 if (stoi(splitStr(tutorList[middle].tutorId, "TR")) == id) {
			 int modiCho = 99;
			 while (modiCho != 0)
			 {
				 system("cls");
				 cout << "The following are the information can be modifed:" << endl;
				 cout << "1.Address" << "\t\t" << " : " << tutorList[middle].address << endl;
				 cout << "2.Phone" << "\t\t" << " : " << tutorList[middle].phone << endl;

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
					 {
						 auto t2 = high_resolution_clock::now();
						 duration<double, std::milli> ms_double = t2 - t1;
						 std::cout << "Execution time : " << ms_double.count() << "ms\n";
						 system("pause");
					 }
					 return;
				 case 1:
				 {
					 system("cls");
					 string temp;
					 cout << "Please enter New Address : ";
					 getline(cin, temp);
					 tutorList[middle].address = temp;
				 }
					 break;
				 case 2:
				 {
					 system("cls");
					 int temp;
					 cout << "Please enter New phone number : ";
					 while (!(cin >> temp)) {
						 cin.clear();
						 cin.ignore(numeric_limits<streamsize>::max(), '\n');
						 cout << endl << "Please enter New phone number : ";
					 }
					 tutorList[middle].phone = temp;
				 }
					 break;
				 default:
					 cout << "no choice";
					 break;
				 }
			 }
			 return;
		 }
		 else if (stoi(splitStr(tutorList[middle].tutorId, "TR")) < id) {
			 startIndex = middle + 1;
		 }
		 else if (stoi(splitStr(tutorList[middle].tutorId, "TR")) > id) {
			 endIndex = middle - 1;
		 }
		 else {
			 cout << endl << "The provided Tutor Id is not in records." << endl;
			 system("pause");
			 return;
		 }
	 }

 }

// merge function -- helper class
void mergeSortTutorByHourlyPayRate(Tutor tutorList[], int startIndex, int middle, int endIndex, Tutor temp[]) {
	//int middle = (startIndex + endIndex) / 2;
	 int i = startIndex; //starting index for left sub array
	 int j = middle + 1; //starting index for right sub array
	 int k = startIndex; //starting index for temporary array

	 //to make sure always in the range of the array
	 while (i <= middle && j <= endIndex) {
		 if (tutorList[i].hourlyPayRate <= tutorList[j].hourlyPayRate) {
			 temp[k] = tutorList[i]; // tutorList[i] is smaller than tutorList[j]
			 i++;
			 k++;
		 }else {
			 temp[k] = tutorList[j]; //tutorList[j] is smaller than tutorList[i]
			 j++;
			 k++;
		 }
	 }

	 while (i <= middle) {
		 temp[k] = tutorList[i]; // copy all elements from left sub array to temp as it is
		 i++;
		 k++;
	 }

	 while (j <= endIndex) {
		 temp[k] = tutorList[j]; // copy all elements from right sub array to temp as it is
		 j++;
		 k++;
	 }

 }

// Sort tutor based on the hourly pay rate (merge sort)
void sortTutorByHourlyPayRate(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]) {
	 if (startIndex < endIndex) {
		 int middle = (startIndex + endIndex) / 2;
		 sortTutorByHourlyPayRate(tutorList, startIndex, middle, temp);
		 sortTutorByHourlyPayRate(tutorList, middle + 1, endIndex, temp);
		 mergeSortTutorByHourlyPayRate(tutorList, startIndex, middle, endIndex, temp);
	 }
 };

// delete by ID
int deleteTutorRecord(Tutor* tutorList, int curSize)
{
	if (curSize == 0)
	{
		cout << "There is no record, cannot delete!" << endl;
		return curSize;
	}

	system("cls");

	string id;
	cout << "Please enter the tutor's ID that you want to delete" << endl;
	cin >> id;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!" << endl;
		cout << "Please enter correct tutor ID, only number is required : TR";
		cin >> id;
	}

	for (int i = 0; i < curSize; i++)
	{
		if (tutorList[i].tutorId == id)
		{
			system("cls");
			cout << endl << "Are you sure to delete? please type in y" << endl;
			string answer;
			cin >> answer;
			if (answer == "y")
			{
				int j = i;
				while (j < curSize - 1)
				{
					tutorList[j] = tutorList[j + 1];
					j++;
				}
				cout << "DELETE Completed" << endl;
				curSize = curSize - 1;
			}
			else
			{
				break;
			}
		}
	}

	cout << "Now the records terminated are updating" << endl;
	for (int i = 0; i < curSize; i++)
	{
		if (tutorList[i].dateTerminated == "NULL")
		{
			continue;
		}
		else
		{
			int endmonth = atoi(tutorList[i].dateTerminated.substr(3, 2).c_str());
			int endyear = atoi(tutorList[i].dateTerminated.substr(6, 4).c_str());

			int months = (endyear - 1900) * 12 + endmonth;

			time_t nowtime;
			struct tm* p;;
			time(&nowtime);
			p = localtime(&nowtime);

			int nowmonths = p->tm_year * 12 + p->tm_mon;

			if (nowmonths - months > 6)
			{
				int j = i;
				while (j < curSize - 1)
				{
					tutorList[j] = tutorList[j + 1];
					j++;
				}
				cout << "DELETE Completed" << endl;
				curSize = curSize - 1;
			}
			else
			{
				continue;
			}
		}
	}

	system("pause");
	return curSize;
}

// search by rating
void searchTutorByRating(Tutor* tutorList, int size, int rating)
{
	int judge = 0;
	for (int i = 0; i < size; i++)
	{
		if (rating == tutorList[i].rating)
		{
			judge = 1;
			//system("cls");
			cout << "TutorId" << "\t\t" << " : " << tutorList[i].tutorId << endl;
			cout << "TutorName" << "\t" << " : " << tutorList[i].name << endl;
			cout << "IC" << "\t\t" << " : " << tutorList[i].ic << endl;
			cout << "FieldOfStudy" << "\t" << " : " << tutorList[i].fieldOfStudy << endl;
			cout << "Address" << "\t\t" << " : " << tutorList[i].address << endl;
			cout << "Phone" << "\t\t" << " : " << tutorList[i].phone << endl;
			cout << "DateJoined" << "\t" << " : " << tutorList[i].dateJoined << endl;
			cout << "DateTerminated" << "\t" << " : " << tutorList[i].dateTerminated << endl;
			cout << "TuitionCenterCode" << ": " << tutorList[i].tuitionCenterCode << endl;
			cout << "TuitionCenterName" << ": " << tutorList[i].tuitionCenterName << endl;
			cout << "SubjectCode" << "\t" << " : " << tutorList[i].subjectCode << endl;
			cout << "SubjectName" << "\t" << " : " << tutorList[i].subjectName << endl;
			cout << "HourlyPayRate" << "\t" << " : " << tutorList[i].hourlyPayRate << endl;
			cout << "Experience" << "\t" << " : " << tutorList[i].experience << endl;
			cout << "Rating" << "\t\t" << " : " << tutorList[i].rating << endl;
			cout << "========================================" << endl;
		}
	}
	if (judge == 1)
	{
		cout << "Search complete! All the records are displayed" << endl;
		system("pause");
	}
	else
	{
		cout << "The provided Tutor Id is not match with the record." << endl;
		system("pause");
	}
}

// supporting function for sort by rating
void quickSortrating(Tutor* data, int start, int end)
{
	if (start < end) //execute when data can be divided
	{
		Tutor base = data[start]; //set first element as base
		int low = start;
		int high = end + 1;

		while (start < end) {
			//search ele is greater than base
			while (low < end && data[++low].rating <= base.rating);
			//find ele less than base
			while (high > start && data[--high].rating >= base.rating);

			if (low < high) //exchange if bigger one is under smaller one
			{
				Tutor temp;
				temp = data[low];
				data[low] = data[high];
				data[high] = temp;

			}
			else // stop after traversing all elements
			{
				break;
			}
		}
		//exchange position of base and the first element under all greater elements(greater than base)
		data[start] = data[high];
		data[high] = base;
		//recursive - divide list into 2 and do the above things again
		quickSortrating(data, start, high - 1); //element that all less than base
		quickSortrating(data, high + 1, end); //element that all greater than base
	}
}

// Sort tutor by given rating (overall performance)
void sortTutorByRating(Tutor* tutorList, int size)
{
	auto t1 = high_resolution_clock::now();
	if (size == 0) {
		cout << "There is no record, cannot sort!" << endl;
		return;
	}
	else if (size == 1) {
		cout << "There is only 1 record, cannot sort!" << endl;
		return;
	}
	else {
		quickSortrating(tutorList, 0, size - 1);
	}
	auto t2 = high_resolution_clock::now();
	duration<double, std::milli> ms_double = t2 - t1;
	//show the sortted data
	system("cls");
	cout << "Operation done! The data is already sorted by Overall Perfomance." << endl;
	displayAllTutors(tutorList, size);
	std::cout << "Execution time : " << ms_double.count() << "ms\n";
	system("pause");
}