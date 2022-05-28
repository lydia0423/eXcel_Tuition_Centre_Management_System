#include <iostream>
#include <string>
#include <conio.h>
#include <ctime>
#include "Tutor.h"

using namespace std;

int main()
{
	generateTutorRecord();
	//displayAllTutors();
	//displayAllTutorsByLocation();
	//mergeSortTutorByHourlyPayRate();
	//searchTutorById("tr002");
	//registerNewTutor();
	//displayAllTutors();

	searchTutorBySubject();

	return 0;
}