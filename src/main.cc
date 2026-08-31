#include <iostream>

#include "suggest.h"

int main() {
  wordle::WordleSolver wordle;
  // wordle.input("abcde",
  //              {wordle::type::hit, wordle::type::miss, wordle::type::miss,
  //               wordle::type::miss, wordle::type::miss});
  // wordle.input("slate",
  //              {wordle::type::miss, wordle::type::miss, wordle::type::hit,
  //               wordle::type::miss, wordle::type::miss});
  wordle.input("slate",
               {wordle::type::miss, wordle::type::miss, wordle::type::miss,
                wordle::type::miss, wordle::type::blow});
  wordle.input("crony",
               {wordle::type::miss, wordle::type::blow, wordle::type::miss,
                wordle::type::miss, wordle::type::miss});
  wordle.input("HUMId",
               {wordle::type::miss, wordle::type::miss, wordle::type::hit,
                wordle::type::hit, wordle::type::miss});
  wordle.co_list();
  return 0;
}
