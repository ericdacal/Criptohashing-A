
// Guarda el fichero con algun otro nombre para no generar conflictos con el del resto (como Bloom_Eric.cc)
// Esto, pero, implicará hacer cambios en el Makefile!

#include <iostream>
#include <string>
#include <vector>

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


void insert(std::string key, std::vector<bool>& Bloom_filter) {
    int pos = hash(key, Bloom_filter.size());
    Bloom_filter[pos] = true;
}

bool member(std::string key, std::vector<bool>& Bloom_filter) {
    int pos = hash(key, Bloom_filter.size());
    return Bloom_filter[pos];
}


int main () {
	//Code
  int m;
  std::cout << "Introduce el tamaño del filtro de Bloom: " << std::endl;
  std::cin >> m;
  std::vector<bool> Bloom_filter (m);
  while(true) {
    std::cout << "Escoge una opción:" << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Member" << std::endl;
    int option;
    std::cin >> option;
    if(option == 1) {
      std::cout << "Introduce la clave ha insertar: " << std::endl;
      std::string key;
      std::cin >> key;
      insert(key, Bloom_filter);
    }
    else {
      std::cout << "Introduce la clave a buscar en el filtro: " << std::endl;
      std::string key;
      std::cin >> key;
      std::cout << member(key, Bloom_filter) << std::endl;
    }
  }
}
