#include "YUKI.N.h"
#include "person.h"
#include "character.h"
#include "voice-actress.h"

namespace YUKI_N {

bool Welcome() {
  cout << "YUKI.N:\n...\n" <<
          "Welcome to Nagato Yuki's log.\n" <<
          "Here logs some important persons monitored by 情報統合思念体.\n" <<
          "Unadmitted visitors will be prevented from contact with the " <<
          "universe by force.\n" <<
          "Press Enter to continue " <<
          "or any other keys to exit back to your normal life.\n\n";
  while (!_kbhit()) {}
  if (_getch() == ENTER) {
    return true;
  } else {
    return false;
  }
}

void MainUI() {
  list<Character> character_list;
  list<VoiceActress> voice_actress_list;
  while (1) {
    int person_kind = SelectPersonType();
    if (person_kind == CHARACTER) {
      PersonUI(character_list, "dat/character.dat");
    } else if (person_kind == VOICE_ACTRESS) {
      PersonUI(voice_actress_list, "dat/voice-actress.dat");
    } else {
      return;
    }
  }
}

int SelectPersonType() {
  cout << "\nThere're two kinds of persons: character and voice actress.\n" <<
          "Characters are moe girls may provide possibility for evolution.\n" <<
          "And we've found that voice actresses may be the sources " <<
          "of the characters' moe power." <<
          "Press \'C\' or \'c\' to handle information of characters.\n" <<
          "Press \'V\' or \'v\' for voice actresses.\n" <<
          "And Esc to exit.\n";
  char cmd;
  do {
    while (!_kbhit()) {}
    cmd = _getch();
    switch (cmd) {
      case 'C':
      case 'c':
        return CHARACTER;
      case 'V':
      case 'v':
        return VOICE_ACTRESS;
      case ESC:
        return -1;
      default:
        break;
    }
  } while (1);
}

void PersonUIGuide() {
  cout << "\n\'P\' or \'p\' for printing all the persons.\n" <<
          "\'U\' or \'u\' for sorting and deleting duplicate nodes.\n" <<
          "\'A\' or \'a\' for adding a person.\n" <<
          "\'F\' or \'f\' for finding and printing a person.\n" <<
          "\'M\' or \'m\' for modifying a person.\n" <<
          "\'D\' or \'d\' for deleting a person.\n" <<
          "\'S\' or \'s\' for saving the persons into specific file.\n" <<
          "And Esc for going back.\n";
}

}  // namespace YUKI_N