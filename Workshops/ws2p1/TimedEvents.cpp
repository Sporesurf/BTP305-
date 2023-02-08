// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 09 / 26
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <chrono>
#include <iomanip>
#include "TimedEvents.h"

using namespace std;
namespace sdds
{
	TimedEvents::TimedEvents(){
		currentRecords = 0;
	}

	void TimedEvents::startClock(){
		m_startTime = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock(){
		m_endTime = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name) {
		if (currentRecords < MAX_SIZE && name != nullptr)
		{
			events[currentRecords].m_eventName = name;
			events[currentRecords].m_time = "nanoseconds";
			events[currentRecords].m_eventDuration = 
				chrono::duration_cast<chrono::nanoseconds>(m_endTime - m_startTime);
			currentRecords++;
		}
	}

	ostream& operator<<(ostream& os, const TimedEvents& obj) {
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (int i = 0; i < obj.currentRecords; i++)
		{
			os << left << setw(21) << obj.events[i].m_eventName;
			os << right << setw(13) << obj.events[i].m_eventDuration.count()
				<< " " << obj.events[i].m_time << endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}