#include <iostream>
#include <vector>
#include <string>
#include "couting_Bloom.h"

couting_Bloom::couting_Bloom(int num_hash, int Bloom_size) : basic_Bloom(num_hash, Bloom_size){
    Bloom_filter.resize(Bloom_size,0);
    num_hash_functions = num_hash;
}

void couting_Bloom::insert(std::string key) {
    int h = hash(key);
	++Bloom_filter[h];
}

void couting_Bloom::remove(std::string key) {
    int h = hash(key);
	--Bloom_filter[h];
}
