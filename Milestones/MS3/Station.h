// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>

//A Station object manages a single station on the assembly line. Each station
//handles a specific item for filling customer orders.

namespace sdds
{
	class Station
	{
		int m_stationId;
		std::string m_desc;
		std::string m_itemName;
		unsigned int m_serialNum;
		unsigned int m_noOfItems;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station(const std::string& new_record);
		//Returns the name of the current Station object
		const std::string& getItemName() const;
		//Returns the next serial number to be used on the assembly line and increments m_serialNumber
		size_t getNextSerialNumber();
		//Returns the remaining quantity of items in the Station object
		size_t getQuantity() const;
		//Subtracts 1 from the available quantity; should not drop below 0.
		void updateQuantity();
		// Inserts information about the current object into stream
		void display(std::ostream& os, bool full) const;
	};
}
#endif