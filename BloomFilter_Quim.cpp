#include "BloomFilter_Quim.h"
#include <cstdlib>
#include <math.h>
#include <vector>


BloomFilter::BloomFilter(int size, int numHash, int numKeys, int maxKeys) {

    filter = vector <bool> (size);
    filterSize = size;
    hashFunctionsNum = numHash;
    keysNum = numKeys;
    maxNumKeys = maxKeys;
    createTwoHashFunctions();
}

vector <int> erastosthenesSieve(int maxNumKeys) {

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


void BloomFilter::createTwoHashFunctions() {
    vector <int> aux = erastosthenesSieve(maxNumKeys);
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

vector <int> BloomFilter::transformStringToInt(const string& key) {

    int valueHash1 = 0;
    int valueHash2 = 0;
    for (int i = 0;i < key.size();i++) {
        valueHash1 = ((valueHash1*128)%prime + (int)key[i]%prime)%prime;
        valueHash2 = ((valueHash2*128)%prime + (int)key[i]%prime)%prime;
    }
    valueHash1 = (valueHash1 * a1%prime)%prime;
    valueHash1 = (valueHash1%prime + b1%prime)%prime;
    valueHash1 = valueHash1%filterSize;

    valueHash2 = (valueHash2 * a2%prime)%prime;
    valueHash2 = (valueHash2%prime + b2%prime)%prime;
    valueHash2 = valueHash2%filterSize;

    vector <int> indexos = vector <int> (2);
    indexos[0] = valueHash1;
    indexos[1] = valueHash2;
    return indexos;
}



void BloomFilter::addKey (const string& key) {
	vector <int> representation = transformStringToInt(key);
	//cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre " << index << endl;
        filter[index] = true;
    }

}

bool BloomFilter::queryKey(const string& key) {

	vector <int> representation = transformStringToInt(key);
	//cout << representation[0] << " " << representation[1];
    for (int i = 0;i < hashFunctionsNum;++i) {
        int index = (representation[0] + (i*representation[1]))%filterSize;
        //cout << "Index filtre " << index << endl;
        if (filter[index] == false) return false;


    }
    return true;

}

