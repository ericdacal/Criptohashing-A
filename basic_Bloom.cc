#include "basic_Bloom.h"

basic_Bloom::basic_Bloom(int num_hash, int Bloom_size) {
    Bloom_filter.resize(Bloom_size,false);
    num_hash_functions = num_hash;
}

int basic_Bloom::hash(std::string key) {
    int val = 0;
	for (int i = 0; i < key.size(); ++i) {
		int aux = 0;
		if ('a' <= key[i] and key[i] <= 'z') {
			aux = key[i] - 'a';
		}
		else if ('A' <= key[i] and key[i] <= 'A') {
			aux = key[i] - 'A';
		}
		else aux = key[i] - '0';

		//mod arithmetic
		val = ((val % Bloom_filter.size()) + (aux % Bloom_filter.size())) % Bloom_filter.size() + num_hash_functions;
	}
	return (val < Bloom_filter.size()) ? val : val - Bloom_filter.size();
}


void basic_Bloom::insert(std::string key) {
    int h = hash(key);
	if(not Bloom_filter[h]) Bloom_filter[h] = true;
}

bool basic_Bloom::contains(std::string key) {
    int h = hash(key);
    if(Bloom_filter[h] == 0) return false;
    return true;
}
