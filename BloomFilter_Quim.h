#include <iostream>
#include <vector>
#include <string>
using namespace std;



class BloomFilter {

private:
    vector <bool> filter;
    int filterSize;
    int hashFunctionsNum;
    int keysNum;
    vector <int> primes;
    int a1,a2,b1,b2;
    int prime;
    int hash1(long long value);
    int hash2(long long value);

public:

    BloomFilter (int size, int numHash, int numKeys);
    void addKey(const string& key);
    bool queryKey(const string& key);
    void createTwoHashFunctions();



};
