#pragma once

#include <string>
#include "date.h"
#include <list>

using namespace std;

class Person {
private:
	string name_;
	Date birthday_;
protected:
	Person(const string &name = "NULL", const Date &birthday = {1, 1, 1});
	void SetName(const string &name);
	void SetBirthday(const Date &birthday);
	string& Person::GetName();
	Date& Person::GetBirthday();
};

template <typename PersonType>			// PersonType可以是VoiceActress、Character
void CreatPersonList(list<PersonType>& person_list, const string& file) {
	ifstream person_file(file);
	if (!person_file)
	{
		cerr << "The file of persons could not be opened!" << endl;
		cin.get();
		exit(1);
	}

	PersonType new_person;
	while (!person_file.eof()) {
		new_person.ReadAPersonFromFile(person_file);
		if (person_file.bad() || person_file.fail()) {
			cerr << "Error while reading voice-actress.dat\n";
			cin.get();
			exit(1);
		}
		person_list.push_back(new_person);
	}
}

template <typename PersonType>			// PersonType可以是VoiceActress、Character
void SavePeosonList(list<PersonType>& person_list, const string& file) {
	ofstream person_file(file);
	if (!person_file)
	{
		cerr << "The file of persons could not be opened!" << endl;
		cin.get();
		exit(1);
	}

	PersonType new_person;
	list<PersonType>::const_iterator it = person_list.begin();
	while (it != person_list.end()) {
		new_person = *it;
		new_person.WriteAPersonToFile(person_file);
		if (person_file.bad() || person_file.fail()) {
			cerr << "Error while reading voice-actress.dat\n";
			cin.get();
			exit(1);
		}
		++it;
	}
}