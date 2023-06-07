#include "analyzer.cpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void leerArchivo() {
  ifstream archivo;
  archivo.open("file.isa", ios::in);
  if (archivo.fail()) {
    cout << "Error abriendo el archivo \n";
  } else {
    while (!archivo.eof()) {
      string cadena;
      getline(archivo, cadena);
      if (cadena.find("si(") != string::npos) {
        int pos = Analyzer::get_position(cadena, "si(");
        if (pos != -1) {
          string aux = "";
          string ref = "if(";
          for (int i = 0; i < cadena.length(); i++) {
            if (i < pos || i > pos + 2) {
              aux += cadena[i];
            } else {
              aux += ref;
              i = pos + 2;
            }
          }
          cadena = aux;
        } else {
          cout << "null \n";
        }
      }
      cout << cadena << endl;
    }
  }
  archivo.close();
}

int main() { leerArchivo(); }
