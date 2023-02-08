
#include <iostream>
#include <fstream>
#include <iomanip>
#include "SpellChecker.h"

using namespace std;
namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		ifstream file(filename);
		string tempStr;
		unsigned int count = 0;
		unsigned int i = 0;

		if (!file) {
			throw("Bad file name!");
		}

		while (getline(file, tempStr))
			if (file) {

				//find bad word
				count = tempStr.find_last_not_of(' ') + 1;
				m_badWords[i] = tempStr.substr(0, count);
				tempStr.erase(0, count + 1);

				//find good word, not sure about formating yet
				count = tempStr.find_first_not_of(' ') + 1;
				m_goodWords[i] = tempStr.substr(0, count);
				tempStr.erase(0, count + 1);
				i++;
			}
		}
		file.close();
	}

	void SpellChecker::operator()(string& text)
	{
		size_t x = 0;
		for (size_t i = 0; i < 6; i++)
		{
			size_t counter = 0;
			do
			{
				x = text.find(m_badWords[i]);
				text.replace(x, m_badWords[i].length(), m_goodWords[i]);
				counter++;
				if (i == 4 && replacements[i] == 5)
					replacements[i] = 4;
			} while (x != string::npos);
		}
	}

	void SpellChecker::showStatistics(ostream& out) const
	{
		out << "Spellchecker Statistics" << endl;
		for (size_t i = 0; i < 6; i++)
		{
			out << setw(15) << m_badWords[i] << ": " << replacements[i] << " replacements" << endl;
		}
	}
}