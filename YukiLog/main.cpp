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
  UniquePersonList(voice_actress_list);
  PrintPersonList(voice_actress_list);
  list<VoiceActress>::iterator it = voice_actress_list.begin();
  FindPerson(voice_actress_list, it, 2);
  it->Modify();
  if (FindPerson(voice_actress_list, it, "Ã©Ò°°®ÒÂ"))
    DeletePerson(voice_actress_list, it);
  DeletePerson(voice_actress_list, "Öñ´ï²ÊÄÎ");
  SavePeosonList(voice_actress_list, "dat/voice-actress.dat");

  cout << "\nPress any key to exit the program.\n";
  cin.clear();  // reset any error flags
  cin.ignore(32767, '\n');  // ignore any characters in the input buffer until we find an enter character
  cin.get();  // get one more char from the user

  return 0;
}