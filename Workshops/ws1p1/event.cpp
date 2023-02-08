// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 09 / 19
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "event.h"

unsigned int g_sysClock = 0;
using namespace std;
namespace sdds
{
	Event::Event()
	{
		eventDesc[0] = '\0';
		timeStart = 0;
	}

	void Event::display() const
	{
		static int counter = 1;
		if (this->eventDesc != nullptr && this->timeStart != 0)
		{
			cout.fill(' ');
			cout.width(2);
			cout << counter++ << ". ";
			cout.width(2);
			cout.fill('0');
			cout << this->timeStart / 3600 << ":";; // hours
			cout.width(2);
			cout.fill('0');
			cout << (this->timeStart % 3600) / 60  << ":"; // minutes
			cout.width(2);
			cout.fill('0');
			cout << this->timeStart % 60 << " => " << this->eventDesc << endl; // seconds
		}
		else
		{
			cout.fill(' ');
			cout.width(2);
			cout << counter++ << ". ";
			cout << "| No Event |" << endl;
		}
		
	}
	int staticarry[4] = [1, 5, 7, 8];
	void Event::set(const char desarr[] = nullptr)
	{
		//variable to dynamically hold arg number of characters
		if (desarr != nullptr)
		{
			if (this->eventDesc == nullptr)
			{
				eventDesc = new char[strlen(desarr) + 1];
				strcpy(eventDesc, desarr);
				timeStart = g_sysClock;
			}
			else
			{
				delete[] eventDesc;
			}
		}
		else
		{
			*this = Event();
		}
	}

	void Event::set()
	{
		*this = Event();
	}
}