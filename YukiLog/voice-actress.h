#pragma once

#include "person.h"
#include <fstream>

class VoiceActress : public Person {
private:
	double moe_rate_;
	string enterprise_;
	string characers_;
public:
	VoiceActress();
	VoiceActress(const Person& person, const double& moe_rate, const string& enterprise, const string& characters);

	template <typename TypeStream>
	friend TypeStream& operator>>(TypeStream& in, VoiceActress& voice_actress);

	template <typename TypeStream>
	friend TypeStream& operator<<(TypeStream& out, const VoiceActress& voice_actress);
};

template <typename TypeStream>
TypeStream& operator>>(TypeStream& in, VoiceActress& voice_actress) {
		string name;
		getline(in, name);
		voice_actress.SetName(name);

		Date date;
		in >> date;
		voice_actress.SetBirthday(date);

		string moe_rate;
		getline(in, moe_rate);
		voice_actress.moe_rate_ = stod(moe_rate);
		getline(in, voice_actress.enterprise_);
		getline(in, voice_actress.characers_);
		return in;
}

template <typename TypeStream>
TypeStream& operator<<(TypeStream& out, const VoiceActress& voice_actress) {
	out << voice_actress.GetName() << '\n'
			<< voice_actress.GetBirthday() << '\n'
			<< voice_actress.moe_rate_ << '\n'
			<< voice_actress.enterprise_ << '\n'
			<< voice_actress.characers_;
	return out;
}