#ifndef FLACONE_H
#define FLACONE_H

#include "farmaco.h"

class Flacone : public Farmaco {
private:
    double ml;
    double prezzoMl;
public:
    Flacone(std::string n, std::string m, std::vector<unsigned int> v, double ml, double p);
    double calculatePrice() const;
    std::string getType() const;
    Flacone* clone() const;
    bool operator==(const Farmaco& f) const;
    bool operator!=(const Farmaco& f) const;
    /* Metodi getter */
    double getMl() const;
    double getPriceMl() const;
    /* Metodi setter */
    void setMl(double m);
    void setPriceMl(double p);
};

#endif // FLACONE_H

/*
 * La classe Flacone rappresenta un farmaco venduto in formato flacone.
 * Ogni flacone è caratterizzato dalla quantità di ml e da un prezzo al ml.
 * Il prezzo finale di un flacone è dato dalla moltiplicazione degli ml totali per il prezzo al ml
*/
