#ifndef INCLUDE_SUGGEST_H_
#define INCLUDE_SUGGEST_H_

#include <vector>
#include <string>
#include <array>
#include <map>
#include <unordered_set>

namespace wordle{
  enum class type{
    hit,
    blow,
    none
  };
  void input(std::string word,std::array<type,5 > result);
  std::string suggest();
}

namespace _wordle_{
  int init();
  int size;
  std::vector<std::string> list;
  std::vector<std::string> suggest_list;
  std::unordered_set<char> miss;
  std::vector<std::vector<char>> blow(5,std::vector<char>());// set un correct index;
  std::vector<char> correct(5);
}

#endif
