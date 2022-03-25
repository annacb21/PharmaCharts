#include "farmaco.h"

Farmaco::Farmaco(std::string n, std::string m, std::vector<unsigned int> v): nome(n), marca(m), vendite(v) {}

std::string Farmaco::getName() const {
    return nome;
}

std::string Farmaco::getBrand() const {
    return marca;
}

std::vector<unsigned int> Farmaco::getSellings() const {
    return vendite;
}

unsigned int Farmaco::getSellingPerYear(unsigned int y) const {
    if(y == 2018)
        return vendite[0];
    else if(y == 2019)
        return vendite[1];
    else if(y == 2020)
        return vendite[2];
    else if(y == 2021)
        return vendite[3];
    else
        throw std::invalid_argument("L'anno passato per parametro eccede la lunghezza del vettore delle vendite");
}

void Farmaco::setName(std::string n) {
    nome = n;
}

void Farmaco::setBrand(std::string m) {
    marca = m;
}

void Farmaco::setSelling(unsigned int v, unsigned int a) {
    if(a == 2018)
        vendite[0]=v;
    else if(a == 2019)
        vendite[1]=v;
    else if(a == 2020)
        vendite[2]=v;
    else if(a == 2021)
        vendite[3]=v;
    else
        throw std::invalid_argument("L'anno passato per parametro eccede la lunghezza del vettore delle vendite");
}

