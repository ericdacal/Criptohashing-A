#include "keyGenerator.h"



keyGenerator::keyGenerator (int numKeys, int keysSize) {

	this->numKeys = numKeys;
	this-> keysSize = keysSize;
	keysGenerated = vector <string> (numKeys);

}

void keyGenerator::generateKeys() {
	srand(time(NULL));
	for (int i = 0;i < numKeys;++i) {
		string key;
		for (int j = 0;j < keysSize;++j) {
			int value = rand()%128;
			while (value == 127) value = rand()%128;
			if (value < 33) value = value + 33;
			//cout << value << endl;
			char letter = (char)value;
			//cout << letter << endl;
			key.push_back(letter);
		}
		keysGenerated[i] = key;
	}
	ofstream fitxer;
        fitxer.open("claus.txt",ios::app);
        for (int i = 0; i < numKeys;++i) {
            fitxer << keysGenerated[i] << "\n";
        }
        fitxer.close();
}
