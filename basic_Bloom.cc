#include "basic_Bloom.h"
#include <cstdlib>
#include <math.h>
#include <vector>


basic_Bloom::basic_Bloom(int size, int numHash) {

    filter = vector <bool> (size);
    filterSize = size;
    hashFunctionsNum = numHash;
}



vector <int> basic_Bloom::transformStringToInt(string key) {
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
    //cout << valueHash1 << " " << valueHash2 << endl;
    vector <int> indexos = vector <int> (2);
    indexos[0] = valueHash1;
    indexos[1] = valueHash2;
    return indexos;
}



void basic_Bloom::insert (string key) {
    vector <int> representation = transformStringToInt(key);
    //cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre insert " << index << endl;
        if (filter[index] == false) filter[index] = true;
    }

}

bool basic_Bloom::contains(string key) {
    vector <int> representation = transformStringToInt(key);
    //cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre contains " << index << endl;
        if (filter[index] == false) return false;
    }
    return true;

}

