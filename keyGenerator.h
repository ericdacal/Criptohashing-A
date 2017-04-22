#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class keyGenerator {

private:
	int numKeys;
	int keysSize;
	vector <string> keysGenerated;


public:
	keyGenerator (int numKeys, int keysSize);
	vector <string> generateKeys();



};
