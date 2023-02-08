//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <sstream>
#include <iomanip>
#include "Car.h"

using namespace std;
namespace sdds 
{
	Name::Name(istream& infile) {
		getline(infile, m_make, ',');
		m_make.erase(0, m_make.find_first_not_of("\n "));
		m_make.erase(m_make.find_last_not_of("\n ") + 1);

		getline(infile, m_condition, ',');
		m_condition.erase(0, m_condition.find_first_not_of("\n "));
		m_condition.erase(m_condition.find_last_not_of("\n ") + 1);

		bool state = m_condition == " " || m_condition == "";
		if (m_condition == "n" || m_condition == "N" || state) { 
			m_condition = "new"; 
		}
		else if (m_condition == "u" || m_condition == "U") {
			m_condition = "used"; 		
		}
		else if (m_condition == "b" || m_condition == "B") {
			m_condition = "broken";
		}
		else { 
			throw string("Invalid record!");
		}
		string topspeed;
		getline(infile, topspeed, ',');
		topspeed.erase(0, topspeed.find_first_not_of("\n "));
		topspeed.erase(topspeed.find_last_not_of("\n ") + 1);
		try {
			m_topspeed = stod(topspeed);
		}
		catch (...) {
			throw string("Invalid record!");
		}
	}

	string Name::condition() const { 
		return m_condition;
	}

	double Name::topSpeed() const { 
		return m_topspeed; 
	}

	void Name::display(ostream& out) const {
		out << "| " << setw(10) << right << m_make << " | "  << setw(6) << left <<
		m_condition << " | " << setw(6) << fixed << setprecision(2) << topSpeed() << " |";
	}
}