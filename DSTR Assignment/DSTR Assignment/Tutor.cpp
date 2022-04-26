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

// Ask the user to key in the tutor details
//void registerNewTutor(Tutor tutorList[], int numberOfTutor)
//{
//	 numberOfTutor += 1;
//	 Tutor* tutorList = new Tutor[numberOfTutor];
//     cout << "Please enter the following details to register a new tutor." << endl;
//     cout << string(20, '=') << endl;
//
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
//	 cout << "Rating : ";
//	 cin >> rating;
//
//	 for (int i = 0; i <= numberOfTutor; i++) {
//		 if (i == (numberOfTutor - 1)) {
//			 tutorList[i] = Tutor("TR004", "Andy", 123456789, "Applied Maths", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 5.0, 10.0, 4);
//		
//				 /*Tutor(tutorId, name, ic, fieldOfStudy, address, phone, dateJoined, dateTerminated,
//				 tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password, hourlyPayRate, experience, rating);*/
//		 }
//	 }
//	 
//	 cout << "Successfully added the new tutor !" << endl;
// }

// Add new tutor record into the array
 //void saveTutor(Tutor newTutor) {
	// numberOfTutor++;
	// tutorList[numberOfTutor - 1] = newTutor;
 //}

// Generate tutor record every time the system is being compiled so the action has been done wouldn't affect it
void generateTutorRecord(Tutor tutorList[]) {
	tutorList[0] = Tutor("TR001", "James", 123456789, "Biomedical", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "B01", "Biology", "abc123", 5.6, 10.0, 4);
	tutorList[1] = Tutor("TR002", "Micheal", 123456789, "Physics", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "P01", "Physcis", "abc123", 10.2, 10.0, 4);
	tutorList[2] = Tutor("TR003", "Andy", 123456789, "Applied Maths", "Bukit Jalil", 123456789, "12-03-2012", "NULL", "TC001", "Elite", "C01", "Maths", "abc123", 1.8, 10.0, 4);
}

 // TODO: Display the records that categorized by location
void displayAllTutors(Tutor tutorList[], int numberOfTutor){
     cout << "TutorId" << "\t" << "TutorName" << "\t" << "IC" << "\t" << "FieldOfStudy" << "\t" << "Address" << "\t" << "Phone" << "\t"
     << "DateJoined" << "\t" << "DateTerminated" << "\t" << "TuitionCenterCode" << "\t" << "TuitionCenterName"
     << "\t" << "SubjectCode" << "\t" << "SubjectName" << "\t" << "HourlyPayRate" << "\t" << "Experience" << "\t" << "Rating" << endl;
     cout << string(210, '=') << endl;

     if(tutorList != NULL){
         for(int i = 0; i < numberOfTutor; i++){
			 cout << tutorList[i].tutorId << "\t" << tutorList[i].name << "\t" << tutorList[i].ic << "\t" << tutorList[i].fieldOfStudy << "\t"
				 << tutorList[i].address << "\t" << tutorList[i].phone << "\t" << tutorList[i].dateJoined << "\t" << tutorList[i].dateTerminated
				 << "\t" << tutorList[i].tuitionCenterCode << "\t" << tutorList[i].tuitionCenterName << "\t" << tutorList[i].subjectCode
				 << "\t" << tutorList[i].subjectName << "\t" << tutorList[i].hourlyPayRate << "\t" << tutorList[i].experience << "\t" << tutorList[i].rating << endl;
         }
     }else{
         cout << "There is no any tutor record available. Please add the tutor record." << endl;
     }
 }

// // Modify =tutor record (only telephone number, date terminated, tuition center code and name)
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

//TODO: need to work on input validation
 // Search =tutor based on their tutor id
 void searchTutorById(Tutor tutorList[], int startIndex, int endIndex, string tutorId) {
	 int id = stoi(splitStr(tutorId, "TR"));
	 while (startIndex <= endIndex) { 
		 int middle = startIndex + (endIndex - startIndex) / 2;
		 
		 if (stoi(splitStr(tutorList[middle].tutorId, "TR")) == id) {
			 system("cls");
			 cout << tutorList[middle].tutorId << "\t" << tutorList[middle].name << "\t" << tutorList[middle].ic << "\t" << tutorList[middle].fieldOfStudy << "\t"
				 << tutorList[middle].address << "\t" << tutorList[middle].phone << "\t" << tutorList[middle].dateJoined << "\t" << tutorList[middle].dateTerminated
				 << "\t" << tutorList[middle].tuitionCenterCode << "\t" << tutorList[middle].tuitionCenterName << "\t" << tutorList[middle].subjectCode
				 << "\t" << tutorList[middle].subjectName << "\t" << tutorList[middle].hourlyPayRate << "\t" << tutorList[middle].experience << "\t" << tutorList[middle].rating << endl;
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
void merge(Tutor tutorList[], int startIndex, int middle, int endIndex, Tutor temp[]) {
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
		 merge(tutorList, startIndex, middle, endIndex, temp);
	 }
 };

// // View profile
// void viewProfile();

// // Delete the tutor record after 6 months termination (only HR can do it)
// void deleteTutorRecord();