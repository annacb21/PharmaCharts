#include "valorivenditenorm.h"

ValoriVenditeNorm::ValoriVenditeNorm(const ValoriVendite& val, unsigned int m): venditaMax(m) {
    unsigned int tmpMax = val.max();
    for(int i=0; i<val.getSize(); ++i){
        unsigned int v = venditaMax*val[i]/tmpMax;
        venditeNorm.push_back(v);
    }
}

int ValoriVenditeNorm::getSize() const {
    return venditeNorm.size();
}

bool ValoriVenditeNorm::isEmpty() const {
    return venditeNorm.empty();
}

unsigned int& ValoriVenditeNorm::operator[](int i) const {
    std::vector<unsigned int>::const_iterator cit = venditeNorm.begin()+i;
    return const_cast<unsigned int&>(*cit);
}

unsigned int ValoriVenditeNorm::maxSelling() const {
    return venditaMax;
}
