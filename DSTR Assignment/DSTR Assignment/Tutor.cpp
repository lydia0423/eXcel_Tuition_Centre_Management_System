#include <iostream>
#include <cctype>
#include <string>
#include "Tutor.h"


string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
int phone, rating, ic;
double hourlyPayRate, experience;

// default size of the array (will keep increasing when new element is added)
//int numberOfTutor = 3;
//Tutor* tutorList = new Tutor[numberOfTutor];

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

int tutorMenu() {
	system("cls");
	int choice = 99;

	while (choice != 0 && choice != -1)
	{
		//menu content
		cout << "\t----------Welcome to Tutor Menu----------" << endl << endl;
		cout << "The following actions are available for tutor : " << endl << endl;
		//function introduction
		cout << "1. View profile of yourself." << endl;
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
		default:
			cout << "no choice";
			break;
		}
	}
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
//void registerNewTutor(Tutor tutorList[], int numberOfTutor)
//{
	//string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
	//int phone, rating, ic;
	//double hourlyPayRate, experience;

	//cout << "Please enter the following details to register a new tutor." << endl;
	//cout << string(20, '=') << endl;

	//cout << "Tutor Id : ";
	//getline(cin, tutorId);
	//cout << "Tutor Name : ";
	//getline(cin, name);
	//cout << "IC : ";
	//while (!(cin >> ic)) {
	//	cout << "IC : ";
	//	cin.clear();
	//	cin.ignore(22, '\n');
	//}
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//cout << "Field of study : ";
	//getline(cin, fieldOfStudy);
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//cout << "Address : ";
	//getline(cin, address);
	//cout << "Phone Number : ";
	//while (!(cin >> phone)) {
	//	cout << "Phone Number : ";
	//	cin.clear();
	//	cin.ignore(22, '\n');
	//}
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//cout << "Tuition Center Code : ";
	//getline(cin, tuitionCenterCode);
	//cout << "Tuition Center Name : ";
	//getline(cin, tuitionCenterName);
	//cout << "Subject Code : ";
	//getline(cin, subjectCode);
	//cout << "Subject Name : ";
	//getline(cin, subjectName);
	//cout << "Password : ";
	//getline(cin, password);
	//cout << "Hourly Pay Rate : ";
	//while (!(cin >> hourlyPayRate)) {
	//	cout << "Hourly Pay Rate : ";
	//	cin.clear();
	//	cin.ignore(22, '\n');
	//}
	//cout << "Experince of teaching : ";
	//while (!(cin >> experience)) {
	//	cout << "Experince of teaching : ";
	//	cin.clear();
	//	cin.ignore(22, '\n');
	//}

	////get current date
	//char currDate[10];

	//time_t t = time(NULL);
	//struct tm tm = *localtime(&t);
	//sprintf(currDate, "%d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	//dateJoined = convertToString(currDate, 10);

	//Tutor* newTutor = addNewTutor(tutorId, name, ic, fieldOfStudy, address, phone, dateJoined, "NULL", tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password, hourlyPayRate, experience, 0);
	//saveTutor(newTutor);

	//cout << endl << "Added new tutor successfully" << endl;
// }

// Add new tutor record into the array
 //void saveTutor(Tutor newTutor) {
	// numberOfTutor++;
	// tutorList[numberOfTutor - 1] = newTutor;
 //}

// Generate tutor record every time the system is being compiled so the action has been done wouldn't affect it
void generateTutorRecord(Tutor tutorList[]) {
	tutorList[0] = Tutor("TR001", "James", 123456789, "Biomedical", "Johor", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 5.6, 10.0, 4);
	tutorList[1] = Tutor("TR002", "Micheal", 123456789, "Physics", "Kuala Lumpur", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 10.2, 10.0, 4);
	tutorList[2] = Tutor("TR003", "Andy", 123456789, "Applied Maths", "Penang", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 1.8, 10.0, 4);
	tutorList[3] = Tutor("TR004", "Cindy", 123456789, "Biomedical", "Kuala Lumpur", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 5.6, 10.0, 4);
	tutorList[4] = Tutor("TR005", "Wennie", 123456789, "Physics", "Kuala Lumpur", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 10.2, 10.0, 4);
	tutorList[5] = Tutor("TR006", "Jolin", 123456789, "Applied Maths", "Penang", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 1.8, 10.0, 4);
}


void displayAllTutors(Tutor tutorList[], int numberOfTutor){
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
				}else if (page == totalPage) {
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

//merge function -- helper class
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

void displayAllTutorsByLocation(Tutor tutorList[], int numberOfTutor) {
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
				}else if (page == totalPage) {
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

// Modify =tutor record (only telephone number, date terminated, tuition center code and name)
// void modifyTutorRecord();

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

 // Search =tutor based on their tutor id
 void searchTutorById(Tutor tutorList[], int startIndex, int endIndex, string tutorId) {
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
			 cout << "Rating" << "\t\t" << " : " << tutorList[middle].rating << endl;
			 break;
		 }else if (stoi(splitStr(tutorList[middle].tutorId, "TR")) < id) {
			 startIndex = middle + 1;
		 }else if(stoi(splitStr(tutorList[middle].tutorId, "TR")) > id){
			 endIndex = middle - 1;
		 }
		 else {
			 cout << "The provided Tutor Id is not match with the record." << endl;
		 }
	 }
 }

// // Search tutor based on the rating given by student
// void searchTutorByRating();

// // Search tutor based on the subject teaching
// void searchTutorBySubject();

// // Sort tutor by using tutor id
// void sortTutorById();

// // Sort tutor by using rating give
// void sortTutorByRating();

//merge function -- helper class
void mergeSortTutorByHourlyPayRate(Tutor tutorList[], int startIndex, int middle, int endIndex, Tutor temp[]) {
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

	 system("cls");
	 displayAllTutors(temp, endIndex + 1);
 }

// // Sort tutor based on the hourly pay rate (merge sort)
 void sortTutorByHourlyPayRate(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]) {
	 if (startIndex < endIndex) {
		 int middle = (startIndex + endIndex) / 2;
		 sortTutorByHourlyPayRate(tutorList, 0, middle, temp);
		 sortTutorByHourlyPayRate(tutorList, middle + 1, endIndex, temp);
		 mergeSortTutorByHourlyPayRate(tutorList, startIndex, middle, endIndex, temp);
	 }
 };

// // View profile
// void viewProfile();

// // Delete the tutor record after 6 months termination (only HR can do it)
// void deleteTutorRecord();