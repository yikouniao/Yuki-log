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
  cout << "YUKI.N:\n...\n";
  list<Character> character_list;
  CreatPersonList(character_list, "dat/character.dat");
  UniquePersonList(character_list);
  SavePeosonList(character_list, "dat/character.dat");
  list<VoiceActress> voice_actress_list;
  CreatPersonList(voice_actress_list, "dat/voice-actress.dat");
  UniquePersonList(voice_actress_list);
  SavePeosonList(voice_actress_list, "dat/voice-actress.dat");

#if 0
  list<Character> character_list;
  CreatPersonList(character_list, "dat/character.dat");
  UniquePersonList(character_list);
  PrintPersonList(character_list);
  list<Character>::iterator it = character_list.begin();
  FindPerson(character_list, it, 2);
  it->Modify();
  if (FindPerson(character_list, it, "Ïã·çÖÇÄË"))
    DeletePerson(character_list, it);
  DeletePerson(character_list, "×µÃûÕæ°×");
  SavePeosonList(character_list, "dat/character.dat");
#endif

  cout << "\nPress any key to exit the program.\n";
  // reset any error flags
  cin.clear();
  // ignore any characters in the input buffer until we find an enter character
  cin.ignore(32767, '\n');
  // get one more char from the user
  cin.get();

  return 0;
}