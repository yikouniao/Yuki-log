#pragma once

#include <string>
#include "date.h"
#include <list>

using namespace std;

class Person {
private:
	string name_;
	Date birthday_;
public:
	Person(const string &name = "NULL", const Date &birthday = {1, 1, 1});
	void SetName(const string &name);
	void SetBirthday(const Date &birthday);
	const string& Person::GetName() const;
	const Date& Person::GetBirthday() const;
};

template <typename PersonType>			// PersonType可以是VoiceActress、Character
void CreatPersonList(list<PersonType>& person_list, const string& file) {
	ifstream person_file(file);
	if (!person_file)
	{
		cerr << "The file of persons could not be opened!\n" << endl;
		cin.get();
		exit(1);
	}

	PersonType new_person;
	while (!person_file.eof()) {
		try {
			person_file >> new_person;
		}
		catch (...) {
			cerr << "Error while inputting a person! It has been replaced with a default person.\n";
			PersonType default_person;
			new_person = default_person;
		}
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
		cerr << "The file of persons could not be opened!\n" << endl;
		cin.get();
		exit(1);
	}

	PersonType new_person;
	list<PersonType>::const_iterator it = person_list.begin();
	while (it != person_list.end()) {
		try {
			person_file << *it;
			if (++it != person_list.end()) {
				person_file << "\n";
			}
			--it;
		}
		catch (...) {
			cerr << "Error while ouputting a person! It has been replaced with a default person.\n";
			cin.get();
			exit(1);
		}
		if (person_file.bad() || person_file.fail()) {
			cerr << "Error while reading voice-actress.dat\n";
			cin.get();
			exit(1);
		}
		++it;
	}
}