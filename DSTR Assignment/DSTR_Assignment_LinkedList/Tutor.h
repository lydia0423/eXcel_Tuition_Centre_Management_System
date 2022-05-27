#pragma once
#include <iostream>

using namespace std;

struct Tutor {
	string tutorId, name, dateJoined, dateTerminated, fieldOfStudy, address, tuitionCenterCode, tuitionCenterName, subjectCode, subjectName, password;
	int phone, rating, ic;
	double hourlyPayRate, experience;
	Tutor *nextAddress;
	Tutor *prevAddress;
};

Tutor* addNewTutor(string tutorId, string name, int ic, string fieldOfStudy, string address, int phone, string dateJoined, string dateTerminated,
	string tuitionCenterCode, string tuitionCenterName, string subjectCode, string subjectName, string password,
	double hourlyPayRate, double experience, int rating);

int tutorMenu();

void registerNewTutor();

void saveTutor(Tutor *newTutor);

void generateTutorRecord();

void displayAllTutors();

void displayAllTutorsByLocation();

//void modifyTutorRecord();

void searchTutorById(string tutorId);

//void searchTutorByRating();

//void searchTutorBySubject();

//void sortTutorById();

//void sortTutorByRating();

void mergeSortTutorByHourlyPayRate();

//void viewProfile();

//void deleteTutorRecord();

void getCurrentDateTime();

