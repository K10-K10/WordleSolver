#include <iostream>
#include <fstream>
#include <string>

int main() {
  std::ifstream ifs("list1");
  std::ofstream ofs("list");
  std::string getline;
  std::string item;
  std::string line;
  if (ifs.is_open()) {
        while (std::getline(ifs, line)) {
          for(int i = 0;i < line.size();++i){
            if(i % 8 >=1&& i % 8 <= 5){
              item +=line[i];
            }
            else if(i% 8==7){
              ofs << item << std::endl;
              item.clear();
            }
          }
        }
        ifs.close();
    }
    return 0;
}
