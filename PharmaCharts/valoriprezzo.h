#ifndef VALORIPREZZO_H
#define VALORIPREZZO_H

#include "valori.h"

class ValoriPrezzo : public Valori {
private:
    std::vector<double> prezzi;
public:
    ValoriPrezzo(const Dataset& d);
    int getSize() const;
    bool isEmpty() const;
    double& operator[](int i) const;
    /**
     * @brief calcola il valore massimo di prezzo dei farmaci del dataset
     * @return valore massimo del vettore dei prezzi
     */
    double max() const;
};

#endif // VALORIPREZZO_H

/*
* La classe ValoriPrezzo serve a rappresentare i valori grezzi dei prezzi dei farmaci contenuti nel dataset.
*/
