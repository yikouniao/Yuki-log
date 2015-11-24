#pragma once

#include "person.h"

class VoiceActress : public Person {
 private:
  double moe_rate_;
  string enterprise_;
  string characers_;
 public:
  VoiceActress();
  VoiceActress(const Person& person, const double& moe_rate,
               const string& enterprise, const string& characters);
  template <typename StreamType>
  friend StreamType& operator>>(StreamType& in, VoiceActress& voice_actress);
  template <typename StreamType>
  friend StreamType& operator<<(StreamType& out, const VoiceActress& voice_actress);
  friend bool operator==(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2);
  friend bool operator<(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2);
  friend bool operator>(const VoiceActress& voice_actress1, const VoiceActress& voice_actress2);
  void Modify();
};

// throws an exception if an internal error occurred.
template <typename StreamType>
StreamType& operator>>(StreamType& in, VoiceActress& voice_actress) {
  string name;
  cout << "\nGetting name...\n";
  getline(in, name);
  voice_actress.SetName(name);
  Date date;
  in >> date;
  voice_actress.SetBirthday(date);
  string moe_rate;
  cout << "Getting moe-rate...\n";
  getline(in, moe_rate);
  voice_actress.moe_rate_ = stod(moe_rate);
  cout << "Getting enterprise...\n";
  getline(in, voice_actress.enterprise_);
  cout << "Getting characers...\n";
  getline(in, voice_actress.characers_);
  return in;
}

// throws an exception if an internal error occurred.
template <typename StreamType>
StreamType& operator<<(StreamType& out, const VoiceActress& voice_actress) {
  out << "\n" << voice_actress.GetName() << '\n' <<
         voice_actress.GetBirthday() << '\n' <<
         voice_actress.moe_rate_ << '\n' <<
         voice_actress.enterprise_ << '\n' <<
         voice_actress.characers_ << '\n';
  return out;
}