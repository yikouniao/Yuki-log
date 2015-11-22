#include "stdafx.h"
#include "voice-actress.h"

VoiceActress::VoiceActress() : Person(), moe_rate_(0.0), enterprise_("NULL"), characers_("NULL") {}

VoiceActress::VoiceActress(const Person& person, const double& moe_rate,
                           const string& enterprise, const string& characters)
    : Person(person), moe_rate_(moe_rate), enterprise_(enterprise), characers_(characters) {}

bool operator==(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2) {
  if (voice_actress1.GetName() == voice_actress2.GetName()) {
    if (voice_actress1.GetBirthday() == voice_actress2.GetBirthday() &&
        voice_actress1.moe_rate_ == voice_actress2.moe_rate_ &&
        voice_actress1.enterprise_ == voice_actress2.enterprise_ &&
        voice_actress1.characers_ == voice_actress2.characers_) {
      return true;
    } else {
      cout << "Find two " << voice_actress1.GetName() <<
              " but they have different infomations.\n";
      return false;
    }
  } else {
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
          "\'C\' or \'c\' for characters\n";
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
    case 'E':
    case 'e':
      cout << "Enter the new enterprise:\n";
      getline(cin, enterprise_);
      break;
    case 'C':
    case 'c': {
      cout << "\'A\' or \'a\' for appending a new character\n" <<
        "other keys for replacing the old character infomation\n";
      cin >> cmd;
      cin.ignore(32767, '\n');
      cout << "Enter the names of characters:\n";
      string character;
      getline(cin, character);
      if (cmd == 'A' || cmd == 'a') {
        characers_ += "¡¢";
        characers_ += character;
      } else {
        characers_ = character;
      }
      break;
    }
    default:
      cerr << "Illegal command!\n";
      return;
  }
  cout << "Succeeded!\n" << *this << '\n';
}