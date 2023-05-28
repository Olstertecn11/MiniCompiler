#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int get_position(string line, string ref) {
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
        int pos = get_position(cadena, "si(");
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
