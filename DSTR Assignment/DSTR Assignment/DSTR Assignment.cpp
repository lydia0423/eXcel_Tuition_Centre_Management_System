#include <iostream>
#include <string>
#include <chrono>
#include "Tutor.h"
#include "Admin.h"

using namespace std;

int main() {
	int login_loop = 0; //use to loop login interface
	int sizeOfTutorList = 12;
	Tutor* tutorList = generateTutorRecord();
	int sizeOfAdminList = 6;
	Admin* adminList = generateNewAdmin();
	int logjudge = 0;
	string ID, pass, cpass;
	int choice;
	Tutor* temp = new Tutor[sizeOfTutorList];
	using std::chrono::high_resolution_clock;
	using std::chrono::duration_cast;
	using std::chrono::duration;
	using std::chrono::milliseconds;
	
	while (login_loop == 0)
	{
		//Write the login identification function here
		system("cls");
		cout << "-----------Welcome to eXcel Tutor Management System-----------" << endl << endl;
		//function introduction
		cout << string(62, '=') << endl;
		cout << "1. Login " << endl;
		cout << "0. Quit the system" << endl;
		//ask choice
		cout << endl << "Your choice: ";

		//read choice from user
		cin >> choice;
		//check whether the user's input is valid, until get expected input
		while (cin.fail() || choice < 0 || choice > 1)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input!" << endl;
			cout << "Please enter a correct number to select what action do you want : ";
			cin >> choice;
		}

		switch (choice)
		{
		case 0:
		{
			system("cls");
			cout << "Quiting the system, thank you for using!" << endl;
			login_loop = 99;
			break;
		}
		case 1:
		{
			int loop_2 = 0;
			// confirm password
			while (loop_2 == 0)
			{
				system("cls");
				cout << "Please enter your ID as username: ";
				cin >> ID;
				cout << endl << "Please enter your password: ";
				cin >> pass;
				cout << endl << "Please confirm your password: ";
				cin >> cpass;

				if (pass != cpass)
				{
					//cout << "Please reconfirm your password!" << endl;
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
									cout << "----------------------------Welcome to Admin Menu----------------------------" << endl << endl;
									cout << "The following actions are available for administrator : " << endl << endl;
									//function introduction
									cout << "1.  Display all tutors' record." << endl;
									cout << "2.  Display all tutors' record according to tutor's Location." << endl;
									cout << "3.  Search tutor's record by tutor's ID." << endl;
									cout << "4.  Search tutor's record by tutor's Overall Performance." << endl;
									cout << "5.  Search tutor's record by tutor's Teaching Subject." << endl;
									cout << "6.  Sort and display all tutor's record by tutor's ID." << endl;
									cout << "7.  Sort and display all tutor's record by tutor's Overall Performance." << endl;
									cout << "8.  Sort and display all tutor's record by tutor's Hourly Pay Rate." << endl;
									cout << "9.  Add a record for new tutor." << endl;
									cout << "10. Modify tutor's record by tutor's ID." << endl;
									cout << "0.  Logout and Go back to Login interface." << endl;
									cout << "-1. Quit the whole system." << endl;
									//ask choice
									cout << endl << "Please enter your choice : ";

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
										cout << "Exiting the system, thank you for using!" << endl << endl;
										loop_2 = -1;
										login_loop = choice2;
										jud = true;
										break;
									case 0:
										system("cls");
										loop_2 = -1;
										login_loop = choice2;
										jud = true;
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
										sortTutorById(tutorList, sizeOfTutorList, 2);
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
										int rating;
										cout << "Please enter The Tutor Overall Performance that you want to search : ";
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> rating;
										searchTutorByRating(tutorList, sizeOfTutorList, rating);
										break;
									case 5:
										system("cls");
										searchTutorBySubject(tutorList, sizeOfTutorList);
										break;
									case 6:
										system("cls");
										sortTutorById(tutorList, sizeOfTutorList, 1);
										displayAllTutors(tutorList, sizeOfTutorList);
										break;
									case 7:
										system("cls");
										sortTutorByRating(tutorList, sizeOfTutorList);
										break;
									case 8:
									{
										system("cls");
										auto t1 = high_resolution_clock::now();
										sortTutorByHourlyPayRate(tutorList, 0, sizeOfTutorList - 1, temp);
										displayAllTutors(temp, sizeOfTutorList);
										cout << endl << endl;
										auto t2 = high_resolution_clock::now();
										duration<double, std::milli> ms_double = t2 - t1;
										std::cout << "Execution time : " << ms_double.count() << "ms\n";
									}
										break;
									case 9:
									{
										system("cls");
										string centerCode;

										cout << "The format of Cent Code is 'TCxxx'." << endl << "Please enter the Center Code of which center do you want to add: ";
										cin >> centerCode;
										while (cin.fail()) {
											cin.clear();
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											cout << "Invalid Input!" << endl;
											cout << "Please enter correct Center Code: ";
											cin >> centerCode;
										}
										bool addFlag = checkCenter(tutorList, sizeOfTutorList, centerCode);
										if (addFlag == true) {
											system("cls");
											cout << "Can add a new tutor to this center." << endl;
											tutorList = addNewTutor(tutorList, sizeOfTutorList, centerCode);
											sizeOfTutorList++;
										}
										else {
											cout << endl << "Cannot add new tutor to this center because it is already full." << endl;
											system("pause");
										}									
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
							else if (ID.substr(0, 2) == "HR")
							{
								int choice2 = 99;
								while (choice2 != 0 && choice2 != -1)
								{
									system("cls");
									//menu content
									cout << "----------------------------Welcome to HR Menu----------------------------" << endl << endl;
									cout << "The following actions are available for administrator : " << endl << endl;
									//function introduction
									cout << "1.  Display all tutors' record." << endl;
									cout << "2.  Display all tutors' record according to tutor's Location." << endl;
									cout << "3.  Search tutor's record by tutor's ID." << endl;
									cout << "4.  Search tutor's record by tutor's Overall Performance." << endl;
									cout << "5.  Search tutor's record by tutor's Teaching Subject." << endl;
									cout << "6.  Sort and display all tutor's record by tutor's ID." << endl;
									cout << "7.  Sort and display all tutor's record by tutor's Overall Performance." << endl;
									cout << "8.  Sort and display all tutor's record by tutor's Hourly Pay Rate." << endl;
									cout << "9.  Add a record for new tutor." << endl;
									cout << "10. Modify tutor's record by tutor's ID." << endl;
									cout << "11. Delete tutor's record" << endl;
									cout << "0.  Logout and Go back to Login interface." << endl;
									cout << "-1. Quit the whole system." << endl;
									//ask choice
									cout << endl << "Please enter your choice : ";

									//read choice from user
									cin >> choice2;
									//check whether the user's input is valid, until get expected input
									while (cin.fail() || choice2 < -1 || choice2 > 11) {
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
										cout << "Exiting the system, thank you for using!" << endl << endl;
										loop_2 = -1;
										login_loop = choice2;
										jud = true;
										break;
									case 0:
										system("cls");
										loop_2 = -1;
										login_loop = choice2;
										jud = true;
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
										sortTutorById(tutorList, sizeOfTutorList, 2);
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
										int rating;
										cout << "Please enter The Tutor Overall Performance that you want to search : ";
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> rating;
										searchTutorByRating(tutorList, sizeOfTutorList, rating);
										break;
									case 5:
										system("cls");
										searchTutorBySubject(tutorList, sizeOfTutorList);
										break;
									case 6:
										system("cls");
										sortTutorById(tutorList, sizeOfTutorList, 1);
										break;
									case 7:
										system("cls");
										sortTutorByRating(tutorList, sizeOfTutorList);
										break;
									case 8:
									{
										system("cls");
										auto t1 = high_resolution_clock::now();
										sortTutorByHourlyPayRate(tutorList, 0, sizeOfTutorList - 1, temp);
										displayAllTutors(temp, sizeOfTutorList);
										cout << endl << endl;
										 auto t2 = high_resolution_clock::now();
										 duration<double, std::milli> ms_double = t2 - t1;
										 std::cout << "Execution time : " << ms_double.count() << "ms\n";
									}
										break;
									case 9:
									{
										system("cls");
										string centerCode;

										cout << "The format of Cent Code is 'TCxxx'." << endl << "Please enter the Center Code of which center do you want to add: ";
										cin >> centerCode;
										bool addFlag = checkCenter(tutorList, sizeOfTutorList, centerCode);
										if (addFlag == true) {
											system("cls");
											cout << "Can add a new tutor to this center." << endl;
											tutorList = addNewTutor(tutorList, sizeOfTutorList, centerCode);
											sizeOfTutorList++;
										}
										else {
											cout << endl << "Cannot add new tutor to this center because it is already full." << endl;
											system("pause");
										}
									}
									break;
									case 10:
										system("cls");
										modifyTutorRecord(tutorList, sizeOfTutorList);
										break;
									case 11:
										system("cls");
										sizeOfTutorList = deleteTutorRecord(tutorList, sizeOfTutorList);
										cout << "Now there are " << sizeOfTutorList << " records of tutors." << endl;
										break;
									default:
										cout << "no choice";
										break;
									}
								}
							}
						}
						

					}
					if (jud == false) {
						system("cls");
						int loginFailChoice;
						cout << endl << "The Account or Password is wrong!" << endl;
						cout << endl << "If you want to back to login menu please enter 1.\nIf you want to re-login please enter 2.";
						cout << endl << "Please enter your choice here: ";

						
						cin >> loginFailChoice;
						//check whether the user's input is valid, until get expected input
						while (cin.fail() || loginFailChoice < 1 || loginFailChoice > 2)
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Invalid Input!" << endl;
							cout << "Please enter a correct number of your choice: ";
							cin >> loginFailChoice;
						}
						if (loginFailChoice == 1) {
							loop_2 = 1;
						}
						else if (loginFailChoice == 2) {
							loop_2 = 0;
						}
						//system("pause");
						
					}

				}

			}
		}
		}
	}
	return 0;
}