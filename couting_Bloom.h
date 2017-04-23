#include <vector>
#include <set>
using namespace std;


class couting_Bloom {

private:
    vector <int> filter;
    int filterSize;
    int hashFunctionsNum;

public:

    couting_Bloom (int size, int numHash);
    vector <int> transformStringToInt(string key);
    void insert(string key);
    bool contains(string key);
    void remove(string key);
    int falseNeg(set<string> keys, vector<string>& erases);




};
