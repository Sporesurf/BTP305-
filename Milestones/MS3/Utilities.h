// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/11/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>

//Parsing string data from input files into 
//tokens is performed uniformly for all objects 
//within the simulation system The Utilities type provides the basic 
//functionality required for all objects in the system.

namespace sdds
{
	
	const size_t u_idField = 3;
	const size_t u_serialField = 6;

	class Utilities
	{
		unsigned int m_widthField = 1;
		static char m_delimiter;
	public:
		//Sets the field width of the current object to the value of parameter
		void setFieldWidth(size_t newWidth);
		//Returns the field width of the current object
		size_t getFieldWidth() const;
		//Extracts a token from string str referred to by the first parameter
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		//Sets the delimiter for this class to the character received
		static void setDelimiter(char newDelimiter);
		//Returns the delimiter for this class.
		static char getDelimiter();
	};
}
#endif