
// Guarda el fichero con algun otro nombre para no generar conflictos con el del resto (como Bloom_Eric.cc)
// Esto, pero, implicará hacer cambios en el Makefile!

#include <iostream>
#include <cmath>
#include <map>
#include <vector>
using namespace std;


vector<bool> Bloom;	
vector<string> S, T;
int fp; //Num. Falsos Positivos

//Funcion de hash con el metodo de la division
//PRE: key es alfanumerico
int hash_f1(string &key, int &m) {
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
		val = ((val % m) + (aux % m)) % m;
	}
	return val;
}

//Funcion de hash con el metodo de la multiplicacion (random!!!)
//PRE: key es alfanumerico
int hash_f2(string &key, int &m) {
	float val = 0;
	for (int i = 0; i < key.size(); ++i) {
		int aux = 0;
		if ('a' <= key[i] and key[i] <= 'z') {
			aux = key[i] - 'a';
		}
		else if ('A' <= key[i] and key[i] <= 'A') {
			aux = key[i] - 'A';
		}
		else aux = key[i] - '0';

		val = ((int(val) % m) + (int(aux) % m)) % m;
	}
	float A = static_cast <float> (rand()) / static_cast <float> (RAND_MAX); // 0 <= A <= 1
	val *= A;
	return int(floor(val));
}

//Funcion de hash con el metodo de "folding"
//PRE: key es alfanumerico
int hash_f3(string &key, int &m) {
    int val = 0;
    for(int i = 0; i < key.length(); i += 2) {
    	val = key[i]*100 + key[i+2];
    }
    return (val % m);
}


//Por ahora no me preocupo de encontrar los falsos positivos: lo dejo para después...
void hashTests(string &key, int &m) {
	int h1 = hash_f1(key, m);
	int h2 = hash_f2(key, m);
	int h3 = hash_f3(key, m);

	if (Bloom[h1] == 1 or Bloom[h2] == 1 or Bloom[h3] == 1) {
		for (int i = 0; i != S.size(); ++i) {
			if (S[i] == key){
				cout << "Yes - ";
				++fp;
				break;	
			}
		}
		cout << "FP! - ";
	}
	else cout << "No  - ";

	cout << h1 << ", "  << h2 << ", "  << h3 << endl;
}

void BloomInsert(string &key, int &m) {
	int h1 = hash_f1(key, m);
	int h2 = hash_f2(key, m);
	int h3 = hash_f3(key, m);

	if (Bloom[h1] == 0) Bloom[h1] = 1;
	if (Bloom[h2] == 0) Bloom[h2] = 1;
	if (Bloom[h3] == 0) Bloom[h3] = 1;

	cout << h1 << ", "  << h2 << ", "  << h3 << endl;
}

int main () {
	cout << "Primero escribe el tamaño del filtro de Bloom: " << endl;
	int m; 		cin >> m;	//Bloom Size
	
	cout << "Seguidamente, escribe el tamaño y luego cada clave del primer conjunto:" << endl;
	int n;		cin >> n;	//Number Keys
	Bloom = vector<bool> (m, 0);
	S = vector<string> (n);
	
	for (int i = 0; i != n; ++i) {	
		cin >> S[i];
		BloomInsert(S[i], m);
	}

	cout << "Seguidamente, escribe el tamaño y luego cada clave del segundo (!) conjunto: " << endl;
	
	int k; cin >> k;
	T = vector<string> (k);
	for (int i = 0; i != k; ++i) {	
		cin >> T[i];
		hashTests(T[i], m);
	}

	cout << "Bloom filter result: ";
	for (int i = 0; i != m; ++i) {	
		cout << Bloom[i];
	}
	cout << endl;
	
}