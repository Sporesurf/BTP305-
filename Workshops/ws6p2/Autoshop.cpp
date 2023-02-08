//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "Autoshop.h"

using namespace std;
namespace sdds
{
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);
		return *this;
	}

	void Autoshop::display(ostream& out) const {
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		for (auto& car : m_vehicles) {
			car->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop() { for (auto& car : m_vehicles) delete car; }
}