#include "analyzer.cpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void leerArchivo(Analyzer analyzer) {
  ifstream archivo;
  archivo.open("file.isa", ios::in);
  if (archivo.fail()) {
    cout << "Error abriendo el archivo \n";
  } else {
    while (!archivo.eof()) {
      string cadena;
      getline(archivo, cadena);

      if (cadena.find("si(") != string::npos) {
        cadena = analyzer.get_new_string("if(", cadena);
      }
      cout << cadena << endl;
    }
  }
  archivo.close();
}

int main() {
  Analyzer analyzer = Analyzer();
  leerArchivo(analyzer);
}
