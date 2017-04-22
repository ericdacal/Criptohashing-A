#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include "spectral_Bloom.h"



spectral_Bloom::spectral_Bloom(int num_hash, int Bloom_size) : couting_Bloom(num_hash, Bloom_size){
    Bloom_filter.resize(Bloom_size,0);
    num_hash_functions = num_hash;
}

int spectral_Bloom::num_occurs(std::string item)
{
    int smallest = INT_MAX;
    for(int i = 0; i < Bloom_filter.size(); i++) {
        if(Bloom_filter[hash(item)] < smallest) smallest = Bloom_filter[hash(item)];
    }
    return smallest;
}

