#pragma once

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
  const string& Person::GetName() const;
  const Date& Person::GetBirthday() const;
};

// The following PersonTypes can be VoiceActress, Character, etc.
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
      exit(1);
    }
    person_list.push_back(new_person);
  }
  if (!person_file.eof()) {
    cerr << "Error while reading " << file << " \n";
  }
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
void SavePeosonList(const list<PersonType>& person_list, const string& file) {
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

// PersonType can be VoiceActress, Character
// StreamType can be istream, ifstream
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

enum SortDir {
  DESC, ASC
};

template <typename PersonType>
void SortPersonList(list<PersonType>& person_list, SortDir dir = DESC) {
  if (dir == DESC) {
    person_list.sort(greater<PersonType>());
  } else {
    person_list.sort(less<PersonType>());
  }
}

// Sort before using unique() to delete uncontinuous duplicate nodes.
template <typename PersonType>
void UniquePersonList(list<PersonType>& person_list, SortDir dir = DESC) {
  SortPersonList(person_list, dir);
  person_list.unique();
}

template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list,
                typename list<PersonType>::const_iterator& it,
                const string& name) {
  for (it = person_list.begin(); it != person_list.end(); ++it) {
    if (it->GetName() == name) {
      cout << '\n' << name << " was found!:\n" << *it << "\n";
      return true;
    }
  }
  cout << "\nCould not find " << name << ". \n\n";
  return false;
}

template <typename PersonType>
bool FindPerson(const list<PersonType>& person_list,
                typename list<PersonType>::const_iterator& it, int order) {
  if (static_cast<int>(person_list.size()) < order) {
    cout << "\nWe have only " << person_list.size() << " persons.\n\n";
    return false;
  } else if (order < 1) {
    cout << "\nInput an interger order.\n" <<
            "You can print the whole list to check the order.\n\n";
    return false;
  } else {
    int i = order;
    for (it = person_list.begin(); i > 1; ++it, --i) {}
    cout << "\nNumber "<< order << " person was found!:\n" << *it << "\n";
    return true;
  }
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