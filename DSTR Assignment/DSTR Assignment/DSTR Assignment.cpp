#include <iostream>
#include <string>

#include "Tutor.h"

using namespace std;

int main() {
	int numberOfTutor = 3;
	Tutor* tutorList = new Tutor[numberOfTutor];
	generateTutorRecord(tutorList);
	//displayAllTutors();

	/*numberOfTutor++;
	Tutor* tutorList = new Tutor[numberOfTutor];
	registerNewTutor(tutorList, numberOfTutor);*/
	//displayAllTutors(tutorList, numberOfTutor);

	/*int sizeOfTutorList = 3;
	int endIndex = sizeOfTutorList - 1;
	Tutor* temp = new Tutor[sizeOfTutorList];
	sortTutorByHourlyPayRate(tutorList, 0, endIndex, temp);

	searchTutorById(tutorList, 0, endIndex, "TR002");*/

	return 0;
}