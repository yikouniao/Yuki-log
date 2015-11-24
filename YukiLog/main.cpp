#include "stdafx.h"
#include "YUKI.N.h"

int main()
{
  using namespace std;
  using namespace YUKI_N;

  if (!Welcome())
    return 0;
  MainUI();
  return 0;
}