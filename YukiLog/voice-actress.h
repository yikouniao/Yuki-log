#pragma once

#include "person.h"

class VoiceActress : public Person {
private:
	string enterprise_;
	string characers_;
public:
	VoiceActress(const Person &person, const string &enterprise, const string &characters);
};