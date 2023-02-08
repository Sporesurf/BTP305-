// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/12/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

using namespace std;
namespace sdds
{
	deque<CustomerOrder> pending;
	deque<CustomerOrder> completed;
	deque<CustomerOrder> incomplete;

	void Workstation::fill(ostream& os)
	{
		if (m_orders.empty() == false)
			m_orders.front().fillItem(*this, os);
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool movedOrder = false;
		if (m_orders.empty() == false)
		{
			CustomerOrder& n_order = m_orders.front();
			if (n_order.isItemFilled(getItemName()) || getQuantity() == 0)
			{
				if (m_pNextStation != nullptr)
				{
					*m_pNextStation += move(n_order);
					m_orders.pop_front();
				}
				else
				{
					if (n_order.isFilled())
					{
						completed.push_back(move(n_order));
						m_orders.pop_front();
					}
					else
					{
						incomplete.push_back(move(n_order));
					}
					movedOrder = true;
					return movedOrder;
				}
			}
		}
		return movedOrder;
	}

	void Workstation::setNextStation(Workstation* station = nullptr)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(ostream& os) const
	{
		os << getItemName() << " --> ";
		os << (m_pNextStation != nullptr ? m_pNextStation->getItemName() : "End of Line") << endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(move(newOrder));
		return *this;
	}

}