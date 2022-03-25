#ifndef VALORIVENDITENORM_H
#define VALORIVENDITENORM_H

#include "valorinorm.h"
#include "valorivenditeanno.h"
#include "valorivenditeitem.h"

class ValoriVenditeNorm : public ValoriNorm {
private:
    std::vector<unsigned int> venditeNorm;
    unsigned int venditaMax;
public:
    ValoriVenditeNorm(const ValoriVendite& val, unsigned int m =1000);
    int getSize() const;
    bool isEmpty() const;
    unsigned int& operator[](int i) const;
    unsigned int maxSelling() const;
};

#endif // VALORIVENDITENORM_H
