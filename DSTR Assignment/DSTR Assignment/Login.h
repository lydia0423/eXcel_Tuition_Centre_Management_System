#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Login{
	string account, password;
	int authority;

	Login();
	Login(string account, string password, int authority);
};

int Loginmenu;
Login* generateLoginRecord();
