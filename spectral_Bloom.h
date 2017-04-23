#include <vector>
using namespace std;


class spectral_Bloom {

private:
    vector <int> filter;
    int filterSize;
    int hashFunctionsNum;
    int maxNumKeys;
    vector <int> primes;
    int a1,a2,b1,b2;
    int prime;

public:

    spectral_Bloom (int size, int numHash, int maxKeys);
    void insert(string key);
    bool contains(string key);
    void createTwoHashFunctions();
    void remove(string key);
    int num_occurs(string item);
    vector <int> transformStringToInt(string key);



};
