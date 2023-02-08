#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;
namespace sdds {
	struct Song {
		string m_artist;
		string m_title;
		string m_album;
		double m_price;
		unsigned int m_year;
		unsigned int m_length;
	};
	class SongCollection {
		vector<Song> m_collection;
	public:
		string& trimline(string& token);
		explicit SongCollection(string file);
		void display(std::ostream& out) const;
		void sort(string field);
		void cleanAlbum();
		bool inCollection(string) const;
		list<Song> getSongsForArtist(string) const;
	};
	ostream& operator<<(ostream& out, const Song& src);
}
#endif