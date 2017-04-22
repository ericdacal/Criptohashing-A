#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class keyGenerator {

private:
	int numKeys;
	int keysSize;
	vector <string> keysGenerated;


public:
	keyGenerator (int numKeys, int keysSize);
	void generateKeys();



};
