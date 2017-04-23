#include <vector>
using namespace std;


class couting_Bloom {

private:
    vector <int> filter;
    int filterSize;
    int hashFunctionsNum;
    int maxNumKeys;
    vector <int> primes;
    int a1,a2,b1,b2;
    int prime;

public:

    couting_Bloom (int size, int numHash);
    vector <int> transformStringToInt(string key);
    void insert(string key);
    bool contains(string key);
    void remove(string key);




};
