#include "./include/analyzer.h"

int Analyzer::get_position(string line, string ref) {
  for (int i = 0; i < line.length(); i++) {
    string cadena = "";
    for (int j = i; j < line.length(); j++) {
      cadena += line[j];
      if (cadena.length() == ref.length()) {
        if (cadena == ref)
          return i;
        else
          cadena = "";
      }
    }
  }
  return -1;
}
