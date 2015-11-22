#include "stdafx.h"
#include "character.h"

Character::Character() : Person(), moe_rate_(0.0), anime_("NULL") {}

Character::Character(const Person& person, const double& moe_rate,
                     const string& anime)
    : Person(person), moe_rate_(moe_rate), anime_(anime) {}

bool operator==(const Character& character1, const Character& character2) {
  if (character1.GetName() == character2.GetName()) {
    if (character1.GetBirthday() == character2.GetBirthday() &&
      character1.moe_rate_ == character2.moe_rate_ &&
      character1.anime_ == character2.anime_) {
      return true;
    }
    else {
      cout << "Find two " << character1.GetName() <<
        " but they have different infomations.\n";
      return false;
    }
  }
  else {
    return false;
  }
}

// When their moe-rates are equal, compare names.
bool operator<(const Character& character1, const Character& character2) {
  if (character1.moe_rate_ != character2.moe_rate_) {
    return character1.moe_rate_ < character2.moe_rate_;
  }
  else {
    return character1.GetName() < character2.GetName();
  }
}

// When their moe-rates are equal, compare names.
bool operator>(const Character& character1, const Character& character2) {
  if (character1.moe_rate_ != character2.moe_rate_) {
    return character1.moe_rate_ > character2.moe_rate_;
  }
  else {
    return character1.GetName() > character2.GetName();
  }
}

void Character::Modify() {
  cout << "Modifying " << GetName() << " ...\n" <<
    "\'N\' or \'n\' for name\n" <<
    "\'D\' or \'d\' for birthday\n" <<
    "\'M\' or \'m\' for moe-rate\n" <<
    "\'A\' or \'a\' for anime\n";
  if (!cin.good()) {
    cin.clear();  // reset any error flags
    cin.ignore(32767, '\n');
  }
  char cmd;
  cin >> cmd;
  cin.ignore(32767, '\n');
  switch (cmd) {
  case 'N':
  case 'n': {
    cout << "Enter the new name:\n";
    string name;
    getline(cin, name);
    SetName(name);
    break;
  }
  case 'D':
  case 'd': {
    try {
      Date date;
      cin >> date;
      SetBirthday(date);
      break;
    }
    catch (...) {
      cerr << "Illegal date.\n";
      return;
    }
  }
  case 'M':
  case 'm':
    cout << "Enter the new moe-rate:\n";
    cin >> moe_rate_;
    break;
  case 'A':
  case 'a':
    cout << "Enter the new anime:\n";
    getline(cin, anime_);
    break;
  default:
    cerr << "Illegal command!\n";
    return;
  }
  cout << "Succeeded!\n" << *this << '\n';
}