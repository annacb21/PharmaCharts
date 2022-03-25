#include "valorivendite.h"

int ValoriVendite::getSize() const {
    return vendite.size();
}

bool ValoriVendite::isEmpty() const {
    return vendite.empty();
}

unsigned int& ValoriVendite::operator[](int i) const {
    std::vector<unsigned int>::const_iterator cit = vendite.begin()+i;
    return const_cast<unsigned int&>(*cit);
}

unsigned int ValoriVendite::max() const {
    std::vector<unsigned int>::const_iterator cit = vendite.begin();
    unsigned int max = *cit;
    ++cit;
    for(; cit!=vendite.end(); ++cit)
        if((*cit) > max)
            max = (*cit);
    return max;
}

