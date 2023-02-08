// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds 
{
	size_t Station::m_widthField = 0;
	size_t Station::id_generator = 0;

	Station::Station(const string& new_record) 
	{
		Utilities n_obj;
		id_generator++;
		m_stationId = id_generator;

		size_t n_pos = 0;
		bool more = false;

		m_itemName = n_obj.extractToken(new_record, n_pos, more);
		m_serialNum = stoi(n_obj.extractToken(new_record, n_pos, more));
		m_noOfItems = stoi(n_obj.extractToken(new_record, n_pos, more));

		if (m_widthField <= n_obj.getFieldWidth())
			m_widthField = n_obj.getFieldWidth();
		m_desc = n_obj.extractToken(new_record, n_pos, more);
	}

	const string& Station::getItemName() const 
	{ 
		return m_itemName; 
	}

	size_t Station::getNextSerialNumber() 
	{ 
		return m_serialNum++;
	}

	size_t Station::getQuantity() const 
	{ 
		return m_noOfItems; 
	}

	void Station::updateQuantity() {
		if (m_noOfItems - 1 < 0)
			m_noOfItems = 0;
		else 
			m_noOfItems--;
	}

	void Station:: display(std::ostream& os, bool full) const 
	{

		os << "[" << setw(u_idField) << right << setfill('0') << m_stationId << "]" << setfill(' ');
		os << " Item: " << setw(m_widthField) << left << m_itemName << setfill(' ');
		os << " [" << setw(u_serialField) << right << setfill('0') << m_serialNum << "]" << setfill(' ');

		if (full)
		{
			os << " Quantity: " << setw(m_widthField) << left << m_noOfItems << setfill(' ');
			os << " Description: " << m_desc;
			os << endl;
		}
		else 
			os << endl;
	}
}