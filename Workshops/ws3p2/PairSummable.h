// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 03
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include <iomanip>
#include "Pair.h"

namespace sdds
{
	template <typename V, typename K>
	class PairSummable : public Pair<V, K>
	{
		static V initialValue;
		static size_t minChars;
	public:
		PairSummable() { 
			minChars = 0;
		}

		PairSummable(const K& key, const V& value = initialValue) : Pair<V, K>(key, value) {
			if (key.size() > minChars)
				minChars = key.size();
		}	

		bool isCompatibleWith(const PairSummable<V, K>& b) {
			bool check = false;
			if (b.key() == this->key())
				check = true;
			return check;
		}

		PairSummable<V, K>& operator+=(const PairSummable <V, K>& rhs) {
			if (isCompatibleWith(rhs) == true)
				this->pValue += rhs.value();
			return *this;
		}

		void display(ostream& os)const {
			os << left << setw(minChars);
			Pair<V, K>::display(os);
			os << right;
		}
	};

	template <typename V, typename K>
	V PairSummable<V, K>::initialValue;

	template <typename V, typename K>
	size_t PairSummable<V, K>::minChars;

	template <>
	PairSummable<string, string>& PairSummable<string, string>::operator+=(const PairSummable <string, string>& rhs) {
		string concat;
		if (this->value().empty())
			concat = rhs.value();
		else concat = this->value() + ", " + rhs.value();
		*this = PairSummable(this->key(), concat);
		return *this;
	}
}
#endif