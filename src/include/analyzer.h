#include <fstream>
#include <iostream>
#include <stdlib.h>
using namespace std;

class Analyzer {
public:
  static int get_position(std::string, std::string);
  string get_new_string(std::string, std::string);
  void read_file();
};
