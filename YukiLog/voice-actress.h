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
	void ReadAPersonFromFile(ifstream& voice_actress_file);
	void WriteAPersonToFile(ofstream& voice_actress_file);
};