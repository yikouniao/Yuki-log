#pragma once

#include <iostream>

using namespace std;

class Date {
private:
  int year_;
	int month_;
	int day_;

public:
	Date(int year = 2003, int month = 7, int day = 6);
	bool SetDate(int year, int month, int day);
	template <typename TypeStrem>
	friend TypeStrem & operator>>(TypeStrem &in, Date &date);
	friend ostream & operator<<(ostream &out, const Date &date);
	friend void DateOfstream(ofstream& p_file, const Date& date);
	Date & operator++();
	Date operator++(int);
	Date & operator--();
	Date operator--(int);
	bool DateCheck();
	bool IsLeapYear();
};

template <typename TypeStrem>
TypeStrem & operator>>(TypeStrem &in, Date &date) {
	// Input ****.**.**
	cout << "Getting a date in type of ****(BC).**.**...\n";
	string date_str;
	getline(in, date_str);
	int date_length = date_str.length();
	int dot1 = 0, dot2 = 0;			//the position of two dots in ****.**.**
	for (int i = 0; i < date_length; i++) {
		if (date_str[i] == '.') {
			(dot1 == 0) ? (dot1 = i) : (dot2 = i);
		}
	}
	string date_year, date_month, date_day;
	date_year.assign(date_str, 0, dot1);
	date_month.assign(date_str, dot1 + 1, dot2 - dot1 - 1);
	date_day.assign(date_str, dot2 + 1, date_length - dot2 - 1);
	date.year_ = stoi(date_year);
	date.month_ = stoi(date_month);
	date.day_ = stoi(date_day);
	if (date_year.find("BC") != string::npos || date_year.find("bc") != string::npos) {
		date.year_ = -date.year_;
	}

	if (!date.DateCheck()) {
		throw "This date is illegal! Pleast retry.\n";
	}
	return in;
}