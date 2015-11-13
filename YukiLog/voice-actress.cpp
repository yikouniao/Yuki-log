#include "stdafx.h"
#include "voice-actress.h"

VoiceActress::VoiceActress(const Person &person, const string &enterprise, const string &characters)
		: Person(person), enterprise_(enterprise), characers_(characters) {}