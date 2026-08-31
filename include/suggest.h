#ifndef INCLUDE_SUGGEST_H_
#define INCLUDE_SUGGEST_H_

#include <array>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

namespace wordle {
enum class type { hit, blow, miss };

class WordleSolver {
 public:
  WordleSolver();
  void co_list();
  void input(std::string word, std::array<type, 5> result);
  std::string suggest();

 private:
  int init();
  void update_list();
  int size = 0;
  std::vector<std::string> list;
  std::vector<std::string> suggest_list;
  std::unordered_set<char> miss;
  std::vector<std::array<bool, 6>> blow =
      std::vector<std::array<bool, 6>>(26, std::array<bool, 6>{false});
  // is_blow, 0,1,2,3,4
  std::unordered_set<char> blow_cnt;
  std::vector<char> correct = std::vector<char>(5, ' ');
};
}  // namespace wordle

#endif
