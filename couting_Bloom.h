#include "basic_Bloom.h"

class couting_Bloom: public basic_Bloom {
private:
    std::vector<int> Bloom_filter; 
public:
     couting_Bloom(int num_hash, int Bloom_size);
     void insert(std::string key);
     void remove(std::string key);
};
