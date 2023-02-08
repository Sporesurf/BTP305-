// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 11
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
#include <iostream>
#include "Restaurant.h"

using namespace std;
namespace sdds
{
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
		this->noOfObjects = cnt;
		this->resObj = new Reservation[this->noOfObjects];
		for (size_t i = 0; i < this->noOfObjects; i++) {
			this->resObj[i] = *reservations[i];
		}
	}

	size_t Restaurant::size() const {
		return this->noOfObjects;
	}

	Restaurant::Restaurant(const Restaurant& obj) {
		*this = obj;
	}

	Restaurant& Restaurant::operator=(const Restaurant& obj) {
		if (this != &obj) {
			if (this->resObj != nullptr)
				delete[] this->resObj;
			this->resObj = nullptr;
			this->noOfObjects = obj.noOfObjects;
			this->resObj = new Reservation[this->noOfObjects];
			for (size_t i = 0; i < this->noOfObjects; i++) {
				this->resObj[i] = obj.resObj[i];
			}
		}
		return *this;
	}

	Restaurant::Restaurant(Restaurant&& obj) noexcept {
		*this = move(obj);
	}

	Restaurant& Restaurant::operator=(Restaurant&& obj) noexcept {
		if (this != &obj) {
			if (this->resObj != nullptr)
				delete[] this->resObj;
			this->resObj = nullptr;
			this->noOfObjects = obj.noOfObjects;
			this->resObj = obj.resObj;
			obj.resObj = nullptr;
			obj.noOfObjects = 0;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const Restaurant& rhs) {
		static size_t CALL_CNT;
		size_t numOfRes = rhs.size();
		CALL_CNT++;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << CALL_CNT << ")" << endl;
		os << "--------------------------" << endl;
		if (numOfRes != 0) {
			for (size_t i = 0; i < numOfRes; i++) {
				os << rhs.resObj[i];
			}
			os << "--------------------------" << endl;
		}
		else { 
			os << "This restaurant is empty!" << endl;
			os << "--------------------------" << endl;
		}
		return os;
	}
}
