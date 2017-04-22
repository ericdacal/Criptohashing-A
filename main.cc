#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BloomFilter_Quim.h"
#include "keyGenerator.h"
using namespace std;


int main () {
    
    int filterSize,numHashFunctions, keysNum, maxKeys, numFitxers;
    cout << "Introdueix el tamany del filtre" << endl;
    cin >> filterSize;
    cout << "Introdueix el nombre de funcions de Hash" << endl;
    cin >> numHashFunctions;
    
    cout << "Introdueix el nombre de fitxers de test a probar" << endl;
    cin >> numFitxers;
    keyGenerator generador(5,5);
    generador.generateKeys();
    
    ifstream addFile("claus.txt");
    string line;
    getline(addFile,line);
    istringstream iss(line);
    
    BloomFilter filter (filterSize,numHashFunctions,5, 40);
    string key;
    while (getline(addFile,key)) {
        filter.addKey(key);
    }
    cout << "-----------------" << endl;
    addFile.close();
    for (int i = 1;i <= numFitxers;++i) {
    	string file = "test";
        file.append(to_string(i));
        file.append(".txt");
    	ifstream queryFile;
    	queryFile.open(file);

    	    while (getline(queryFile,key)) {
    	        bool member = filter.queryKey(key);
    	        if (member == false) cout << "key " << key << " is not in the set." << endl;
    	        else cout << "key " << key << " maybe is in the set." << endl;
    	    }
    	    queryFile.close();
    	    
    }


}
