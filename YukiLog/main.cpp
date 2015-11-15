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

#define TEST_LIST 0
#if TEST_LIST
void TestList(list<Date>& li) {
	li.push_back(Date(2003, 7, 6));
	li.push_back({ 2004, 7, 6 });
}
#endif

int main()
{
#if TEST_LIST
	list<Date> li;
	TestList(li);
	//li.push_back(3);
	list<Date>::const_iterator it;
	it = li.begin();
	while (it != li.end()) {
		cout << *it << '\n';
		++it;
	}
#endif

	list<VoiceActress> voice_actress_list;
	CreatPersonList(voice_actress_list, "dat\\voice-actress.dat");
	SavePeosonList(voice_actress_list, "dat\\voice-actress.dat");



	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user

  return 0;
}

