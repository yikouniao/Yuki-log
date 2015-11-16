#include "stdafx.h"
#include "voice-actress.h"

VoiceActress::VoiceActress() : Person(), moe_rate_(0.0), enterprise_("NULL"), characers_("NULL") {}

VoiceActress::VoiceActress(const Person &person, const double &moe_rate, const string &enterprise, const string &characters)
		: Person(person), moe_rate_(moe_rate), enterprise_(enterprise), characers_(characters) {}
