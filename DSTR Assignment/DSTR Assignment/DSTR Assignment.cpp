#include <iostream>
#include <string>

#include "Tutor.h"

using namespace std;

int main() {
	int numberOfTutor = 3;
	Tutor* tutorList = new Tutor[numberOfTutor];
	generateTutorRecord(tutorList);
	//displayAllTutors();

	numberOfTutor++;
	Tutor* tutorList = new Tutor[numberOfTutor];
	registerNewTutor(tutorList, numberOfTutor);
	displayAllTutors(tutorList, numberOfTutor);

	return 0;
}