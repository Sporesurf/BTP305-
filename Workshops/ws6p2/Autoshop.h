// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 11 / 07
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <list>
#include <vector>
#include"Vehicle.h"

namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			for (auto& car : m_vehicles) {
				if (test(car))
					vehicles.push_back(car);
			}
		}
		~Autoshop();
	};
}

#endif