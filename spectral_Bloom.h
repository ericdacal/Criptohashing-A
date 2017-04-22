#include "couting_Bloom.h"

class spectral_Bloom: public couting_Bloom {
private:
    std::vector<int> Bloom_filter; 
public:
     spectral_Bloom(int num_hash, int Bloom_size);
     int num_occurs(std::string item);
};
