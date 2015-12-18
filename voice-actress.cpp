#include "stdafx.h"
#include "voice-actress.h"
#include <conio.h>
#include "key.h"

VoiceActress::VoiceActress() : Person(), moe_rate_(0.0), enterprise_("NULL"), characers_("NULL") {}

VoiceActress::VoiceActress(const Person& person, const double& moe_rate,
                           const string& enterprise, const string& characters)
    : Person(person), moe_rate_(moe_rate), enterprise_(enterprise), characers_(characters) {}

bool operator==(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2) {
  if (voice_actress1.GetName() == voice_actress2.GetName()) {  // names equal
    if (voice_actress1.GetBirthday() == voice_actress2.GetBirthday() &&
        voice_actress1.moe_rate_ == voice_actress2.moe_rate_ &&
        voice_actress1.enterprise_ == voice_actress2.enterprise_ &&
        voice_actress1.characers_ == voice_actress2.characers_) {  // other infos equal
      return true;
    } else {  // other infos unequal
      cout << "Find two " << voice_actress1.GetName() <<
              " but they have different infomations.\n";
      return false;
    }
  } else {  // names unequal
    return false;
  }
}

// When their moe-rates are equal, compare names.
bool operator<(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2) {
  if (voice_actress1.moe_rate_ != voice_actress2.moe_rate_) {
    return voice_actress1.moe_rate_ < voice_actress2.moe_rate_;
  } else {
    return voice_actress1.GetName() < voice_actress2.GetName();
  }
}

// When their moe-rates are equal, compare names.
bool operator>(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2) {
  if (voice_actress1.moe_rate_ != voice_actress2.moe_rate_) {
    return voice_actress1.moe_rate_ > voice_actress2.moe_rate_;
  }
  else {
    return voice_actress1.GetName() > voice_actress2.GetName();
  }
}

void VoiceActress::Modify() {
  cout << "Modifying " << GetName() <<" ...\n" <<
          "\'N\' or \'n\' for name\n" <<
          "\'D\' or \'d\' for birthday\n" <<
          "\'M\' or \'m\' for moe-rate\n" <<
          "\'E\' or \'e\' for enterprise\n" <<
          "\'C\' or \'c\' for characters\n" <<
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
    case 'E':
    case 'e':
      cout << "Enter the new enterprise:\n";
      getline(cin, enterprise_);
      break;
    case 'C':
    case 'c': {
      cout << "\n\'A\' or \'a\' for appending a new character\n" <<
        "other keys for replacing the old character infomation\n";
      while (!_kbhit()) {}
      char cmd = _getch();
      cout << "\nEnter the names of characters:\n";
      string character;
      getline(cin, character);
      if (cmd == 'A' || cmd == 'a') {
        characers_ += ", ";
        characers_ += character;
      } else {
        characers_ = character;
      }
      break;
    }
    case ESC:
      cout << "\nModification was cancelled.\n\n";
      return;
    default:
      cerr << "\nIllegal command!\n\n";
      return;
  }  // switch (cmd)
  cout << "\nSucceeded!\n" << *this << '\n';
}