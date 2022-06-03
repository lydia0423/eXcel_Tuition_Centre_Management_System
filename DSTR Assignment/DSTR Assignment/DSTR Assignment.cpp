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
		//此处写login识别功能

		//if(登陆者为hr时)
		//login_loop = hrMenu(tutorList, sizeOfTutorList);

		//if(登陆者为admin时)
		login_loop = adminMenu(tutorList, sizeOfTutorList);

		//if(登陆者为tutor时)
		//login_loop = tutorMenu(tutorList, sizeOfTutorList);
	
	}
	
	return 0;
}