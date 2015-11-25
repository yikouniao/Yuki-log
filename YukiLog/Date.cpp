#include "stdafx.h"
#include "date.h"
#include <string>
#include <fstream>

Date::Date(int year, int month, int day) : year_(year), month_(month), day_(day) {
  DateCheck();
}

void Date::SetDate(int year, int month, int day) {
  Date date(year, month, day);
  date.DateCheck();
  (*this) = date;
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

Date& Date::operator--() {
  --day_;
  return *this;
}

Date Date::operator--(int) {
  Date temp(*this);
  --(*this);
  return temp;
}

bool operator==(const Date& date1, const Date& date2) {
  if (date1.year_ == date2.year_ &&
      date1.month_ == date2.month_ &&
      date1.day_ == date2.day_) {
    return true;
  } else {
    return false;
  }
}

void Date::DateCheck() const {
  if (year_ == 0 || month_ < 1 || month_ > 12) {  // year or month wrong
    throw "Wrong Date!\n";
  }	else {  // year or month right
    switch (month_) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:  // 31 days in these months
      if (day_ < 1 || day_ > 31) {
        throw "Wrong Date!\n";
      } else {
        return;
      }
    case 4:
    case 6:
    case 9:
    case 11:  // 30 days in these months
      if (day_ < 1 || day_ > 30) {
        throw "Wrong Date!\n";
      } else {
        return;
      }
    case 2:  // in February
      if (IsLeapYear()) {  // in a leap year
        if (day_ < 1 || day_ > 29) {
          throw "Wrong Date!\n";
        } else {
          return;
        }
      } else {  // not a leap year
        if (day_ < 1 || day_ > 28) {
          throw "Wrong Date!\n";
        } else {
          return;
        }
      }
    default: throw "Wrong Date!\n";
    }  // switch (month_)
  }  // year or month right
}

bool Date::IsLeapYear() const {
  int year_temp;
  if (year_ < 0) {          //BC
    year_temp = year_ + 1;
  } else {                  //DC
    year_temp = year_;
  }
  if (year_temp % 400 == 0 || (year_temp % 4 == 0 && year_temp % 100 != 0)) {
    return true;
  } else {
    return false;
  }
}