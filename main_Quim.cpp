#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "BloomFilter.h"
using namespace std;


int main () {

    int filterSize,numHashFunctions, keysNum;
    ifstream addFile("claus.txt");
    string line;
    getline(addFile,line);
    istringstream iss(line);
    iss >> filterSize >> numHashFunctions >> keysNum;
    BloomFilter filter (filterSize,numHashFunctions,keysNum);
    string key;
    while (getline(addFile,key)) {
        filter.addKey(key);
    }

    addFile.close();
    ifstream queryFile("test.txt");

    while (getline(queryFile,key)) {
        bool member = filter.queryKey(key);
        if (member == false) cout << "key " << key << " is not in the set." << endl;
        else cout << "key " << key << " maybe is in the set." << endl;
    }
    queryFile.close();


}
