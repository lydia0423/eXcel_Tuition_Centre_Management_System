#include <iostream>
#include <string>
#include "Tutor.h"

using namespace std;

int main() {
	int login_loop = 0;
	int sizeOfTutorList = 6;
	Tutor* tutorList = generateTutorRecord();

	while (login_loop == 0)
	{
		login_loop = adminMenu(tutorList, sizeOfTutorList);
	}
	

	
	return 0;
}