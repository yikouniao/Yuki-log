#pragma once

#include <string>
#include "date.h"

using namespace std;

class Person {
private:
	string name_;
	Date birthday_;
protected:
	Person(const string &name = "NULL", const Date &birthday = {1, 1, 1});
	void SetName(const string &name);
	void SetBirthday(const Date &birthday);
	void PrintName();
	void PrintBirthday();
	void PrintPerson();
};