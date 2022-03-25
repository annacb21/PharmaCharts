#include "valorivenditeitem.h"

ValoriVenditeItem::ValoriVenditeItem(const Dataset& d, int i): index(i) {
    std::vector<unsigned int> aux = d[i]->getSellings();
    vendite = aux;
}

int ValoriVenditeItem::getIndex() const {
    return index;
}
