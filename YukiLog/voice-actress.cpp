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
      cout << "Find two " << voice_actress1.GetName()
           << " but they have different infomations.\n";
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