#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <istream>
#include <iostream>
#include "Vehicle.h"


namespace sdds
{
	class Name : public Vehicle
	{	
		char m_tag;
		char m_condition;
		std::string m_make;
		double m_topSpeed;
	public:
		Name();
		//read a single record from stream,
		//extract car info and store it
		Name(std::istream& infile); // TAG,MAKER,CONDITION,TOP_SPEED
		//A query that returns new, used or broken, representing the condition of the car
		std::string condition() const;

		double topspeed() const;
		void display(std::ostream& out);

	};
}

#endif