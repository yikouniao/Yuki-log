#include "stdafx.h"
#include "person.h"
#include <fstream>

Person::Person(const string &name, const Date &birthday) : name_(name), birthday_(birthday) {}

void Person::SetName(const string &name) {
	name_ = name;
}

void Person::SetBirthday(const Date &birthday) {
	birthday_ = birthday;
}

string& Person::GetName() {
	return name_;
}

Date& Person::GetBirthday() {
	return birthday_;
}



