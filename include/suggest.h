#ifndef INCLUDE_SUGGEST_H_
#define INCLUDE_SUGGEST_H_

#include <array>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

namespace wordle {
enum class type { hit, blow, none };
void input(std::string word, std::array<type, 5> result);
std::string suggest();
}  // namespace wordle

namespace _wordle_ {
int init();
inline int size;
void update_list();
inline std::vector<std::string> list;
inline std::vector<std::string> suggest_list;
inline std::unordered_set<char> miss;
inline std::vector<std::unordered_set<char>> blow(5);  // set un correct index;
inline std::vector<char> correct(5, ' ');
}  // namespace _wordle_

#endif
