#include "valoriprezzo.h"

ValoriPrezzo::ValoriPrezzo(const Dataset& d) {
    for(int i=0; i<d.getSize(); ++i){
        double p = d[i]->calculatePrice();
        prezzi.push_back(p);
    }
}

int ValoriPrezzo::getSize() const {
    return prezzi.size();
}

bool ValoriPrezzo::isEmpty() const {
    return prezzi.empty();
}

double& ValoriPrezzo::operator[](int i) const {
    std::vector<double>::const_iterator cit = prezzi.begin()+i;
    return const_cast<double&>(*cit);
}

double ValoriPrezzo::max() const {
    std::vector<double>::const_iterator cit = prezzi.begin();
    double max = *cit;
    ++cit;
    for(; cit!=prezzi.end(); ++cit)
        if((*cit) > max)
            max = (*cit);
    return max;
}
