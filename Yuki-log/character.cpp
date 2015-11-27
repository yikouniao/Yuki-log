#include "stdafx.h"
#include "character.h"
#include <conio.h>
#include "key.h"

Character::Character() : Person(), moe_rate_(0.0), anime_("NULL") {}

Character::Character(const Person& person, const double& moe_rate,
                     const string& anime)
    : Person(person), moe_rate_(moe_rate), anime_(anime) {}

bool operator==(const Character& character1, const Character& character2) {
  if (character1.GetName() == character2.GetName()) {  // names equal
    if (character1.GetBirthday() == character2.GetBirthday() &&
        character1.moe_rate_ == character2.moe_rate_ &&
        character1.anime_ == character2.anime_) {  // other infos equal
      return true;
    } else {  // other infos unequal
      cout << "Find two " << character1.GetName() <<
              " but they have different infomations.\n";
      return false;
    }
  } else {  // names unequal
    return false;
  }
}

// When their moe-rates are equal, compare names.
bool operator<(const Character& character1, const Character& character2) {
  if (character1.moe_rate_ != character2.moe_rate_) {
    return character1.moe_rate_ < character2.moe_rate_;
  } else {
    return character1.GetName() < character2.GetName();
  }
}

// When their moe-rates are equal, compare names.
bool operator>(const Character& character1, const Character& character2) {
  if (character1.moe_rate_ != character2.moe_rate_) {
    return character1.moe_rate_ > character2.moe_rate_;
  } else {
    return character1.GetName() > character2.GetName();
  }
}

void Character::Modify() {
  cout << "Modifying " << GetName() << " ...\n" <<
          "\'N\' or \'n\' for name\n" <<
          "\'D\' or \'d\' for birthday\n" <<
          "\'M\' or \'m\' for moe-rate\n" <<
          "\'A\' or \'a\' for anime\n" <<
          "Esc for cancellation.\n";
  while (!_kbhit()) {}
  char cmd = _getch();
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
    case ESC:
      cout << "\nModification was cancelled.\n\n";
      return;
    default:
      cerr << "Illegal command!\n\n";
      return;
  }  // switch(cmd)
  cout << "Succeeded!\n" << *this << '\n';
}