#ifndef COMPRESSE_H
#define COMPRESSE_H

#include "farmaco.h"

class Compresse : public Farmaco {
private:
    unsigned int comp;
    double prezzoComp;
public:
    Compresse(std::string n, std::string m, std::vector<unsigned int> v, unsigned int c, double p);
    double calculatePrice() const;
    std::string getType() const;
    Compresse* clone() const;
    bool operator==(const Farmaco& f) const;
    bool operator!=(const Farmaco& f) const;
    /* Metodi getter */
    unsigned int getComp() const;
    double getPriceComp() const;
    /* Metodi setter */
    void setComp(unsigned int c);
    void setPriceComp(double p);
};

#endif // COMPRESSE_H

/*
 * La classe Compresse rappresenta un farmaco in confezione di compresse.
 * Ogni confezione è caratterizzata dal numero di compresse e da un prezzo per compressa.
 * Il prezzo finale è dato dalla moltiplicazione del prezzo a compressa per il numero di compresse totale della confezione
*/
