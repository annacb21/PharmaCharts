#include "valoriprezzinorm.h"

ValoriPrezziNorm::ValoriPrezziNorm(const ValoriPrezzo& val, double m): prezzoMax(m) {
    double tmpMax = val.max();
    for(int i=0; i<val.getSize(); ++i){
        double p = prezzoMax*val[i]/tmpMax;
        prezziNorm.push_back(p);
    }
}

int ValoriPrezziNorm::getSize() const {
    return prezziNorm.size();
}

bool ValoriPrezziNorm::isEmpty() const {
    return prezziNorm.empty();
}

double& ValoriPrezziNorm::operator[](int i) const {
    std::vector<double>::const_iterator cit = prezziNorm.begin()+i;
    return const_cast<double&>(*cit);
}

double ValoriPrezziNorm::maxPrice() const {
    return prezzoMax;
}
