#pragma once
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include "Book.h"
#include "Movie.h"

using namespace std;
namespace sdds
{
	/*When a new item is added to the collection, this class informs the client using a callback function.*/
	template <class T>
	class Collection
	{
		string m_title;
		T* m_items;
		size_t m_noOfItems;
		//This is the observer function (it observes an event):
		//when an item has been added to the collection, the class Collection<T> will call this function informing the client about the addition.
		void(*itemAdded)(const Collection<T>&, const T&);
	public:
		Collection(const string& name)
		{
			this->m_title = name;
			m_items = T();
			m_noOfItems = 0;
		}

		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		//DELETE MOVE OPERATIONS?

		const string& name() const{ return m_title; }

		size_t size()const { return m_noOfItems; }

		void setObserver(void (*observer)(const Collection<T>&, const T&)) { *itemsAdded = observer; }

		//ASSUMPTION: type T has a member function 
		//called title() that returns the title of the item (std::string).
		Collection<T>& operator+=(const T& item)
		{
			bool found = false;
			for (size_t i = 0; i < m_noOfItems && !found; i++)
			{
				if (item.title() == m_items[i].title()) { // changed name to title
					found = true;
				}
				if (!found) {
					//resizes the array of items to accommodate the new item
					T* newArr = new T[m_noOfItems + 1];
					//if an observer has been registered, this operator calls the observer function passing the current object(*this) and the new item as arguments.
					if (itemsAdded)
						setObserver(*this, item);
					//	ASSUMPTION: type T has a member function called title() that returns the title of the item(std::string).
				}
			}
		}

		T& operator[](size_t idx) const { 
			if (idx > m_noOfItems) {
				throw out_of_range("Bad Index [" + to_string(idx) + "]. Collection has [" + to_string(m_noOfItems) + "] items.");
			}
			return m_items[idx];
		}

		T* operator[](const string& title) const
		{
			for (size_t i = 0; i < m_noOfItems; i++)
			{
				if (m_items[i].title() == title)
					return *m_items[i];
			}
			//if no such item exists return nullptr
			return nullptr;
		}

		friend ostream& operator<<(ostream& os, const Collection& rhs)
		{
			for (size_t = 0; i < m_noOfItem; i++)
			{
				os << m_items[i];
			}
		}

		~Collection() {};
	};
}
#endif // !SDDS_COLLECTION_H

