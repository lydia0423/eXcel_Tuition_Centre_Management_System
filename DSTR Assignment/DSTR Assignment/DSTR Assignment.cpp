#include <iostream>
#include <string>
#include "Tutor.h"

using namespace std;

int main() {
	int sizeOfTutorList = 6;
	Tutor* tutorList = generateTutorRecord();

	
	

	adminMenu(tutorList, sizeOfTutorList);
	return 0;
}