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
	friend istream & operator>>(istream &in, Date &date);
	friend ostream & operator<<(ostream &out, const Date &date);
	friend void DateIfstream(fstream& p_file, Date& date);
	friend void DateOfstream(fstream& p_file, const Date& date);
	Date & operator++();
	Date operator++(int);
	Date & operator--();
	Date operator--(int);
	bool DateCheck();
	bool IsLeapYear();
};