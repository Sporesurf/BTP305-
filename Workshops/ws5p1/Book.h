#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>

using namespace std;
namespace sdds
{
	class Book
	{
		string m_author;
		string m_title;
		string m_country;
		size_t m_year;
		double m_pOfBook; //price of book
		string m_description;
	public:
		Book() {};
		const string& title() const { return m_title; }
		const string& country() const { return m_country; }
		const size_t& year() const { return m_year; }
		//Return price by reference, client code update price
		double& price() { return m_pOfBook; }
		Book(const string& strBook);
		friend ostream& operator<<(ostream& os, const Book& rhs);
	};
}
#endif // !SDDS_BOOK_H