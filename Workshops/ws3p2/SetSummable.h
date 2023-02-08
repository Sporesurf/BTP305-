// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 03
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include <iostream>
#include "Set.h"

using namespace std;
namespace sdds
{
	template <unsigned N, typename T>
	class SetSummable :  public Set<N, T>
	{
	public:
		T accumulate(const string& filter) const {
			T locObj(filter);
			for (int i = 0; i < static_cast<int>(this->size()); i++) {
				if (locObj.isCompatibleWith(this->get(i)))
					locObj += this->get(i);
			}
			return locObj;
		}
	};
}
#endif