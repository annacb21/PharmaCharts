#ifndef VALORIVENDITEITEM_H
#define VALORIVENDITEITEM_H

#include "valorivendite.h"

class ValoriVenditeItem : public ValoriVendite {
private:
    int index;
public:
    ValoriVenditeItem(const Dataset& d, int i);
    int getIndex() const;
};

#endif // VALORIVENDITEITEM_H
