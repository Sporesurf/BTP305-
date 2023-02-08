// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 09 / 26
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_STRINGSET_H
#define SDDS_STRINGSET_H

#include <string>

using namespace std;
namespace sdds
{
	class StringSet
	{
		string* m_string = nullptr;
		size_t m_noOfRecords = 0;
	public:
		StringSet();
		StringSet(const char* fname);
		size_t size();
		string operator[](size_t position);
		StringSet(const StringSet& src);
		StringSet(StringSet&& src) noexcept;
		StringSet& operator=(const StringSet& src);
		StringSet& operator=(StringSet&& src) noexcept;
		~StringSet();
	};
}
#endif // !SDDS_STRINGSET_H
