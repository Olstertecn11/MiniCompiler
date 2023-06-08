#include "./include/analyzer.h"
#include <string>

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

void Analyzer::read_file() {
  ifstream archivo;
  archivo.open("file.isa", ios::in);
  if (archivo.fail()) {
    cout << "Error abriendo el archivo \n";
  } else {
    while (!archivo.eof()) {
      string cadena;
      getline(archivo, cadena);

      if (cadena.find("si(") != string::npos) {
        cadena = this->get_new_string("if(", cadena);
      }

      if (cadena.find("principal(") != string::npos) {
        cout << "here" << endl;
        cadena = this->get_new_string("main(", cadena);
      }
      cout << cadena << endl;
    }
  }
  archivo.close();
}
