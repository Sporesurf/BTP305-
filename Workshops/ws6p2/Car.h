//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include <iostream>
#include"Vehicle.h"

namespace sdds {
	class Name : public Vehicle {
		std::string m_condition;
		std::string m_make;
		double m_topspeed;
	public:
		Name(std::istream& infile);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}
#endif



