#include "flacone.h"

Flacone::Flacone(std::string n, std::string m, std::vector<unsigned int> v, double ml, double p): Farmaco(n,m,v), ml(ml), prezzoMl(p) {}

double Flacone::calculatePrice() const {
    return prezzoMl * ml;
}

std::string Flacone::getType() const {
    return "Flacone";
}

Flacone* Flacone::clone() const {
    return new Flacone(*this);
}

double Flacone::getMl() const {
    return ml;
}

double Flacone::getPriceMl() const {
    return prezzoMl;
}

void Flacone::setMl(double m) {
    ml = m;
}

void Flacone::setPriceMl(double p) {
    prezzoMl = p;
}

bool Flacone::operator==(const Farmaco& f) const {
    if(dynamic_cast<const Flacone*>(&f)){
        const Flacone& fl = dynamic_cast<const Flacone&>(f);
        return getName()==fl.getName() && getBrand()==fl.getBrand() && getMl()==fl.getMl() && getPriceMl()==fl.getPriceMl();
    }
    return false;
}

bool Flacone::operator!=(const Farmaco& f) const {
    if(dynamic_cast<const Flacone*>(&f)){
        const Flacone& fl = dynamic_cast<const Flacone&>(f);
        return !(getName()==fl.getName() && getBrand()==fl.getBrand() && getMl()==fl.getMl() && getPriceMl()==fl.getPriceMl());
    }
    return true;
}
