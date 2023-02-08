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
		Reservation(){};
		void update(int day, int time);
		Reservation(const string& res);
		friend ostream& operator<<(ostream& os, const Reservation& rhs);
	};
}
#endif // !SDDS_RESERVATION_H
