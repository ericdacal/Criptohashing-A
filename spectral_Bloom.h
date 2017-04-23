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

    spectral_Bloom (int size, int numHash);
    void insert(string key);
    bool contains(string key);
    vector <int> transformStringToInt(string key);
    void remove(string key);
    int num_occurs(string item);
   



};
