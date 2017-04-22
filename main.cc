#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BloomFilter_Quim.h"
#include "keyGenerator.h"
using namespace std;


int main () {
    int numFitxers;
    cout << "Introdueix el nombre de fitxers de test a probar" << endl;
    cin >> numFitxers;
    int filterSize,numHashFunctions, keysNum, maxKeys;
    ifstream addFile("claus.txt");
    string line;
    getline(addFile,line);
    istringstream iss(line);
    iss >> filterSize >> numHashFunctions >> keysNum >> maxKeys;
    BloomFilter filter (filterSize,numHashFunctions,keysNum, maxKeys);
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
