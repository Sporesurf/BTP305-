// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 03
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

using namespace std;
namespace sdds
{
	template <typename V, typename K>
	class Pair 
	{
	protected:
		V pValue;
		K pKey;
	public:
		Pair() //Initialize unkown types in def constr
			: pValue{}, pKey{}
		{}

		Pair(const K& key, const V& value) {
			pKey = key; pValue = value;
		}

		const V& value() const {
			return pValue;
		}

		const K& key() const {
			return pKey;
		}

		virtual void display(ostream& os) const { //Modify display for polymorphic inclusion
			os << pKey << " : " << pValue << endl;
		}
	};

	template <typename V, typename K>
	ostream& operator<<(ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	}
}
#endif