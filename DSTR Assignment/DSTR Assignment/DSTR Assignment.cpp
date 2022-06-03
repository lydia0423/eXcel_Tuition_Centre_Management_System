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
		system("cls");
		int choice = 99;
		while (choice != 0 && choice != -1)
		{
			system("cls");
			//menu content
			cout << "\t----------Welcome to Admin Menu----------" << endl << endl;
			cout << "The following actions are available for administrator : " << endl << endl;
			//function introduction
			cout << "1. Display all tutors' record." << endl;
			cout << "2. Display all tutors' record according to tutor's Location." << endl;
			cout << "3. Search tutor's record by tutor's ID." << endl;
			cout << "4. Search tutor's record by tutor's Overall Performance." << endl;
			cout << "5. Search tutor's record by tutor's Teaching Subject." << endl;
			cout << "6. Sort and display all tutor's record by tutor's ID." << endl;
			cout << "7. Sort and display all tutor's record by tutor's Overall Performance." << endl;
			cout << "8. Sort and display all tutor's record by tutor's Hourly Pay Rate." << endl;
			cout << "9. Add a record for new tutor." << endl;
			cout << "10. Modify tutor's record by tutor's ID." << endl;
			cout << "0. Logout and Go back to Login interface." << endl;
			cout << "-1. Quit the whole system." << endl;
			//ask choice
			cout << endl << "Please enter correct number to select what action do you want : ";

			//read choice from user
			cin >> choice;
			//check whether the user's input is valid, until get expected input
			while (cin.fail() || choice < -1 || choice > 10) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid Input!" << endl;
				cout << "Please enter a correct number to select what action do you want : ";
				cin >> choice;
			}

			//execute chosen function according to user's choice
			switch (choice)
			{
			case -1:
				system("cls");
				cout << "Quiting the system, thank you for using!" << endl;
				login_loop = choice;
				break;
			case 0:
				system("cls");
				login_loop = choice;
				break;
			case 1:
				system("cls");
				displayAllTutors(tutorList, sizeOfTutorList);
				break;
			case 2:
				system("cls");
				cout << "choice is 2";
				break;
			case 3:
				system("cls");
				cout << "choice is 3";
				break;
			case 4:
				system("cls");
				cout << "choice is 4";
				break;
			case 5:
				system("cls");
				cout << "choice is 5";
				break;
			case 6:
				system("cls");
				cout << "choice is 6";
				break;
			case 7:
				system("cls");
				cout << "choice is 7";
				break;
			case 8:
				system("cls");
				cout << "choice is 8";
				break;
			case 9:
			{
				system("cls");


				tutorList = addNewTutor(tutorList, sizeOfTutorList);

				sizeOfTutorList++;
			}
			break;
			case 10:
				system("cls");
				cout << "choice is 10";
				break;
			default:
				cout << "no choice";
				break;
			}
		}

		//if(登陆者为tutor时)
		//login_loop = tutorMenu(tutorList, sizeOfTutorList);
	
	}
	
	return 0;
}