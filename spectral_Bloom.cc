#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include "spectral_Bloom.h"

spectral_Bloom::spectral_Bloom(int size, int numHash) {

    filter = vector <int> (size);
    filterSize = size;
    hashFunctionsNum = numHash;

}

vector <int> spectral_Bloom::transformStringToInt(string key) {
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




void spectral_Bloom::insert (string key) {
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        ++filter[index];
    }

}

bool spectral_Bloom::contains(string key) {
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        if (filter[index] == 0) return false;
    }
    return true;

}

void spectral_Bloom::remove(string key)
{
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        if (filter[index] > 0) --filter[index];
    }
}


int spectral_Bloom::num_occurs(string key)
{
    int smallest = INT_MAX;
    vector <int> representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        if (filter[index] < smallest) smallest = filter[index];
    }
    return smallest;
}

