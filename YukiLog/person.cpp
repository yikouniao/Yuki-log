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
#if 0
template <typename PersonType>			// PersonTypeø…“‘ «VoiceActress°¢Character
void PersonType::CreatPersonList(const string &file) {
	fstream person_file(file);
	if (!person_file)
	{
		cerr << "The file of persons could not be opened!" << endl;
		cin.get();
		exit(1);
	}

	//while(person_file)
	//push_back(ReadAPersonFromFile(person_file));
}
#endif