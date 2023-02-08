// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

using namespace std;
namespace sdds
{
	char Utilities::m_delimiter;

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		size_t t_pos = 0;
		string temp{};
		t_pos = str.find(m_delimiter, next_pos);
		if (t_pos != string::npos) {
			temp = str.substr(next_pos, t_pos - next_pos);
			more = true;
			if (str.at(next_pos) == m_delimiter)
			{
				more = false;
				throw "ERROR: NO TOKEN FOUND";
			}
		}
		else {
			more = false;
			temp = str.substr(next_pos);
		}
		if (getFieldWidth() < temp.length())
			m_widthField = temp.length();
		
		next_pos = t_pos + 1;
		return temp;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

}