#include "stdafx.h"
#include "date.h"
#include <string>
#include <fstream>

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
	if (!DateCheck()) {
		cerr << "This date is illegal.\n";
	}
}

bool Date::SetDate(int year, int month, int day) {
	Date date(year, month, day);
	if (!date.DateCheck()) {
		cerr << "This date is illegal.\n"; 
		return false;
	}
	else {
		(*this) = date;
		return true;
	}
}

istream & operator>>(istream &in, Date &date) {
	// Input ****.**.**
	cout << "Input a date in type of ****.**.**\n";
	bool date_err = true;				// Assume the date is in error by default
	while (date_err) {
		cin >> date.year_;
		cin.ignore(32767, '.');
		cin >> date.month_;
		cin.ignore(32767, '.');
		cin >> date.day_;

		if (!date.DateCheck()) {
			cerr << "This date is illegal! Pleast retry.\n";
		}
		else {
			date_err = false;
		}
	}
	return in;
}

ostream & operator<<(ostream &out, const Date &date) {
	if (date.year_ < 0) {							//BC
		cout << "BC" << -date.year_;
	}
	else {														//DC
		cout << date.year_;
	}
	cout << "." << date.month_ << "." << date.day_;
	return out;
}

void DateIfstream(ifstream& p_file, Date& date) {
	string date_str;
	getline(p_file, date_str);
	int date_length = date_str.length();
	int dot1 = 0, dot2 = 0;			//存放点所在的位置
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
}

void DateOfstream(ofstream& p_file, const Date& date) {
	p_file << date.year_ << '.' << date.month_ << '.' << date.day_;
}

Date& Date::operator++() {
	++day_;
	return *this;
}

Date Date::operator++(int) {
	Date temp(*this);
	++(*this);
	return temp;
}

Date & Date::operator--() {
	--day_;
	return *this;
}

Date Date::operator--(int) {
	Date temp(*this);
	--(*this);
	return temp;
}

bool Date::DateCheck() {
	if (year_ == 0 || month_ < 1 || month_ > 12) {
		return false;
	}
	else {
		switch (month_) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			if (day_ < 1 || day_ > 31) {
				return false;
			}
			else {
				return true;
			}
		case 4:
		case 6:
		case 9:
		case 11:
			if (day_ < 1 || day_ > 30) {
				return false;
			}
			else {
				return true;
			}
		case 2:
			if (IsLeapYear()) {
				if (day_ < 1 || day_ > 29) {
					return false;
				}
				else {
					return true;
				}
			}
			else {  // not a leap year
				if (day_ < 1 || day_ > 28) {
					return false;
				}
				else {
					return true;
				}
			}
		default: return false;
		}
	}
}

bool Date::IsLeapYear() {
	int year_temp;
	if (year_ < 0) {					//BC
		year_temp = year_ + 1;
	}
	else {													//DC
		year_temp = year_;
	}
	if (year_temp % 400 == 0 || (year_temp % 4 == 0 && year_temp % 100 != 0)) {
		return true;
	}
	else {
		return false;
	}
}