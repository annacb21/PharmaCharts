#ifndef VALORIVENDITE_H
#define VALORIVENDITE_H

#include "valori.h"

class ValoriVendite : public Valori {
protected:
    std::vector<unsigned int> vendite;
public:
    int getSize() const;
    bool isEmpty() const;
    unsigned int& operator[](int i) const;
    /**
     * @brief calcola il valore massimo di vendite dei farmaci del dataset
     * @return valore massimo del vettore delle vendite
     */
    unsigned int max() const;
};

#endif // VALORIVENDITE_H

/*
* La classe ValoriVendite è una classe virtuale che serve a rappresentare i valori grezzi delle vendite
*/
