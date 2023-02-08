// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 11
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
namespace sdds
{
	class Restaurant
	{
		Reservation* resObj{};
		size_t noOfObjects{};
	public:
		Restaurant() {};
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		friend ostream& operator<<(ostream& os, const Restaurant& rhs);

		//COPY CONST, ASSIGNEMNT OPS
		Restaurant(const Restaurant& obj);
		Restaurant& operator=(const Restaurant& obj);
		Restaurant(Restaurant&& obj) noexcept;
		Restaurant& operator=(Restaurant&& obj) noexcept;

		~Restaurant() { delete[] this->resObj; }
	};
}
#endif // !SDDS_RESTAURANT_H
