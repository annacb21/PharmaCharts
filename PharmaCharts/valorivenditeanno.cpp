#include "valorivenditeanno.h"

ValoriVenditeAnno::ValoriVenditeAnno(const Dataset& d, unsigned int a): anno(a) {
    for(int i=0; i<d.getSize(); ++i){
        unsigned int v = d[i]->getSellingPerYear(a);
        vendite.push_back(v);
    }
}

unsigned int ValoriVenditeAnno::getAnno() const {
    return anno;
}
