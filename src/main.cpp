#include "analyzer.cpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main() {
  Analyzer analyzer = Analyzer();
  analyzer.read_file();
}
