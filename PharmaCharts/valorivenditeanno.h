#ifndef VALORIVENDITEANNO_H
#define VALORIVENDITEANNO_H

#include "valorivendite.h"

class ValoriVenditeAnno : public ValoriVendite {
private:
    unsigned int anno;
public:
    ValoriVenditeAnno(const Dataset& d, unsigned int a);
    unsigned int getAnno() const;
};

#endif // VALORIVENDITEANNO_H
