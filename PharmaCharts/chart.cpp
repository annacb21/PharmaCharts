#include "chart.h"

Chart::Chart(std::string t, const Variabili& var, const Valori& val): titolo(t), var(const_cast<Variabili*>(&var)), val(const_cast<Valori*>(&val)) {}

Chart::~Chart() {
    delete var;
    delete val;
}

std::string Chart::getTitle() const {
    return titolo;
}

Valori* Chart::getValues() const {
    return val;
}

Variabili* Chart::getVariables() const {
    return var;
}
