#pragma once
#include <iostream>
#include <string>

using namespace std;



struct Tutor {
	string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
	int phone, rating, ic;
	double hourlyPayRate, experience;

	Tutor();
	Tutor(string tutorId, string name, int ic, string fieldOfStudy, string address, int phone, string dateJoined, string dateTerminated,
		string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, string password,
		double hourlyPayRate, double experience, int rating);
};



int tutorMenu();
Tutor* generateTutorRecord();

//void registerNewTutor(Tutor tutorList[], int numberOfTutor);
//void saveTutor(Tutor* newTutor);

void displayAllTutors(Tutor tutorList[], int numberOfTutor);
void displayAllTutorsByLocation(Tutor tutorList[], int numberOfTutor);
Tutor* addNewTutor(Tutor* oldList, int size);
//void modifyTutorRecord();
void searchTutorById(Tutor tutorList[], int startIndex, int endIndex, string tutorId);
//void searchTutorByRating();
void searchTutorBySubject(Tutor* tutorList, int size);
void quickSort(Tutor* data, int start, int end);
void sortTutorById(Tutor* data, int size);

//void sortTutorByRating();
void sortTutorByHourlyPayRate(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]);
void sortTutorByAddress(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]);
//void viewProfile();
//void deleteTutorRecord();


