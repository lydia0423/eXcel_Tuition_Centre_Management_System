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

void registerNewTutor(Tutor tutorList[], int numberOfTutor);
//void saveTutor(Tutor* newTutor);
void generateTutorRecord(Tutor tutorist[]);
void displayAllTutors(Tutor tutorList[], int numberOfTutor);
//void modifyTutorRecord();
//void searchTutorById();
//void searchTutorByRating();
//void searchTutorBySubject();
//void sortTutorById();
//void sortTutorByRating();
//void sortTutorByHourlyPayRate();
//void viewProfile();
//void deleteTutorRecord();

