#include "stdafx.h"
#include "person.h"
#include <fstream>

Person::Person(const string& name, const Date& birthday) : name_(name), birthday_(birthday) {}

void Person::SetName(const string& name) {
  name_ = name;
}

void Person::SetBirthday(const Date& birthday) {
  birthday_ = birthday;
}

const string& Person::GetName() const {
  return name_;
}

const Date& Person::GetBirthday() const {
  return birthday_;
}