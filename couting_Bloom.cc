#include <iostream>
#include <string>
#include <climits>
#include <algorithm>
#include <set>
#include "couting_Bloom.h"

couting_Bloom::couting_Bloom(int size, int numHash) {

    filter = vector <int> (size);
    filterSize = size;
    hashFunctionsNum = numHash;
}

vector <int> couting_Bloom::transformStringToInt(string key) {
    int valueHash1 = 0;
    int valueHash2 = 0;
    int cont = 0;
    int aux = 0;
    for (int i = 0;i < key.size();i++) {
        valueHash1 = ((valueHash1*128)%filterSize + ((int)key[i])%filterSize)%filterSize;
        if (cont < 2) {
            aux = aux*128 + (int)key[i];
            ++cont;
            if (cont == 2) {
                cont = 0;
                valueHash2 += aux;
                aux = 0;
            }
        }
    }
    valueHash2 += aux;
    valueHash2%filterSize;
    vector <int> indexos = vector <int> (2);
    indexos[0] = valueHash1;
    indexos[1] = valueHash2;
    return indexos;
}




void couting_Bloom::insert (string key) {
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        ++filter[index];
    }

}

bool couting_Bloom::contains(string key) {
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        if (filter[index] == 0) return false;
    }
    return true;

}

void couting_Bloom::remove(string key)
{
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        if (filter[index] > 0) --filter[index];
    }
}


int couting_Bloom::falseNeg(set<string> keys, vector<string> & erases) {
    
    int cont = 0;
    set <string>::iterator it = keys.begin();
    while (it != keys.end()) {
        string key = *it;
        vector <int> representation = transformStringToInt(key);
        int contAux = 0;
        bool found = false;
        for (int i = 0;i < hashFunctionsNum and not found;++i) {
            int index = (representation[0] + (i*representation[1]))%filterSize;
            if (filter[index] == 0) {
                for (int j = 0;j < erases.size();++j) {
                    if (key != erases[j]) ++contAux;
                }
                if (contAux == erases.size()) {
                    found = true;
                    ++cont;
                }
            }
            
        }
        ++it;
    }
    return cont;
}


