// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/12/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"
#include "Utilities.h"

// The LineManager class manages an assembly line of active stations and contains the following information:

namespace sdds
{
	class LineManager
	{
		//The collection of workstations for the current assembly line.
		std::vector<Workstation*> activeLine;
		//The total number of CustomerOrder objects
		size_t m_cntCustomerOrder = 0;
		//Points to the first active station on the current line
		Workstation* m_firstStation = nullptr;
	public:
		//Recieves name of file and active stations, and collectio nof workshops avalable for configuration.
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		//Reorders present workshop in activeLine, stores reordered collection in activeLine. Start at first station, procceed to end of line.
		void linkStations();
		//Performs single iteration of operations on all workstations.
		bool run(std::ostream& os);
		//Display all active stations.
		void display(std::ostream& os) const;
	};
}
#endif // !SDDS_LINEMANAGER_H