// Vlado Tomovic     vtomovic@myseneca.ca     SN : 107995151     Date : 2021 / 09 / 26
// I have done all the coding by myself and only copied the code that
// my professor provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <string>
#include "StringSet.h"

using namespace std;
namespace sdds
{
	StringSet::StringSet() {
		m_string = nullptr;
		m_noOfRecords = 0;
	}

	StringSet::StringSet(const char* fname) {
		ifstream fin(fname);
		string nstr;
		m_string = nullptr;
		m_noOfRecords = 0;

		if (fin.is_open()) {
			while (getline(fin, nstr, ' ')){
				m_noOfRecords++;
			}
			fin.close();
		}
		m_string = new string[m_noOfRecords];
		fin.open(fname);
		if (fin.is_open()) {
			for (size_t i = 0; i < m_noOfRecords; i++) {
				getline(fin, nstr, ' ');
				m_string[i] = nstr;
			}
			fin.close();
		}
	}

	size_t StringSet::size(){
		return m_noOfRecords;
	}

	string StringSet::operator[](size_t position){
		if (position < m_noOfRecords && position >= 0)
			return m_string[position];
		return "";
	}

	StringSet::StringSet(const StringSet& src) {
		*this = src;
	}

	StringSet::StringSet(StringSet&& src)noexcept {
		*this = move(src);
	}

	StringSet& StringSet::operator=(const StringSet& src) {
		if (this != &src) {
			if (m_string != nullptr)
			delete[] m_string;

			m_string = nullptr;
			m_string = new string[src.m_noOfRecords];
			m_noOfRecords = src.m_noOfRecords;

			for (size_t i = 0; i < src.m_noOfRecords; i++)
				m_string[i] = src.m_string[i];
		}
		return *this;
	}

	StringSet& StringSet::operator=(StringSet&& src)noexcept {
		if (this != &src) {
			if (m_string != nullptr)
			delete[] m_string;
			m_string = nullptr;

			m_string = src.m_string;
			src.m_string = nullptr;

			m_noOfRecords = src.m_noOfRecords;
			src.m_noOfRecords = 0;
		}
		return *this;
	}

	StringSet::~StringSet(){
		if (m_string != nullptr){
			delete[] m_string;
			m_string = nullptr;
		}
		m_noOfRecords--;
	}
}