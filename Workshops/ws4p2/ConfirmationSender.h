// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 10 / 11
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** reservation{};
		size_t sizeOfArr{};
	public:
		ConfirmationSender() {};
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend ostream& operator<<(ostream& os, const ConfirmationSender& rhs);

		//COPY CONST, ASSIGNEMNT OPS
		ConfirmationSender(const ConfirmationSender& res);
		ConfirmationSender& operator=(const ConfirmationSender& res);
		ConfirmationSender(ConfirmationSender&& res) noexcept;
		ConfirmationSender& operator=(ConfirmationSender&& res) noexcept;

		~ConfirmationSender() { delete[] reservation; }
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H
