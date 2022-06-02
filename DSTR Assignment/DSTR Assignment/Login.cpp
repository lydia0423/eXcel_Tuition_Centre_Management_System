#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <string>
#include <ctime>
#include "Login.h"

string account, password;
int authority;

Login::Login(){}

Login::Login(string account, string password, int authority){
  this->account = account;
  this->password = account;
  this->authority = authority;
}

Login* generateLoginRecord(){
  Login* loginList = new Login[6];

  loginList[0] = Login("30001", "123456", 1);
  loginList[1] = Login("30002", "123456", 1);
  loginList[2] = Login("30003", "123456", 1);
  loginList[3] = Login("30004", "123456", 1);
  loginList[4] = Login("30005", "123456", 1);
  loginList[5] = Login("30006", "123456", 1);
	
	return loginList;
}

int Loginmenu(){
  system("cls");
  int choice = 99;
  
  while(choice != 0 && choice != -1){
    //menu content
		 cout << "\t----------Welcome to the system----------" << endl << endl;
		 cout << "Please log in first" << endl << endl;
		 //function introduction
     cout << "2. Register" << endl;
		 cout << "1. Login with an existing account." << endl;
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
         return choice;
       case 0:
         system("cls");
         return choice;
       case 1:
         system("cls");
         cout << "please enter your account" << endl;
         String acc,pass,cpass;
         cin >> acc;
         cout << "please enter your password" << endl;
         cin >> pass;
         cout << "please confirm your password" << endl;
         cin >> cpass;
         if (pass != cpass)
         {
           cout<<"please reconfirm your password"<< endl;
         }
         else
         {
             for (int i = 0; i < loginList.size(); i++) {
             if (loginList[i].account == acc && loginList[i].password = pass){
                cout << "choice is 1";
             }
             else
             {
               cout<<"Wrong accout or password"<<endl;
             }
          }
         break;
       case 2:
         system("cls");
         cout << "choice is 2";
         break;
       default:
         cout << "no choice";
         break;
		 }
  }
}
