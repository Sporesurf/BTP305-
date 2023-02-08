#include <iostream>
#include <functional>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <algorithm>
#include "SongCollection.h"

using namespace std;
namespace sdds {
	string& SongCollection::trimline(string& token) {
		if (!token.empty()) {
			token.erase(0, token.find_first_not_of(' '));
			token.erase(token.find_last_not_of(' ') + 1);
		}
		return token;
	}
	SongCollection::SongCollection(string fileName) {
		std::ifstream file(fileName);
		if (!file) {
			throw "Invalid file name.";
			return;
		}
		while (file)
		{
			Song song;
			string line;
			getline(file, line);
			if (file) {
				trimline(song.m_title = line.substr(0, 25));
				trimline(song.m_artist = line.substr(25, 25));
				trimline(song.m_album = line.substr(50, 25));
				try {
					song.m_year = stoi(line.substr(75, 5));
				}
				catch (...) {
					song.m_year = 0;
				}
				song.m_length = stoi(line.substr(80, 5));
				song.m_price = stod(line.substr(85, 5));
				c_songs.push_back(song);
			}
		}
		file.close();
	}
	void SongCollection::display(std::ostream& out) const {
			for_each(c_songs.begin(), c_songs.end(), [&out](const Song
				& song) {
					out << song << endl;
				});
		size_t sumTime = accumulate(c_songs.begin(), c_songs.end(), 0u,
			[](const size_t& sumLength, const Song
				& song) {
					return sumLength + song.m_length;
			});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << "| ";
		out.width(77);
		out << "Total Listening Time: "
			<< sumTime / 3600 << ":" << (sumTime - (sumTime / 3600) * 3600) / 60
			<< ":"
			<< sumTime % 60;
		out << " |" << endl;
	}
	void SongCollection::sort(string column) {
		if (column == "title") {
			::sort(c_songs.begin(), c_songs.end(), [](const Song& front,
				const Song& after) {
					return front.m_title < after.m_title;
				});
		}
		else if (column == "album") {
			::sort(c_songs.begin(), c_songs.end(), [](const Song& front,
				const Song& after) {
					return front.m_album < after.m_album;
				});
		}
		else if (column == "length") {
			::sort(c_songs.begin(), c_songs.end(), [](const Song& front,
				const Song& after) {
					return front.m_length < after.m_length;
				});
		}
	}
	ostream& operator<<(ostream& out, const Song& src) {
		out << "| ";
		out << left << setw(20) << src.m_title;
		out << " | ";
		out << left << setw(15) << src.m_artist;
		out << " | ";
		out << left << setw(20) << src.m_album;
		out << " | ";
		if (src.m_year > 0)
			out << right << setw(6) << src.m_year;
		else
			out << right << setw(6) << ' ';
		out << " | ";
		out << src.m_length / 60 << ":";
		out << right << setw(2) << setfill('0') << src.m_length % 60 << setfill(' ');
			out << " | ";
		out << src.m_price;
		out << " |";
		return out;
	}

	void SongCollection::cleanAlbum() {
		for_each(c_songs.begin(), c_songs.end(),
			[](Song& song) { song.m_album = song.m_album == "[None]" ? "" : song.m_album; });
	}
	bool SongCollection::inCollection(string artist) const {
		auto valid = find_if(c_songs.begin(), c_songs.end(),
			[&artist](const Song& song) {return song.m_artist == artist; });
		return valid != c_songs.end();
	}
	::list<Song> SongCollection::getSongsForArtist(string artist) const {
		auto count = count_if(c_songs.begin(), c_songs.end(),
			[&artist](const Song& song) {
				return song.m_artist == artist;
			});
		list<Song>listed(count);
		copy_if(c_songs.begin(), c_songs.end(), listed.begin(),
			[&artist](const Song& song) {
				return song.m_artist == artist;
			});
		return listed;
	}
}
