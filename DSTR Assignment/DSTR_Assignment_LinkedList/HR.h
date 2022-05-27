#pragma once
#include <iostream>
using namespace std;

struct HumanResourceManager {
	string hrId, name, password;
	int ic, phone;
	HumanResourceManager* nextAddress;
	HumanResourceManager* prevAddress;
}*headHR, *tailHR;

HumanResourceManager* addeNewHR(string hrId, string name, int ic, int phone, string password);

void hrMenu();

void registerNewHR(HumanResourceManager* newHR);

void generateNewHR();

void displayAllHRs();
