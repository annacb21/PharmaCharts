#ifndef VALORI_H
#define VALORI_H

#include "dataset.h"

class Valori {
public:
    virtual ~Valori() =default;
    virtual int getSize() const =0;
    virtual bool isEmpty() const =0;
};

#endif // VALORI_H

/*
* La classe Valori serve a rappresentare i valori grezzi contenuti nella classe Dataset.
* Valori è una classe base astratta, da cui derivano le classi dei valori specifici da considerare
* per i grafici (prezzi, vendite in uno specifico anno)
*/
