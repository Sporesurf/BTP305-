//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;
namespace sdds
{
	Vehicle* createInstance(istream& in)
	{
		string temp;
		string vehType;

		getline(in, temp);
		stringstream nCar(temp);
		
		getline(nCar, vehType, ',');
		vehType.erase(0, vehType.find_first_not_of("\n "));
		vehType.erase(vehType.find_last_not_of("\n ") + 1);

		if (vehType == "c" || vehType == "C")
			return new Name(nCar);
		else if (vehType == "" || vehType == " ")
			return nullptr;
		else if (vehType == "r" || vehType == "R")
			return new Racecar(nCar); 
		else 
			throw "Unrecognized record type: [" + vehType + "]";
	}
}