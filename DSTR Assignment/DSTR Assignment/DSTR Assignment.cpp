#include <iostream>
#include <string>
#include "Tutor.h"
#include "Admin.h"

using namespace std;

int main() {
	int login_loop = 0; //use to loop login interface
	int sizeOfTutorList = 6;
	Tutor* tutorList = generateTutorRecord();
	int sizeOfAdminList = 6;
	Admin* adminList = generateNewAdmin();
	int logjudge = 0;
	string ID, pass, cpass;
	int choice;

	while (login_loop == 0)
	{
		//Write the login identification function here
		system("cls");
		cout << "\t----------Welcome to the system----------" << endl << endl;
		cout << "Login menu" << endl << endl;
		//function introduction
		cout << "1. Login with an existing account." << endl;
		cout << "0. Refresh and back to login system" << endl;
		cout << "-1. Quit the whole system." << endl;
		//ask choice
		cout << endl << "Please enter correct number to select what action do you want : ";

		//read choice from user
		cin >> choice;
		//check whether the user's input is valid, until get expected input
		while (cin.fail() || choice < -1 || choice > 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Please enter a correct number to select what action do you want : ";
			cin >> choice;
		}

		switch (choice)
		{
		case(-1):
		{
			system("cls");
			cout << "Quiting the system, thank you for using!" << endl;
			login_loop = choice;
			break;
		}
		case(0):
		{
			system("cls");
			login_loop = choice;
			break;
		}
		case(1):
		{
			int loop_2 = 0;
			system("cls");
			cout << "Please enter your ID: ";
			cin >> ID;
			cout << endl << "Please enter your password: ";
			cin >> pass;
			cout << endl << "please confirm your password: ";
			cin >> cpass;
			// confirm password
			while (loop_2 == 0)
			{
				if (pass != cpass)
				{
					cout << "Please reconfirm your password!" << endl;
					cout << endl << "Please enter your password: ";
					cin >> pass;
					cout << endl << "please confirm your password: ";
					cin >> cpass;
					// continue to judge
					loop_2 = 0;
				}
				else
				{
					bool jud = false;
					for (int i = 0; i < sizeOfAdminList; i++)
					{
						if (adminList[i].adminId == ID && adminList[i].password == pass)
						{
							cout << "Login success" << endl << endl;
							jud = true;
							if (ID.substr(0, 2) == "AD")
							{
								//If (when the login is admin)
								
								int choice2 = 99;
								while (choice2 != 0 && choice2 != -1)
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
									cin >> choice2;
									//check whether the user's input is valid, until get expected input
									while (cin.fail() || choice2 < -1 || choice2 > 10) {
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Invalid Input!" << endl;
										cout << "Please enter a correct number to select what action do you want : ";
										cin >> choice2;
									}

									//execute chosen function according to user's choice
									switch (choice2)
									{
									case -1:
										system("cls");
										cout << "Quiting the system, thank you for using!" << endl << endl;
										loop_2 = -1;
										login_loop = choice2;
										break;
									case 0:
										system("cls");
										loop_2 = -1;
										login_loop = choice2;
										break;
									case 1:
										system("cls");
										displayAllTutors(tutorList, sizeOfTutorList);
										break;
									case 2:
										system("cls");
										displayAllTutorsByLocation(tutorList, sizeOfTutorList);
										break;
									case 3:
									{
										system("cls");
										sortTutorById(tutorList, sizeOfTutorList);
										system("cls");
										string tutorId;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cout << "Please enter The Tutor Id that you want to search : ";
										getline(cin, tutorId);
										searchTutorById(tutorList, 0, sizeOfTutorList - 1, tutorId);
									}
									
										break;
									case 4:
										system("cls");
										cout << "choice is 4";
										break;
									case 5:
										system("cls");
										searchTutorBySubject(tutorList, sizeOfTutorList);
										break;
									case 6:
										system("cls");
										sortTutorById(tutorList, sizeOfTutorList);
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
										modifyTutorRecord(tutorList, sizeOfTutorList);
										break;
									default:
										cout << "no choice";
										break;
									}
								}
							}
							else if (ID.substr(0, 2) == "TR")
							{
								//if(µÇÂ½ÕßÎªtutorÊ±)
								//login_loop = tutorMenu(tutorList, sizeOfTutorList);
							}
							else if (ID.substr(0, 2) == "HR")
							{
								//If (when the login is HR)
								//login_loop = hrMenu(tutorList, sizeOfTutorList);
							}
						}
						//else {
							//cout << "This user does not exist!" << endl;
							//system("pause");
							//break;
						//}
					}
					if (jud == false) {
						cout << "This user does not exist!" << endl;
						system("pause");
						loop_2 = 99;
					}

				}
				
			}
		}
		}
	}
	return 0;
}