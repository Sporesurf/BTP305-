// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 11
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
#include <iostream>
#include <string>
#include <iomanip>
#include "Reservation.h"

using namespace std;
namespace sdds
{
	void Reservation::update(int day, int time)
	{
		this->resDay = day;
		this->resHour = time;
	}

	Reservation::Reservation(const string& res)
	{
		string tmpStr = res;
		unsigned int count = 0;
		count = tmpStr.find(':');
		resID = tmpStr.substr(0, count);
		resID.erase(resID.find_last_not_of(' ') + 1);
		tmpStr.erase(0, count + 1);

		count = tmpStr.find(',');
		resName = tmpStr.substr(0, count);
		resName.erase(resName.find_last_not_of(' ') + 1);
		tmpStr.erase(0, count + 1);

		tmpStr.erase(0, tmpStr.find_first_not_of(' '));
		count = tmpStr.find(',');
		resEmail = tmpStr.substr(0, count);
		resEmail.erase(resEmail.find_last_not_of(' ') + 1);
		tmpStr.erase(0, count + 1);

		count = tmpStr.find(',');
		noOfPeople = stoi(tmpStr.substr(0, count));
		tmpStr.erase(0, count + 1);

		count = tmpStr.find(',');
		resDay = stoi(tmpStr.substr(0, count));
		tmpStr.erase(0, count + 1);

		count = tmpStr.find(',');
		resHour = stoi(tmpStr.substr(0, count));
		tmpStr.erase(0, count + 1);
	}

	ostream& operator<<(ostream& os, const Reservation& rhs)
	{
		string meal{};
		os << "Reservation " << setw(10) << right << rhs.resID << ": ";
		os << setw(20) << right << rhs.resName << "  ";
		os << setw(20) << left << '<' + rhs.resEmail + '>' << "    ";

		//Recieve type of meal for os
		if (rhs.resHour >= 6 && rhs.resHour <= 9) {
			meal = "Breakfast";
		}
		else if (rhs.resHour >= 11 && rhs.resHour <= 15) {
			meal = "Lunch";
		}
		else if (rhs.resHour >= 17 && rhs.resHour <= 21) {
			meal = "Dinner";
		}
		else {
			meal = "Drinks";
		}

		os << meal << " on day " << rhs.resDay << " @ ";
		os << rhs.resHour << ":00 for ";
		os << rhs.noOfPeople;

		//Output depending on # of people
		if (rhs.noOfPeople > 1)
			os << " people.";
		else {
			os << " person.";
		}
		os << endl;
		return os;
	}
}