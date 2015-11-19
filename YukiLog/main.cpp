#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "date.h"
#include "person.h"
#include "voice-actress.h"
#include "character.h"

using namespace std;

int main()
{
	list<VoiceActress> voice_actress_list;
	CreatPersonList(voice_actress_list, "dat/voice-actress.dat");
	SavePeosonList(voice_actress_list, "dat/voice-actress.dat");



	cout << "\nProgram runs normally to the end!\n";
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

  return 0;
}

