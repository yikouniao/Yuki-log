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
		cerr << file << " could not be opened!\n" << endl;
		cin.get();
		exit(1);
	}

	PersonType new_person;
	while (person_file.peek() != EOF) {
		try {
			person_file >> new_person;
		}
		catch (...) {
			cerr << "Error while inputting the following person!\n";
			cout << new_person;
			cerr << "\n";
			continue;
		}
		if (person_file.bad() || person_file.fail()) {
			cerr << "Error while reading " << file << " \n";
			cin.get();
			exit(1);
		}
		person_list.push_back(new_person);
	}
	if (!person_file.eof()) {
		cerr << "Error while reading " << file << " \n";
	}
}

template <typename PersonType>			// PersonType可以是VoiceActress、Character
void SavePeosonList(list<PersonType>& person_list, const string& file) {
	ofstream person_file(file);
	if (!person_file)
	{
		cerr << file << " could not be opened!\n" << endl;
		cin.get();
		exit(1);
	}

	PersonType new_person;
	list<PersonType>::const_iterator it = person_list.begin();
	while (it != person_list.end()) {
		try {
			person_file << *it;
		}
		catch (...) {
			cerr << "Error while ouputting a person!\n";
			cin.get();
			exit(1);
		}
		if (person_file.bad() || person_file.fail()) {
			cerr << "Error while reading " << file << " \n";
			cin.get();
			exit(1);
		}
		++it;
	}
}

//	PersonType can be VoiceActress, Character
//  StreamType can be istream, ifstream
template <typename PersonType, typename StreamType>
void AddPersonToList(list<PersonType>& person_list, StreamType& in) {
	PersonType new_person;
	try {
		in >> new_person;
	}
	catch (...) {
		cerr << "Error while inputting a person!\n";
		return;
	}
	person_list.push_back(new_person);
}