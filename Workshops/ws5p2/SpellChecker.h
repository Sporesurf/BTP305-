#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <string>

using namespace std;
namespace sdds
{
	class SpellChecker
	{
		static string m_badWords[6];
		static string m_goodWords[6];
		size_t replacements[6]{};
	public:
		SpellChecker() {};
		SpellChecker(const char* filename);
		void operator()(string& text);
		void showStatistics(ostream& out) const;
	};
}
#endif // !SDDS_SPELLCHECKER_H
