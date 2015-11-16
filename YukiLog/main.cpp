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
	//list<VoiceActress> voice_actress_list;
	//CreatPersonList(voice_actress_list, "dat\\voice-actress.dat");
	//SavePeosonList(voice_actress_list, "dat\\voice-actress.dat");

#if 0
	//ifstream inf("z.txt");
	Date temp1;
	try {
		cin >> temp1;
	}
	catch (char* strException) {
		cerr << strException;
	}
	catch (...) {
		cerr << "This date is illegal!Pleast retry.\n";
	}
#endif

	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

  return 0;
}

