#include <iostream>
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
	double hourlyPayRate, double experience, int rating) 
{
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

// Ask the user to key in the tutor details
void registerNewTutor(Tutor tutorList[], int numberOfTutor)
{
	 numberOfTutor += 1;
	 Tutor* tutorList = new Tutor[numberOfTutor];
     cout << "Please enter the following details to register a new tutor." << endl;
     cout << string(20, '=') << endl;

     cout << "Tutor Id : ";
     getline(cin, tutorId);
     cout << "Tutor Name : ";
     getline(cin, name);
     cout << "IC : ";
     cin >> ic;
     cout << "Field of study : ";
     getline(cin, fieldOfStudy);
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Address : ";
     getline(cin, address);
     cout << "Phone Number : ";
     cin >> phone;
     cin.ignore(numeric_limits<streamsize>::max(), '\n');
     cout << "Date Joined : ";
     getline(cin, dateJoined);
     cout << "Date Terminated : ";
     getline(cin, dateTerminated);
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
     cin >> hourlyPayRate;
     cout << "Experince of teaching : ";
     cin >> experience;
	 cout << "Rating : ";
	 cin >> rating;

	 for (int i = 0; i <= numberOfTutor; i++) {
		 if (i == (numberOfTutor - 1)) {
			 tutorList[i] = Tutor("TR004", "Andy", 123456789, "Applied Maths", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 5.0, 10.0, 4);
		
				 /*Tutor(tutorId, name, ic, fieldOfStudy, address, phone, dateJoined, dateTerminated,
				 tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password, hourlyPayRate, experience, rating);*/
		 }
	 }
	 
	 cout << "Successfully added the new tutor !" << endl;
 }

// Add new tutor record into the array
 //void saveTutor(Tutor newTutor) {
	// numberOfTutor++;
	// tutorList[numberOfTutor - 1] = newTutor;
 //}

// Generate tutor record every time the system is being compiled so the action has been done wouldn't affect it
void generateTutorRecord(Tutor tutorList[]) 
{
	tutorList[0] = Tutor("TR001", "James", 123456789, "Biomedical", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 5.0, 10.0, 4);
	tutorList[1] = Tutor("TR002", "Micheal", 123456789, "Physics", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 5.0, 10.0, 4);
	tutorList[2] = Tutor("TR003", "Andy", 123456789, "Applied Maths", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 5.0, 10.0, 4);
}

 // TODO: Display the records that categorized by location
 void displayAllTutors(Tutor tutorList[], int numberOfTutor)
{
     cout << "TutorId" << "\t" << "TutorName" << "\t" << "IC" << "\t" << "FieldOfStudy" << "\t" << "Address" << "\t" << "Phone" << "\t"
     << "DateJoined" << "\t" << "DateTerminated" << "\t" << "TuitionCenterCode" << "\t" << "TuitionCenterName"
     << "\t" << "SubjectCode" << "\t" << "SubjectName" << "\t" << "HourlyPayRate" << "\t" << "Experience" << "\t" << "Rating" << endl;
     cout << string(210, '=') << endl;

     if(tutorList != NULL){
         for(int i = 0; i < numberOfTutor; i++){
			 cout << tutorList[i].tutorId << "\t\t" << tutorList[i].name << "\t\t" << tutorList[i].ic << "\t\t" << tutorList[i].fieldOfStudy << "\t\t"
				 << tutorList[i].address << "\t\t" << tutorList[i].phone << "\t\t" << tutorList[i].dateJoined << "\t\t" << tutorList[i].dateTerminated
				 << "\t\t" << tutorList[i].tuitionCenterCode << "\t\t" << tutorList[i].tuitionCenterName << "\t\t" << tutorList[i].subjectCode
				 << "\t\t" << tutorList[i].subjectName << "\t\t" << tutorList[i].hourlyPayRate << "\t\t" << tutorList[i].experience << "\t\t" << tutorList[i].rating << endl;
         }
     }else{
         cout << "There is no any tutor record available. Please add the tutor record." << endl;
     }

	 cout << &tutorList;
 }

// // Modify =tutor record (only telephone number, date terminated, tuition center code and name)
// void modifyTutorRecord();

// // Search =tutor based on their tutor id
// void searchTutorById();

// // Search tutor based on the rating given by student
// void searchTutorByRating();

// // Search tutor based on the subject teaching
// void searchTutorBySubject();

// // Sort tutor by using tutor id
// void sortTutorById();

// // Sort tutor by using rating give
// void sortTutorByRating();

// // Sort tutor based on the hourly pay rate
// void sortTutorByHourlyPayRate();

// // View profile
// void viewProfile();

// // Delete the tutor record after 6 months termination (only HR can do it)
// void deleteTutorRecord();