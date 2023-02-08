// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/12/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

/*The LineManager module first configures the assembly
line and then moves CustomerOrders along it (from start to finish).
The LineManager object configures the Workstation objects identified by the user,
and moves orders along the line one step at a time. A Workstation is a Station that
the LineManager has activated on the user's request. At each step, every Workstation fills
one item in a Customer Order, if possible. The manager moves orders from station to station.
Once an order has reached the end of the line, it is either complete or incomplete. An order
is incomplete if one or more stations had an insufficient number of items in stock to cover
that order's requests.*/

namespace sdds
{
	//Holds the orders to be placed onto the assembly line at the first station.
	extern std::deque <CustomerOrder> pending;
	//Holds the orders that have been removed from the last stationand have been completely filled.
	extern std::deque <CustomerOrder> completed;
	//Holds the orders that have been removed from the last station and could not be filled completely.
	extern std::deque <CustomerOrder> incomplete;

	class Workstation : public Station
	{
		//Orders placed on station to recieve service(or already serviced).
		std::deque<CustomerOrder> m_orders;
		//Pointer to next workstation on assembly line.
		Workstation* m_pNextStation = nullptr;
	public:
		//Object cannot be copied OR moved.
		Workstation(const Workstation&) = delete;
		Workstation& operator=(const Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

		//Receives a reference to an unmodifiable string, passes to stantion base class.
		Workstation(const std::string& new_record) : Station(new_record) {};
		//Attempts to fill order at front of queue. else do nothing.
		void fill(std::ostream& os);
		//Attempts to move the order order at the front of the queue to the next station in the assembly line.
		bool attemptToMoveOrder();
		//Stores address of referenced Workstation pointing to m_pNextPstation. defaults to null.
		void setNextStation(Workstation* station);
		//Returns address of next Workstation.
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);
	};
}
#endif //! SDDS_WORKSTATION_H