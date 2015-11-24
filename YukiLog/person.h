#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "date.h"
#include <list>
#include <functional>

using namespace std;

class Person {
 private:
  string name_;
  Date birthday_;
 public:
  Person(const string& name = "NULL", const Date& birthday = {1, 1, 1});
  void SetName(const string& name);
  void SetBirthday(const Date& birthday);
  const string& GetName() const;
  const Date& GetBirthday() const;
};

enum PersonTypeEnum { CHARACTER, VOICE_ACTRESS};
enum SortDir { DESC, ASC };

// The following PersonTypes can be VoiceActress, Character, etc.
// And streamType can be istream, ifstream,etc.
template <typename PersonType>
void CreatPersonList(list<PersonType>& person_list, const string& file);
template <typename PersonType>
void PrintPersonList(const list<PersonType>& person_list);
template <typename PersonType>
void SavePeosonList(list<PersonType>& person_list, const string& file);
template <typename PersonType>
void SortPersonList(list<PersonType>& person_list, SortDir dir = DESC);
// Sort before using unique() to delete uncontinuous duplicate nodes.
template <typename PersonType>
void UniquePersonList(list<PersonType>& person_list, SortDir dir = DESC);
template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list, const string& name);
template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list,
                typename list<PersonType>::const_iterator& it,
                const string& name);
template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list,
                typename list<PersonType>::const_iterator& it, int order);
template <typename PersonType, typename StreamType>
void AddPersonToList(list<PersonType>& person_list, StreamType& in);
template <typename PersonType>
void DeletePerson(list<PersonType>& person_list,
                  typename list<PersonType>::iterator& it);
template <typename PersonType>
void DeletePerson(list<PersonType>& person_list, const string& name);
template <typename PersonType>
void DeletePerson(list<PersonType>& person_list, int order);

template <typename PersonType>
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
      return;
    }
    person_list.push_back(new_person);
  }
  if (!person_file.eof()) {
    cerr << "Error while reading " << file << " \n";
    return;
  }
  UniquePersonList(person_list);
}

template <typename PersonType>
void PrintPersonList(const list<PersonType>& person_list) {
  cout << "\nPrint persons:\n";
  int i = 1;
  for (const auto& person : person_list) {
    cout << "\nNumber " << i << ":\n" << person;
    ++i;
  }
  cout << "\n";
}

template <typename PersonType>
void SavePeosonList(list<PersonType>& person_list, const string& file) {
  ofstream person_file(file);
  if (!person_file)
  {
    cerr << file << " could not be opened!\n" << endl;
    cin.get();
    exit(1);
  }
  UniquePersonList(person_list);
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
  cout << "Save persons into " << file << " successfully.\n";
}

template <typename PersonType>
void SortPersonList(list<PersonType>& person_list, SortDir dir) {
  if (dir == DESC) {
    person_list.sort(greater<PersonType>());
  } else {
    person_list.sort(less<PersonType>());
  }
}

template <typename PersonType>
void UniquePersonList(list<PersonType>& person_list, SortDir dir) {
  SortPersonList(person_list, dir);
  person_list.unique();
}

template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list, const string& name) {
  for (const auto& element : person_list) {
    if (element.GetName() == name)
      return true;
  }
  return false;
}

template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list,
                typename list<PersonType>::const_iterator& it,
                const string& name) {
  for (it = person_list.begin(); it != person_list.end(); ++it) {
    if (it->GetName() == name) {
      return true;
    }
  }
  return false;
}

template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list,
                typename list<PersonType>::const_iterator& it, int order) {
  if (static_cast<int>(person_list.size()) < order) {
    cerr << "\nWe have only " << person_list.size() << " persons.\n\n";
    return false;
  } else if (order < 1) {
    cerr << "\nInput an interger order.\n" <<
            "You can print the whole list to check the order.\n\n";
    return false;
  } else {
    int i = order;
    for (it = person_list.begin(); i > 1; ++it, --i) {}
    return true;
  }
}

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
  if (FindPerson(person_list, new_person.GetName())) {
    cerr << '\n' << new_person.GetName() << " has already existed!\n";
    return;
  }
  person_list.push_back(new_person);
  cout << '\n' << new_person.GetName() << " has added successfully!\n";
}

template <typename PersonType>
void DeletePerson(list<PersonType>& person_list,
                  typename list<PersonType>::iterator& it) {
  string name = it->GetName();
  person_list.erase(it);
  cout << name << " was deleted!\n\n";
}

template <typename PersonType>
void DeletePerson(list<PersonType>& person_list, const string& name) {
  list<PersonType>::iterator it = person_list.begin();
  for (; it != person_list.end(); ++it) {
    if (it->GetName() == name) {
      person_list.erase(it);
      cout << name << " was deleted!\n\n";
      return;
    }
  }
  cout << "Could not find " << name << ". \n\n";
}

template <typename PersonType>
void DeletePerson(list<PersonType>& person_list, int order) {
  list<PersonType>::iterator it = person_list.begin();
  if (static_cast<int>(person_list.size()) < order) {
    cout << "We have only " << person_list.size() << " persons.\n\n";
  }
  else if (order < 1) {
    cout << "Input an interger order.\n" <<
      "You can print the whole list to check the order.\n\n";
  }
  else {
    int i = order;
    for (it = person_list.begin(); i > 1; ++it, --i) {}
    person_list.erase(it);
    cout << "Number " << order << " person was deleted!\n\n";
  }
}