
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "SongCollection.h"


using namespace std;
namespace sdds
{
	//trimline white spaces.
	string& SongCollection::trimline(string& line)
	{
		size_t startOfLine;
		size_t endOfWSpace;
		if (line != "")
		{
			startOfLine = line.find_first_not_of(' ', 0);
			if (startOfLine > 0)
				line = line.substr(startOfLine);
			endOfWSpace = line.find_first_of(' ', startOfLine + 1); 
			//line.find_last_of(' ', endOfWSpace + 1);
			do // Iterate until full string is found
			{
				endOfWSpace = line.find_first_of(' ', endOfWSpace + 1);
			} while (line.find_last_of(' ', endOfWSpace + 1) == endOfWSpace);
			line = line.substr(0, endOfWSpace);
		}
		return line;
	}

	//string& SongCollection::trimline(string& token) {if (token != "") {int init, end;end = token.find_first_not_of(' ', 0);if (end > 0)token = token.substr(end);init = token.find_first_of(' ', end + 1);while (token.find_last_of(' ', init + 1) == init && init != -1) {init = token.find_first_of(' ', init + 1);}token = token.substr(0, init);}return token;}

	SongCollection::SongCollection(string filename)
	{
		ifstream infile(filename);
		if (infile)
		{
			string songInfo;
			Song song;
			while (infile)
			{  
				getline(infile, songInfo);
				trimline(song.m_title = songInfo.substr(0, 25));
				trimline(song.m_artist = songInfo.substr(0, 25));
				trimline(song.m_title = songInfo.substr(0, 25));

			//	if ()
			}
		} else if (!infile)
			throw "INVALID: arg does not match any filenames.";
	}

	//SongCollection::SongCollection(string fileName) {
	//	std::ifstream file(fileName); if (!file)throw "Invalid file name."; while (file) {
	//		Song song; string line; getline(file, line); if (file) {
	//			trimline(song.m_title = line.substr(0, 25)); trimline(song.m_artist = line.substr(25, 25)); trimline(song.m_album = line.substr(50, 25)); try { song.m_releaseYear = stoi(line.substr(75, 5)); }
	//			catch (...) { song.m_releaseYear = 0; }try { song.m_songLength = stoi(line.substr(80, 5)); }
	//			catch (...) { song.m_songLength = 0; }try { song.m_price = stod(line.substr(85, 5)); }
	//			catch (...) { song.m_price = 0; }c_songs.push_back(song);
	//		}
	//	}file.close();
	//};

	void SongCollection::display(std::ostream& out) const
	{
		for_each(c_songs.begin(), c_songs.end(), [&out](const Song& song) {
			out << 
			});
			
	}

	
	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		// TODO: insert return statement here
		return out;
	}

}