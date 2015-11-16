#include "stdafx.h"
#include "voice-actress.h"

VoiceActress::VoiceActress() : Person(), moe_rate_(0.0), enterprise_("NULL"), characers_("NULL") {}

VoiceActress::VoiceActress(const Person &person, const double &moe_rate, const string &enterprise, const string &characters)
		: Person(person), moe_rate_(moe_rate), enterprise_(enterprise), characers_(characters) {}

void VoiceActress::ReadAPersonFromFile(ifstream& voice_actress_file) {
	string name;
	getline(voice_actress_file, name);
	SetName(name);
	Date date;
	//DateIfstream(voice_actress_file, date);
	SetBirthday(date);

	string moe_rate;
	getline(voice_actress_file, moe_rate);
	moe_rate_ = stod(moe_rate);
	getline(voice_actress_file, enterprise_);
	getline(voice_actress_file, characers_);
}

void VoiceActress::WriteAPersonToFile(ofstream& voice_actress_file) {
	voice_actress_file << GetName() << '\n';
	DateOfstream(voice_actress_file, GetBirthday());
	voice_actress_file << '\n' << moe_rate_ << '\n' << enterprise_ << '\n' << characers_ << '\n';
}