#include "compresse.h"

Compresse::Compresse(std::string n, std::string m, std::vector<unsigned int> v, unsigned int c, double p) : Farmaco(n,m,v), comp(c), prezzoComp(p) {}

double Compresse::calculatePrice() const {
    return prezzoComp * comp;
}

std::string Compresse::getType() const {
    return "Compresse";
}

Compresse* Compresse::clone() const {
    return new Compresse(*this);
}

unsigned int Compresse::getComp() const {
    return comp;
}

double Compresse::getPriceComp() const {
    return prezzoComp;
}

void Compresse::setComp(unsigned int c) {
    comp = c;
}

void Compresse::setPriceComp(double p) {
    prezzoComp = p;
}

bool Compresse::operator==(const Farmaco& f) const {
    if(dynamic_cast<const Compresse*>(&f)){
        const Compresse& c = dynamic_cast<const Compresse&>(f);
        return getName()==c.getName() && getBrand()==c.getBrand() && getComp()==c.getComp() && getPriceComp()==c.getPriceComp();
    }
    return false;
}

bool Compresse::operator!=(const Farmaco& f) const {
    if(dynamic_cast<const Compresse*>(&f)){
        const Compresse& c = dynamic_cast<const Compresse&>(f);
        return !(getName()==c.getName() && getBrand()==c.getBrand() && getComp()==c.getComp() && getPriceComp()==c.getPriceComp());
    }
    return true;
}

