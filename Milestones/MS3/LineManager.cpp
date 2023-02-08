// Name: Vlado Tomovic
// Seneca Student ID: 107995151
// Seneca email: vtomovic@myseneca.ca
// Date of completion: 2021/12/06
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <algorithm>
#include "LineManager.h"

using namespace std;
namespace sdds
{
	LineManager::LineManager(const string& file, const vector<Workstation*>& stations)
	{
		try
		{
			ifstream n_file(file);
			if (n_file)
			{
				bool more = true;
				Utilities u_obj;
				Workstation* c_station = nullptr;
				Workstation* n_station = nullptr;
				Workstation* f_station = nullptr;
				m_cntCustomerOrder = pending.size();

				size_t n_pos = 0;
				string n_record{};
				string c_stationName;
				string n_stationName{};

				while (n_file.eof() == false)
				{
					getline(n_file, n_record);
					c_stationName = u_obj.extractToken(n_record, n_pos, more);
					c_station = *find_if(stations.begin(), stations.end(), [c_stationName](const Workstation* stations) { return c_stationName == stations->getItemName(); });
					activeLine.push_back(c_station);
					if (more)
					{
						n_stationName = u_obj.extractToken(n_record, n_pos, more);
						n_station = *find_if(stations.begin(), stations.end(), [n_stationName](const Workstation* stations) { return stations->getItemName() == n_stationName; });
						c_station->setNextStation(n_station);
					}
				}

				for_each(activeLine.begin(), activeLine.end(), [&](const Workstation*) {
					f_station = *find_if(stations.begin(), stations.end(), [&](const Workstation* temp) {
						return temp->getNextStation() == f_station;
						});
					m_firstStation = f_station;
				});
				n_file.close();
			}
			else
				throw "ERROR: COULD NOT OPEN FILE.";
		}
		catch (...)
		{
			throw "ERROR: PROBLEM WITH CONSTRUCTOR";
		}
	}

	void LineManager::linkStations()
	{
		Workstation* n_station = m_firstStation;
		vector<Workstation*> tempStations;

		if (n_station != nullptr)
		{
			do
			{
				tempStations.push_back(n_station);
				n_station = n_station->getNextStation();

			} while (n_station);
			activeLine = tempStations;
		}
	}

	bool LineManager::run(ostream& os)
	{
		static size_t iterator = 1;

		os << "Line Manager Iteration: " << iterator << endl;

		if (pending.empty() == false)
		{ 
			*m_firstStation += move(pending.front());
			pending.pop_front();
		}

		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->fill(os);
		}

		for (size_t i = 0; i < activeLine.size(); i++)
		{
			activeLine[i]->attemptToMoveOrder();
		}
		size_t totalOrders = completed.size() + incomplete.size();
		iterator++;
		
		if (totalOrders == m_cntCustomerOrder)
			return true;
		return false;
	}

	void LineManager::display(ostream& os) const {
		for_each(activeLine.begin(), activeLine.end(), [&](const Workstation* w_stations) { w_stations->display(os); });
	}
}

