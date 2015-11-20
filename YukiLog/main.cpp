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

#define IN_FROM_FILE 1
#if IN_FROM_FILE
	ifstream person_file("dat/voice-actress.dat");
	if (!person_file)
	{
		cerr << "voice-actress.dat could not be opened!\n" << endl;
		cin.get();
		exit(1);
	}
	AddPersonToList(voice_actress_list, person_file);
	person_file.close();
#else
	AddPersonToList(voice_actress_list, cin);
#endif

	SavePeosonList(voice_actress_list, "dat/voice-actress.dat");



	cout << "\nProgram runs normally to the end!\n";
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

  return 0;
}

