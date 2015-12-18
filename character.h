#pragma once

#include "person.h"

class Character : public Person {
 private:
  double moe_rate_;
  string anime_;
 public:
   Character();
   Character(const Person& person, const double& moe_rate, const string& anime);
   template <typename StreamType>
   friend StreamType& operator>>(StreamType& in, Character& character);
   template <typename StreamType>
   friend StreamType& operator<<(StreamType& out, const Character& character);
   friend bool operator==(const Character& character1, const Character& character2);
   friend bool operator<(const Character& character1, const Character& character2);
   friend bool operator>(const Character& character1, const Character& character2);
   void Modify();
};

// throws an exception if an internal error occurred.
template <typename StreamType>
StreamType& operator>>(StreamType& in, Character& character) {
  string name;
  cout << "\nGetting name...\n";
  std::getline(in, name);
  character.SetName(name);
  Date date;
  in >> date;
  character.SetBirthday(date);
  string moe_rate;
  cout << "Getting moe-rate...\n";
  getline(in, moe_rate);
  character.moe_rate_ = stod(moe_rate);
  cout << "Getting anime...\n";
  getline(in, character.anime_);
  return in;
}

// throws an exception if an internal error occurred.
template <typename StreamType>
StreamType& operator<<(StreamType& out, const Character& character) {
  out << "\n" << character.GetName() << '\n' <<
         character.GetBirthday() << '\n' <<
         character.moe_rate_ << '\n' <<
         character.anime_ << '\n';
  return out;
}