#ifndef VARIABILI_H
#define VARIABILI_H

#include "dataset.h"

class Variabili {
protected:
    std::vector<std::string> variabili;
public:
    virtual ~Variabili() =default;
    int getSize() const;
    bool isEmpty() const;
    std::string& operator[](int i) const;
};

#endif // VARIABILI_H

/*
 * La classe Variabili è una classe base virtuale che prende i dati delle variabili dal dataset,
 * ovvero i nomi dei farmaci oppure gli anni considerati per le vendite
*/
