// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/11/26
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H
#include <string>
#include <iostream>
#include <iomanip>
#include "Station.h"
#include "Utilities.h"

//The CustomerOrder module contains all the functionality 
//for processing customer orders as they move from Station to
//Station along the assembly line.The Station where a given 
//order currently rests fills a request for one item of that 
//station, if there is any such request.

namespace sdds
{
	class CustomerOrder
	{
		struct Item
		{
			std::string m_itemName;
			size_t m_serialNumber{ 0 };
			bool m_isFilled{ false };
			Item(const std::string& src) : m_itemName(src) {};
		};
		std::string m_name = "";
		std::string m_product = ""; 
		size_t m_cntItem = 0;
		Item** m_lstItem = nullptr;
		static size_t m_widthField;
	public:
		//Default Constructor
		CustomerOrder();
		//Extracts a record, add each item to m_lst dble ptr.
		CustomerOrder(const std::string& n_record);
		//Copy operations deleted, throw exception if construct called.
		CustomerOrder(const CustomerOrder& rhs);
		CustomerOrder& operator=(const CustomerOrder& rhs) = delete;
		//Move constructor, no exceptions.
		CustomerOrder(CustomerOrder&& rhs) noexcept;
		//Move assignment operator, no exceptions.
		CustomerOrder& operator=(CustomerOrder&& rhs) noexcept;
		//Customer operator for Updating cnt, resize Item** array dynamically.
		CustomerOrder& operator+=(Item* n_item);
		//Returns true if all items filled, false else
		bool isFilled() const;
		//Iterates through m_lst double ptr and checks if items are filled. True if no match
		bool isItemFilled(const std::string& itemName) const;
		//Modifier, fills all items in current order.
		void fillItem(Station& station, std::ostream& os);
		//Displays current object state.
		void display(std::ostream& os) const;
		//Destructor, manages dynamic memory in m_lstItem
		~CustomerOrder();
	};
}
#endif