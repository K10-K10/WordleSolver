#include "suggest.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <unordered_set>

int _wordle_::init(){
  ::std::ifstream ifs("list");
  std::string line;
  if (!ifs.is_open()){
    std::cerr<< "Error: word list can't open." << std::endl;\
    return -1;
  }
  while(std::getline(ifs, line)){
    _wordle_::list.push_back(line);
    ++size;
  }
  return 0;
}

void wordle::input(std::string word, std::array<wordle::type,5> result){
  if(!::_wordle_::list.empty()){
    ::_wordle_::init();
  }
  for(int i = 0;i < 5;++i){
    if(result[i] == wordle::type::none){
      ::_wordle_::miss.insert(word[i]);
    }
    else if (result[i] == wordle::type::hit){
      ::_wordle_::correct[i] = word[i];
    }else{
      for(char c: _wordle_::blow[i]){
        if(c == word[i]){
          return;
        }
      }
      _wordle_::blow[i].push_back(word[i]);
    }
  }
  return;
}
