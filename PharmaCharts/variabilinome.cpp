#include "variabilinome.h"

VariabiliNome::VariabiliNome(const Dataset& d){
    for(int i=0; i<d.getSize(); i++) {
        std::string n = d[i]->getName();
        variabili.push_back(n);
    }
}
