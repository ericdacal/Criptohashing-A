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
    int maxNumKeys;
    vector <int> primes;
    int a1,a2,b1,b2;
    int prime;

public:

    BloomFilter (int size, int numHash, int numKeys, int maxKeys);
    void addKey(const string& key);
    bool queryKey(const string& key);
    void createTwoHashFunctions();
    vector <int> transformStringToInt(const string& key);



};
