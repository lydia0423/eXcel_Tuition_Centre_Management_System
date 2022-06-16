#pragma once
#include <iostream>
#include <string>

using namespace std;

struct HumanResourceManager {
	string hrId, name, password;
	int ic, phone;

	HumanResourceManager(string hrId, string name, int ic, int phone, string password);
};

int hrMenu();
