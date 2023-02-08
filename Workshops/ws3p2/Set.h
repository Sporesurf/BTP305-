// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 03
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <cstdio> //size_t undefined in compiler?

namespace sdds
{
	template <unsigned N, typename T>
	class Set
	{
		T staticArr[N];
		unsigned currentElements = 0;
	public:
		size_t size() const {
			return currentElements;
		}

		const T& get(size_t idx) const {
			return staticArr[idx];
		}

		void operator +=(const T& item) {
			if (currentElements < N)
			{
				staticArr[currentElements] = item;
				currentElements++;
			}
		}
	};
}
#endif // !SDDS_SET_H
