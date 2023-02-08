// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 11
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iostream>

using namespace std;
namespace sdds
{
	class Reservation
	{
		string resID{};
		string resName{};
		string resEmail{};
		unsigned int noOfPeople{};
		unsigned int resDay{};
		unsigned int resHour{};
	public:
		Reservation() {};
		void update(int day, int time);
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& rhs);
	};
}
#endif // !SDDS_RESERVATION_H
