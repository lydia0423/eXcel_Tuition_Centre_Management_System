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


Tutor* generateTutorRecord();
void displayAllTutors(Tutor tutorList[], int numberOfTutor);
void displayAllTutorsByLocation(Tutor tutorList[], int numberOfTutor);
Tutor* addNewTutor(Tutor* oldList, int size);
void modifyTutorRecord(Tutor* tutorList, int curSize);

void searchTutorById(Tutor tutorList[], int startIndex, int endIndex, string tutorId);

void searchTutorBySubject(Tutor* tutorList, int size);
void quickSort(Tutor* data, int start, int end);
void sortTutorById(Tutor* tutorList, int size, int type);
void sortTutorByHourlyPayRate(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]);
void sortTutorByAddress(Tutor tutorList[], int startIndex, int endIndex, Tutor temp[]);
int deleteTutorRecord(Tutor* tutorList, int curSize);
void searchTutorByRating(Tutor* tutorList, int size, int rating);
void quickSortrating(Tutor* data, int start, int end);
void sortTutorByRating(Tutor* tutorList, int size);

int adminMenu(Tutor tutorList[], int sizeOfTutorList);