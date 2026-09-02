#include "suggest.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

wordle::WordleSolver::WordleSolver() { init(); }

int wordle::WordleSolver::init() {
  ::std::ifstream ifs("list");
  std::string line;
  if (!ifs.is_open()) {
    std::cerr << "Error: word list can't open." << std::endl;
    return -1;
  }
  while (std::getline(ifs, line)) {
    this->list.push_back(line);
    ++this->size;
  }
  std::cout << "Size: " << this->size << std::endl;
  return 0;
}

void wordle::WordleSolver::update_list() {
  if (this->list.empty()) {
    return;
  }

  std::vector<std::string> filtered;
  filtered.reserve(this->list.size());

  for (const std::string& candidate : this->list) {
    bool keep = true;
    std::unordered_set<char> blow_cnt;
    for (int j = 0; j < 5; ++j) {
      const char c = candidate[j];
      if (this->correct[j] != ' ' && this->correct[j] != c) {
        keep = false;
        break;
      }
      if (this->miss.count(c)) {
        keep = false;
        break;
      }
      if (this->blow[int(c - 'a')][0]) {
        blow_cnt.insert(c);
      }
      if (this->blow[int(c - 'a')][0] && !this->blow[int(c - 'a')][1 + j]) {
        keep = false;
        break;
      }
    }
    if (blow_cnt != this->blow_cnt) {
      keep = false;
    }
    if (keep) {
      for (int i = 0; i < 5; ++i) {
        ++this->cnt_char[i][candidate[i] - 'a'];
      }
      filtered.push_back(candidate);
    }
  }

  this->list.swap(filtered);
  this->size = static_cast<int>(this->list.size());
  return;
}

void wordle::WordleSolver::co_list() {
  for (std::string s : this->list) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
  std::cout << this->list.size() << std::endl;
  return;
}

void wordle::WordleSolver::input(std::string word,
                                 std::array<wordle::type, 5> result) {
  if (word.size() != 5) {
    std::cerr << "Error: word must 5 letters." << std::endl;
    return;
  }
  std::transform(word.begin(), word.end(), word.begin(),
                 [](unsigned char c) { return std::tolower(c); });
  for (int i = 0; i < 5; ++i) {
    if (result[i] == wordle::type::miss) {
      this->miss.insert(word[i]);
    } else if (result[i] == wordle::type::hit) {
      this->correct[i] = word[i];
    } else {
      int diff = word[i] - 'a';
      this->blow[diff][1 + i] = false;
      if (!this->blow[diff][0]) {
        this->blow_cnt.insert(word[i]);
        this->blow[diff][0] = true;
        for (int j = 0; j < 5; ++j) {
          this->blow[diff][1 + j] = (i == j) ? false : true;
        }
      }
    }
  }
  this->update_list();
  return;
}

std::string wordle::WordleSolver::suggest() {}
