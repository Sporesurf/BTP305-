#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <istream>

namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		unsigned int m_year;
		unsigned int m_length;
	};

	class SongCollection
	{
		std::vector<Song>c_songs;
	public:
		//Cleans up blank spaces within fields
		std::string& trimline(std::string& field);
		SongCollection(std::string filename);

		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif // !SDDS_SONGCOLLECTION_H