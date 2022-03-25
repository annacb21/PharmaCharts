#include "variabili.h"

int Variabili::getSize() const {
    return variabili.size();
}

bool Variabili::isEmpty() const {
    return variabili.empty();
}

std::string& Variabili::operator[](int i) const {
    std::vector<std::string>::const_iterator cit = variabili.begin()+i;
    return const_cast<std::string&>(*cit);
}
