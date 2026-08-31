#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>
#include <string>

#include "suggest.h"

int main() {
  wordle::WordleSolver wordle;
  std::string input;
  std::string result;
  while (true) {
    std::cout << "-----" << std::endl;
    std::cout << "Input: " << std::flush;
    std::cin >> input;
    if (input.size() != 5) {
      std::cerr << "Error: word length." << std::endl;
      continue;
    }
    std::cout << "h,b,m: " << std::flush;
    std::cin >> result;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    if (result.size() != 5) {
      std::cerr << "Error: input length must be 5" << std::endl;
      return -1;
    }

    std::array<wordle::type, 5> res;
    int cnt = 0;

    for (char c : result) {
      if (cnt >= 5) break;
      switch (c) {
        case 'h':
          res[cnt++] = wordle::type::hit;
          break;
        case 'b':
          res[cnt++] = wordle::type::blow;
          break;
        case 'm':
          res[cnt++] = wordle::type::miss;
          break;
        default:
          std::cerr << "Error: unexpected char '" << c << "'" << std::endl;
          return -1;
      }
    }
    wordle.input(input, res);
    wordle.co_list();
  }
  return 0;
}
