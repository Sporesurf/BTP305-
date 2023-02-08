//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <string>
#include "Racecar.h"
#include "Car.h"

using namespace std;
namespace sdds 
{
	Racecar::Racecar(istream& in) : Name::Name(in) {
		string booster;
		getline(in, booster, '\n');
		try {
			m_booster = stod(booster);
		}
		catch (...) {
			throw string("Invalid record!");
		}
	}

	void Racecar::display(ostream& out) const {
		Name::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const{
		double totalBoost = m_booster + 1;
		totalBoost *= Name::topSpeed();
		return totalBoost;
	}
}