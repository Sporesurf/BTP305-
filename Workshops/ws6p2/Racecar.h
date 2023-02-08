//Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include"Car.h"

namespace sdds {
	class Racecar : public Plane {
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}
#endif