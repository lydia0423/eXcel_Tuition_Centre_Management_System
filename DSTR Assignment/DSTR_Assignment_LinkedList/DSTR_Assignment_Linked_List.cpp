#include <stdio.h>
#include <iostream>
#include <string>
#include "Tutor.hpp"
#include "Admin.hpp"
#include "HR.hpp"

using namespace std;

int main()
{

    generateTutorRecord();
    generateNewHRRecord();
    pair<Admin*, Admin*> temp = generateNewAdmin();
    
    int login_loop = 0; //use to loop login interface
    string ID, pass, cpass;
    int choice;
    
    Admin* headAdmin = temp.first;
    Admin* tailAdmin = temp.second;

    while (login_loop == 0)
    {
        //Write the login identification function here
        //Write the login identification function here
        system("cls");
        cout << "-----------Welcome to eXcel Tutor Management System-----------" << endl << endl;
        //function introduction
        cout << string(62, '=') << endl;
        cout << "1. Login to the system" << endl;
        cout << "0. Cancel" << endl;
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

        if (choice == 0)
        {
            //system("cls");
            cout << "Quiting the system, thank you for using!" << endl;
            //login_loop = choice;
            break;
        }
        else if (choice == 1)
        {
            bool jud = false;
            int loop_2 = 0;
            // confirm password
            while (loop_2 == 0)
            {
                system("cls");
                cout << "Please enter your ID: ";
                cin >> ID;
                cout << endl << "Please enter your password: ";
                cin >> pass;
                cout << endl << "Please confirm your password: ";
                cin >> cpass;

                if (pass != cpass)
                {
                    cout << "Please reconfirm your password!" << endl;
                    // continue to judge
                    loop_2 = 0;
                }
                else
                {
                    if (ID.substr(0, 2) == "AD")
                    {
                        Admin* iter = headAdmin;

                        if (headAdmin == tailAdmin)
                        {
                            if (iter->adminId == ID && iter->password == pass)
                            {
                                //If (when the login is admin)
                                login_loop = adminMenu();
                                jud = true;
                                break;
                            }
                        }
                        else
                        {
                            while (iter != tailAdmin)
                            {
                                if (iter->adminId == ID && iter->password == pass)
                                {
                                    //If (when the login is admin)
                                    login_loop = adminMenu();
                                    jud = true;
                                    break;
                                }
                                iter = iter->nextAddress;
                            }
                            if (iter->adminId == ID && iter->password == pass)
                            {
                                //If (when the login is admin)
                                login_loop = adminMenu();
                                jud = true;
                            }
                        }
                    }
                    else if (ID.substr(0, 2) == "HR")
                    {
                        //login_loop = hrMenu();
                        HumanResourceManager* iter = headHR;

                        if (headHR == tailHR)
                        {
                            if (iter->hrId == ID && iter->password == pass)
                            {
                                //If (when the login is admin)
                                login_loop = hrMenu();
                                jud = true;
                                break;
                            }
                        }
                        else
                        {
                            while (iter != tailHR)
                            {
                                if (iter->hrId == ID && iter->password == pass)
                                {
                                    //If (when the login is admin)
                                    login_loop = hrMenu();
                                    jud = true;
                                    break;
                                }
                                iter = iter->nextAddress;
                            }
                            if (iter->hrId == ID && iter->password == pass)
                            {
                                //If (when the login is admin)
                                login_loop = hrMenu();
                                jud = true;
                            }
                        }
                        jud = true;
                    }
                    else
                    {
                        jud = false;
                    }
                }
                if (jud == false)
                {
                    cout << endl << "Account is not found. Please try again!!" << endl;
                    system("pause");
                    loop_2 = 0;
                }
            }
        }
    }
    return 0;
}
