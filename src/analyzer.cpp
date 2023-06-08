#include "./include/analyzer.h"
#include <string>

int Analyzer::get_position(string line, string ref) { return line.find(ref); }

string Analyzer::get_new_string(std::string ref, std::string cadena,
                                std::string new_string) {
  int index = Analyzer::get_position(cadena, ref);
  int last = index + ref.length();
  return cadena.substr(0, index) + new_string + cadena.substr(last);
}

void Analyzer::read_file() {

  ofstream new_file;
  new_file.open("file.cpp", ios::app);
  ifstream archivo;
  archivo.open("file.isa", ios::in);
  if (archivo.fail() || new_file.fail()) {
    cout << "Error abriendo el archivo \n";
  } else {
    while (!archivo.eof()) {
      string cadena;
      getline(archivo, cadena);

      if (cadena.find("si(") != string::npos) {
        cadena = this->get_new_string("si(", cadena, "if(");
      }

      if (cadena.find("principal(") != string::npos) {
        string aux = this->get_new_string("principal(", cadena, "int main(");
        cadena = aux;
      }
      if (cadena.find("#incluir") != string::npos) {
        string aux = this->get_new_string("#incluir", cadena, "#include");
        cadena = aux;
      }
      if (cadena.find("imprimir") != string::npos) {
        string aux = this->get_new_string("imprimir", cadena, "cout");
        cadena = aux;
      }
      if (cadena.find("_numero") != string::npos) {
        string aux = this->get_new_string("_numero", cadena, "int");
        cadena = aux;
      }
      new_file << cadena << endl;
    }
  }
  archivo.close();
  new_file.close();
}
