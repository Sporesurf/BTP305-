// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 09 / 26
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#define MAX_SIZE 10

#include <chrono>
#include <string>

using namespace std;
namespace sdds
{
	class TimedEvents
	{
		int currentRecords = 0;
		chrono::steady_clock::time_point m_startTime;
		chrono::steady_clock::time_point m_endTime;

		struct {
			string m_eventName;
			string m_time;
			chrono::steady_clock::duration m_eventDuration{};
		}events[MAX_SIZE];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char* name);
		friend ostream& operator<<(ostream& os, const TimedEvents& obj);
	};
}
#endif //!SDDS_TIMEDEVENTS_H