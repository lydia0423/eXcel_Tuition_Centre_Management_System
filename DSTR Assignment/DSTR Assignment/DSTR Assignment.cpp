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
		//�˴�дloginʶ����

		//if(��½��Ϊhrʱ)
		//login_loop = hrMenu(tutorList, sizeOfTutorList);

		//if(��½��Ϊadminʱ)
		login_loop = adminMenu(tutorList, sizeOfTutorList);

		//if(��½��Ϊtutorʱ)
		//login_loop = tutorMenu(tutorList, sizeOfTutorList);
	
	}
	
	return 0;
}