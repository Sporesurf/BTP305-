#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"

using namespace std;
namespace sdds
{
	Book::Book(const string& strBook)
	{
		string tempStr = strBook;
		unsigned int count = 0;

		
		count = tempStr.find(',');
		m_author = tempStr.substr(0, count);
		m_author.erase(m_author.find_last_not_of(' ') + 1);
		tempStr.erase(0, count + 1);

	
		count = tempStr.find(',');
		m_title = tempStr.substr(0, count);
		m_title.erase(m_title.find_last_not_of(' ') + 1);
		tempStr.erase(0, count + 1);

		count = tempStr.find(',');
		m_country = tempStr.substr(0, count);
		m_country.erase(m_country.find_last_not_of(' ') + 1);
		tempStr.erase(0, count + 1);

		count = tempStr.find(',');
		m_pOfBook = stod(tempStr.substr(0, count));
		tempStr.erase(0, count + 1);

		count = tempStr.find(',');
		m_year = stoi(tempStr.substr(0, count));
		tempStr.erase(0, count + 1);

		count = tempStr.find(',');
		m_description = tempStr.substr(0, count);
		m_description.erase(m_description.find_last_not_of(' ') + 1);
		tempStr.erase(0, count + 1);
	}

	ostream& operator<<(ostream& os, const Book& rhs)
	{
		os << setw(20) << rhs.m_author << " | ";
		os << setw(22) << rhs.m_title << " | ";
		os << setw(5) << rhs.m_country << " | ";
		os << setw(4) << rhs.m_year << " | ";
		os << setw(6) << setprecision(4) << rhs.m_pOfBook << " | ";
		os << rhs.m_description << endl;
		return os;
	}
}
