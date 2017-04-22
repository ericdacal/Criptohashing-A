#include <iostream>
#include <vector>
#include <string>
#include <climits>


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



int num_occurs(std::string item,int m, int k, std::vector<int> &Bloom)
{
    int smallest = INT_MAX;
    for(int i = 0; i < k; i++) {
        if(Bloom[hash(item,m,k)] < smallest) smallest = Bloom[hash(item,m,k)];
    }
    return smallest;
}

void BloomInsert(std::string &key, int m, int k, std::vector<int> &Bloom) {
    int h = hash(key, m, k);
	++Bloom[h];
}

void BloomRemove(std::string &key, int m, int k,std::vector<int> &Bloom) {
    int h = hash(key, m, k);
	--Bloom[h];
}


bool contains(std::string item, int m, int k, std::vector<int> &Bloom)
{
    for(int i = 0; i < k; i++) {
        if(Bloom[hash(item, m, k)] = 0) return false;
    }
    return true;
}


int main () {
	std::cout << "Primero escribe el tamaño del filtro de Bloom: " << std::endl;
	int m; 		std::cin >> m;	//Bloom Size
	
	std::cout << "Seguidamente, escribe el tamaño del conjunto:" << std::endl;
	int n;		std::cin >> n;	//Number Keys
	std::vector<int> Bloom(m, 0);
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
