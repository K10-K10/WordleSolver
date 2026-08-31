#ifndef INCLUDE_SUGGEST_H_
#define INCLUDE_SUGGEST_H_

#include <array>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

namespace wordle {
enum class type { hit, blow, miss };
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
inline std::vector<std::array<bool, 6>> blow(26, std::array<bool, 6>{false});
// is_blow, 0,1,2,3,4
inline std::vector<char> correct(5, ' ');
}  // namespace _wordle_

#endif
