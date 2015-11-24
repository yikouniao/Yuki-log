#pragma once

#include <iostream>
#include "person.h"
#include "voice-actress.h"
#include "character.h"
#include <conio.h>
#include "key.h"

using namespace std;

namespace YUKI_N {

bool Welcome();
void MainUI();
int SelectPersonType();
void PersonUIGuide();
template <typename PersonType>
void PersonUI(list<PersonType>& person_list, const string& file);
template <typename PersonType>
void PersonUIP(list<PersonType>& person_list);
template <typename PersonType>
void PersonUIU(list<PersonType>& person_list);
template <typename PersonType>
void PersonUIF(list<PersonType>& person_list, typename list<PersonType>::iterator& it);
template <typename PersonType>
void PersonUIA(list<PersonType>& person_list);
template <typename PersonType>
void PersonUID(list<PersonType>& person_list, typename list<PersonType>::iterator& it);
template <typename PersonType>
void PersonUIM(list<PersonType>& person_list, typename list<PersonType>::iterator& it);
template <typename PersonType>
void PersonUIS(list<PersonType>& person_list, const string& file);

}  // namespace YUKI_N

// definitions of template functions
namespace YUKI_N {

template <typename PersonType>
void YUKI_N::PersonUI(list<PersonType>& person_list, const string& file) {
  CreatPersonList(person_list, file);
  list<PersonType>::iterator it = person_list.begin();
  while (1) {
    PersonUIGuide();
    while (!_kbhit()) {}
    char cmd = _getch();
    cout << "\n";
    switch (cmd) {
      case 'P':
      case 'p':
        PersonUIP(person_list);
        break;
      case 'U':
      case 'u':
        PersonUIU(person_list);
        break;
      case 'A':
      case 'a':
        PersonUIA(person_list);
        break;
      case 'F':
      case 'f':
        PersonUIF(person_list, it);
        break;
      case 'M':
      case 'm':
        PersonUIM(person_list, it);
        break;
      case 'D':
      case 'd':
        PersonUID(person_list, it);
        break;
      case 'S':
      case 's':
        PersonUIS(person_list, file);
        break;
      case ESC:
        return;
      default:
        break;
    }  // end switch (cmd)
  }  // end while(1)
}

template <typename PersonType>
void PersonUIP(list<PersonType>& person_list) {
  PrintPersonList(person_list);
}

template <typename PersonType>
void PersonUIU(list<PersonType>& person_list) {
  cout << "Any other keys for sorting in descending order of moe-rate by default,\n"
          "or you can press \'A\' or \'a\' for ascending order.\n";
  while (!_kbhit()) {}
  char cmd = _getch();
  cout << "\n";
  if (cmd == 'A' || cmd == 'a') {
    UniquePersonList(person_list, ASC);
  } else {
    UniquePersonList(person_list);
  }
}

template <typename PersonType>
void PersonUIF(list<PersonType>& person_list, typename list<PersonType>::iterator& it) {
  cout << "Press \'N\' or \'n\' to find by name.\n" <<
          "Press \'O\' or \'o\' to find by order.\n";
  while (1) {
    while (!_kbhit()) {}
    char cmd = _getch();
    cout << "\n";
    string name;
    int order { 0 };
    if (cmd == 'N' || cmd == 'n') {  // find by name
      cout << "Enter the name:\n";
      getline(cin, name);
      if (FindPerson(person_list, it, name)) {
        cout << name << " was found!:\n" << *it << "\n";
      } else {
        cout << name << " was not found!:\n" << "\n";
      }
    } else if (cmd == 'O' || cmd == 'o') {  // find by order
      cout << "Enter the order:\n";
      cin >> order;
      if (FindPerson(person_list, it, order)) {
        cout << "\nNumber " << order << " person was found!:\n" << *it << "\n";
      } else {
        cout << "\nNumber " << order << " person was not found!:\n" << "\n";
      }
    }
  }
}

template <typename PersonType>
void PersonUIA(list<PersonType>& person_list) {
  cout << "Any other keys for adding person by keyboard by default,\n"
          "or you can press \'F\' or \'f\' for adding from another file.\n";
  while (!_kbhit()) {}
  char cmd = _getch();
  cout << "\n";
  string another_file;
  if (cmd == 'F' || cmd == 'f') {  // add from file
    cout << "Enter the file path:\n";
    getline(cin, another_file);
    ifstream inf(another_file);
    if (!inf)  // could not open file
    {
      cerr << another_file << " could not be opened!\n" << endl;
      return;
    }
    AddPersonToList(person_list, inf);
  } else { // add from std::cin
    AddPersonToList(person_list, cin);
  }
}

template <typename PersonType>
void PersonUID(list<PersonType>& person_list, typename list<PersonType>::iterator& it) {
  string name = it->GetName();
  int order { 0 };
  cout << "Any other keys for deleting " << name << ",\n" <<
          "or you can press \'N\' or \'n\' to delete a person by name,\n" <<
          "or \'O\' or \'o\' to delete by order.\n";
  while (!_kbhit()) {}
  char cmd = _getch();
  cout << "\n";
  if (cmd == 'N' || cmd == 'n') {  // delete by name
    cout << "Enter the name:\n";
    getline(cin, name);
    DeletePerson(person_list, name);
  } else if (cmd == 'O' || cmd == 'o') {  // delete by order
    cout << "Enter the order:\n";
    cin >> order;
    DeletePerson(person_list, order);
  } else {  // delete what the iterator is pointing to currently
    DeletePerson(person_list, it);
  }
}

template <typename PersonType>
void PersonUIM(list<PersonType>& person_list, typename list<PersonType>::iterator& it) {
  cout << "Current person is " << it->GetName() << ".\n" <<
          "If you're going to modify another person, " <<
          "press Esc and use \'F\' or \'f\' to find him/her.\n" <<
          "Press any other keys to continue.\n";
  while (!_kbhit()) {}
  char cmd = _getch();
  cout << "\n";
  if (cmd == ESC)
    return;
  it->Modify();
}

template <typename PersonType>
void PersonUIS(list<PersonType>& person_list, const string& file) {
  SavePeosonList(person_list, file);
}

}  // namespace YUKI_N