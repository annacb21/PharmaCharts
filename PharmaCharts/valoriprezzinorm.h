#ifndef VALORIPREZZINORM_H
#define VALORIPREZZINORM_H

#include "valorinorm.h"
#include "valoriprezzo.h"

class ValoriPrezziNorm : public ValoriNorm {
private:
    std::vector<double> prezziNorm;
    double prezzoMax;
public:
    ValoriPrezziNorm(const ValoriPrezzo& val, double m =150);
    int getSize() const;
    bool isEmpty() const;
    double& operator[](int i) const;
    double maxPrice() const;
};

#endif // VALORIPREZZINORM_H
