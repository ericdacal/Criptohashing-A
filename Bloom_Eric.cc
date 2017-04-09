
// Guarda el fichero con algun otro nombre para no generar conflictos con el del resto (como Bloom_Eric.cc)
// Esto, pero, implicará hacer cambios en el Makefile!

#include <iostream>
#include <string>

int hash(std::string key, int m) {
    int out = 0;
    for(int i = 0; i < key.length();++i) {
        if(key[i] == 'a' and key[i] == 'z') out += int(key[i] - 'a');
        else if(key[i] == 'A' and key[i] == 'Z') out += int(key[i] - 'z');
        else out += key[i];
        
        out *= 10;
    }
    return (out % m);
}


int main () {
	//Code
  std::string key;
  int m;
  std::cout << "Introduce la clave a insertar en el conjunt: " << std::endl;
  std::cin >> key;
  std::cout << "Introduce el tamaño del filtro de Bloom: " << std::endl;
  std::cin >> m;
  std::cout << hash(key, m) << std::endl; 
}
