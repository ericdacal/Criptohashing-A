#include <iostream>
#include <vector>
#include <string>
using namespace std;



class basic_Bloom {

private:
    vector <bool> filter;
    int filterSize;
    int hashFunctionsNum;
    

public:

    basic_Bloom (int size, int numHash);
    void insert(string key);
    bool contains(string key);
    vector <int> transformStringToInt(string key);



};
