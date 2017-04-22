#include <iostream>
#include <vector>
#include <string>


int hash(std::string &key, int m, int k) {
	int val = 0;
	for (int i = 0; i < key.size(); ++i) {
		int aux = 0;
		if ('a' <= key[i] and key[i] <= 'z') {
			aux = key[i] - 'a';
		}
		else if ('A' <= key[i] and key[i] <= 'A') {
			aux = key[i] - 'A';
		}
		else aux = key[i] - '0';

		//mod arithmetic
		val = ((val % m) + (aux % m)) % m + k;
	}
	return (val < m) ? val : val - m;
}


void BloomInsert(std::string &key, int m, int k, std::vector<bool> &Bloom) {
    int h = hash(key, m, k);
	if(not Bloom[h]) Bloom[h] = true;
}


int main () {
	std::cout << "Primero escribe el tamaño del filtro de Bloom: " << std::endl;
	int m; 		std::cin >> m;	//Bloom Size
	
	std::cout << "Seguidamente, escribe el tamaño del conjunto:" << std::endl;
	int n;		std::cin >> n;	//Number Keys
	std::vector<bool> Bloom(m, 0);
	std::vector< std::string > S(n);
    std::cout << "Escribe cuantas funciones de hash deseas:" << std::endl;
    int k;
    std::cin >> k;
    std::cout << "Introduce los elementos del conjunto: " << std::endl;
	for (int i = 0; i < n; ++i) {	
		std::cin >> S[i];
		for(int j = 0; j < k; ++j) BloomInsert(S[i], m, j, Bloom);
	}
    

    std::cout << "Bloom filter result: ";
	for (int i = 0; i != m; ++i) {	
		std::cout << Bloom[i] << ' ';
	}
	std::cout << std::endl;
	
}
