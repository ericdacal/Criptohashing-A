#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include "spectral_Bloom.h"

spectral_Bloom::spectral_Bloom(int size, int numHash, int maxKeys) {

    filter = vector <int> (size);
    filterSize = size;
    hashFunctionsNum = numHash;
    maxNumKeys = maxKeys;
    createTwoHashFunctions();
}

vector <int> erastosthenesSieves(int maxNumKeys) {

    vector <bool> isPrime = vector <bool> ((2*maxNumKeys)+1,true);
    vector <int> primes = vector <int> ();
    vector <int> smallPrimeFactor = vector <int> ((2*maxNumKeys)+1);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2;i <= 2*maxNumKeys;++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            smallPrimeFactor[i] = i;
        }
        for (int j = 0;j < primes.size() and primes[j] <= smallPrimeFactor[i] and i*primes[j] <= 2*maxNumKeys;++j) {
                isPrime[i*primes[j]] = false;
                smallPrimeFactor[i*primes[j]] = primes[j];
        }

    }
    return primes;
}


void spectral_Bloom::createTwoHashFunctions() {
    vector <int> aux = erastosthenesSieves(maxNumKeys);
    for (int i = 0;i < aux.size();++i) {
        if (aux[i] >= maxNumKeys) primes.push_back(aux[i]);
    }
    srand(time(NULL));
    prime = primes[rand()%primes.size()];
    a1 = (rand()%prime);
    if (a1 == 0) a1 = 1;
    b1 = rand()%prime;
    a2 = (rand()%prime);
    if (a2 == 0) a2 = 1;
    b2 = rand()%prime;
    while (a1 == a2) a2 = rand()%prime + 1;
    while (b1 == b2) b2 = rand()%prime;
    //cout << prime << " " << a1 << " " << b1 << " " << a2 << " " << b2 << endl;
}

vector <int> spectral_Bloom::transformStringToInt(string key) {
    int valueHash1 = 0;
    int valueHash2 = 0;
    for (int i = 0;i < key.size();i++) {
        valueHash1 = ((valueHash1*128)%prime + ((int)key[i])%prime)%prime;
        valueHash2 = ((valueHash2*128)%prime + ((int)key[i])%prime)%prime;
    }
   // cout << prime << " " << filterSize << endl;
    valueHash1 = (valueHash1 * a1%prime)%prime;
    valueHash1 = (valueHash1%prime + b1%prime)%prime;
    valueHash1 = valueHash1%filterSize;

    valueHash2 = (valueHash2 * a2%prime)%prime;
    valueHash2 = (valueHash2%prime + b2%prime)%prime;
    valueHash2 = valueHash2%filterSize;
    //cout << valueHash1 << " " << valueHash2 << endl;
    vector <int> indexos = vector <int> (2);
    indexos[0] = valueHash1;
    indexos[1] = valueHash2;
    return indexos;
}



void spectral_Bloom::insert (string key) {
    vector <int> representation = transformStringToInt(key);
    //cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre insert " << index << endl;
        ++filter[index];
    }

}

bool spectral_Bloom::contains(string key) {
    vector <int> representation = transformStringToInt(key);
    //cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre contains " << index << endl;
        if (filter[index] == 0) return false;
    }
    return true;

}

void spectral_Bloom::remove(string key)
{
    vector <int> representation = transformStringToInt(key);
    //cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre contains " << index << endl;
        if (filter[index] > 0) --filter[index];
    }
}


int spectral_Bloom::num_occurs(string key)
{
    int smallest = INT_MAX;
    vector <int> representation = transformStringToInt(key);
    //cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre contains " << index << endl;
        if (filter[index] < smallest) smallest = filter[index];
    }
    return smallest;
}

