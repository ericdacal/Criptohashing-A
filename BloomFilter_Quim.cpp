#include "BloomFilter.h"
#include <cstdlib>
#include <math.h>



BloomFilter::BloomFilter(int size, int numHash, int numKeys) {

    filter = vector <bool> (size);
    filterSize = size;
    hashFunctionsNum = numHash;
    keysNum = numKeys;
    createTwoHashFunctions();
}

vector <int> erastosthenesSieve(int keysNum) {

    vector <bool> isPrime = vector <bool> (2*keysNum,true);
    vector <int> primes = vector <int> ();
    vector <int> smallPrimeFactor = vector <int> (2*keysNum);

    isPrime[0] = isPrime[1] = false;

    for (int i = 2;i < 2*keysNum;++i) {
        if (isPrime[i]) {
            primes.push_back(i);
            smallPrimeFactor[i] = i;
        }
        for (int j = 0;j < primes.size() and primes[j] <= smallPrimeFactor[i] and i*primes[j] < 2*keysNum;++j) {
                isPrime[i*primes[j]] = false;
                smallPrimeFactor[i*primes[j]] = primes[j];
        }

    }
    return primes;
}


void BloomFilter::createTwoHashFunctions() {
    vector <int> aux = erastosthenesSieve(keysNum);
    for (int i = 0;i < aux.size();++i) {
        if (aux[i] > keysNum) primes.push_back(aux[i]);
    }

    prime = primes[rand()%primes.size()];
    a1 = (rand()%prime) + 1;
    b1 = rand()%prime;
    a2 = (rand()%prime) + 1;
    b2 = rand()%prime;
    while (a1 == a2) a2 = rand()%prime + 1;
    while (b1 == b2) b2 = rand()%prime;

}

long long transformStringToInt(const string& key) {

    long long value = 0;
    for (int i = 0;i < key.size();i++) {
        value = (value*128) + (int)key[i];
    }
    return value;
}

int BloomFilter::hash1(long long value) {


	int index = (a1*value + b1)%prime;
	index = index%filterSize;
	return index;
}

int BloomFilter::hash2(long long value) {


	int index = (a2*value + b2)%prime;
	index = index%filterSize;
	return index;
}

void BloomFilter::addKey (const string& key) {

    long long representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
    	int indexH1 = hash1(representation);
    	int indexH2 = hash2(representation);
        int index = (indexH1 + (i*indexH2))%filterSize;
        filter[index] = true;
    }

}

bool BloomFilter::queryKey(const string& key) {
    long long representation = transformStringToInt(key);
    for (int i = 0;i < hashFunctionsNum;++i) {
    	int indexH1 = hash1(representation);
    	int indexH2 = hash2(representation);
        int index = (indexH1 + (i*indexH2))%filterSize;
        if (filter[index] == false) return false;


    }
    return true;

}

