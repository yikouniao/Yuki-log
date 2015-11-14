#include "stdafx.h"
#include "voice-actress.h"

VoiceActress::VoiceActress() : Person(), moe_rate_(0.0), enterprise_("NULL"), characers_("NULL") {}

VoiceActress::VoiceActress(const Person &person, const double &moe_rate, const string &enterprise, const string &characters)
		: Person(person), moe_rate_(moe_rate), enterprise_(enterprise), characers_(characters) {}

void VoiceActress::ReadAPersonFromFile(fstream& voice_actress_file, VoiceActress& new_voice_actress) {
	string name;
	getline(voice_actress_file, name);
	new_voice_actress.SetName(name);
	Date date;
	//cin >> date;



}