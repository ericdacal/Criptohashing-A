#include <iostream>
#include <vector>
#include <string>
using namespace std;



class basic_Bloom {

private:
    vector <bool> filter;
    int filterSize;
    int hashFunctionsNum;
    int maxNumKeys;
    vector <int> primes;
    int a1,a2,b1,b2;
    int prime;

public:

    basic_Bloom (int size, int numHash, int maxKeys);
    void insert(string key);
    bool contains(string key);
    void createTwoHashFunctions();
    vector <int> transformStringToInt(string key);



};
