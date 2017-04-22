#include <iostream>
#include <vector>
#include <string>

class basic_Bloom{
protected:
    std::vector<bool> Bloom_filter; 
    int num_hash_functions;
public:
    basic_Bloom(int num_hash, int Bloom_size);
    int hash(std::string key);
    void insert(std::string key);
    bool contains(std::string key);
};
