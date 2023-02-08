// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 11
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.
#include "ConfirmationSender.h"

using namespace std;
namespace sdds
{
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool exists = false;
		for (size_t i = 0; i < this->sizeOfArr; i++) {
			if (this->reservation[i] == &res)
				exists = true;
		}
		if (exists == false) {
			const Reservation** temp = new const Reservation*[this->sizeOfArr + 1];
			for (size_t i = 0; i < this->sizeOfArr; i++) {
				temp[i] = this->reservation[i];
			}
			delete[] this->reservation;
			this->reservation = temp;
			this->reservation[this->sizeOfArr] = &res;
			this->sizeOfArr++;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool exists = false;
		for (size_t i = 0; i < this->sizeOfArr; i++) {
			if (this->reservation[i] == &res)
				exists = true;
		}
		if (exists != false) {
			size_t j = 0;
			size_t k = this->sizeOfArr;
			const Reservation** temp = new const Reservation*[this->sizeOfArr - 1];
			for (size_t i = 0; i < k; i++) {
				if (this->reservation[i] != &res) {
					temp[j] = this->reservation[i];
					j++;
				}
			}
			this->sizeOfArr--;
			delete[] this->reservation;
			this->reservation = temp;
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(const ConfirmationSender& res) {
		*this = res;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& res) {
		if (this != &res) {
			if (this->reservation != nullptr) {
				delete[] reservation;
			}
			this->sizeOfArr = res.sizeOfArr;
			this->reservation = new const Reservation*[this->sizeOfArr];
			for (size_t i = 0; i < this->sizeOfArr; i++) {
				this->reservation[i] = res.reservation[i];
			}
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& res) noexcept {
		*this = move(res);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& res) noexcept {
		if (this != &res) {
			if (this->reservation != nullptr)
				delete[] this->reservation;
			this->reservation = nullptr;
			this->sizeOfArr = res.sizeOfArr;
			this->reservation = res.reservation;

			res.reservation = nullptr;
			res.sizeOfArr = 0;
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const ConfirmationSender& rhs) {
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (rhs.sizeOfArr != 0) {
			for (size_t i = 0; i < rhs.sizeOfArr; i++) {
				os << *rhs.reservation[i];
			}
			os << "--------------------------" << endl;
		}
		else {
			os << "There are no confirmations to send!" << endl;
			os << "--------------------------" << endl;
		}
		return os;
	}
}