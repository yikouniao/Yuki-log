#include "stdafx.h"
#include "person.h"

Person::Person(const string &name, const Date &birthday) : name_(name), birthday_(birthday) {}

void Person::SetName(const string &name) {
	name_ = name;
}

void Person::SetBirthday(const Date &birthday) {
	birthday_ = birthday;
}

void Person::PrintName() {
	cout << name_;
}

void Person::PrintBirthday() {
	cout << birthday_;
}

void Person::PrintPerson() {
	PrintName();
	cout << "\tbirthday: ";
	PrintBirthday();
}