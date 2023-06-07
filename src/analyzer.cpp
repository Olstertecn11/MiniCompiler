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

string Analyzer::get_new_string(std::string ref, std::string cadena) {
  int pos = Analyzer::get_position(cadena, "si(");
  if (pos != -1) {
    string aux = "";
    for (int i = 0; i < cadena.length(); i++) {
      if (i < pos || i > pos + 2) {
        aux += cadena[i];
      } else {
        aux += ref;
        i = pos + 2;
      }
    }
    return aux;
  } else {
    return "";
  }
}
