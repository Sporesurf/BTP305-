// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 09 / 19
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H

extern unsigned int g_sysClock;
namespace sdds
{
	class Event
	{
		char* eventDesc;
		unsigned int timeStart = 0;
	public:
		Event();
		void display() const;
		void set(const char desarr[]);
		void set(); //overload of set to accept no arg set in main
	};
}

#endif // SDDS_EVENT_H
