#include "pointchart.h"

PointChart::PointChart(std::string t, const Variabili& var, const Valori& val): Chart(t,var,val) {
    if(dynamic_cast<const ValoriPrezzo*>(&val)) {
        const ValoriPrezzo& prezzi = dynamic_cast<const ValoriPrezzo&>(val);
        ValoriPrezziNorm prezziNorm(prezzi,prezzi.max());
        for(int i=0; i<prezziNorm.getSize(); ++i){
            QPointF punto(i+1, prezziNorm[i]);
            punti.push_back(punto);
        }
    }
    if(dynamic_cast<const ValoriVenditeAnno*>(&val)) {
        const ValoriVenditeAnno& venditeAnno = dynamic_cast<const ValoriVenditeAnno&>(val);
        ValoriVenditeNorm venditeNorm(venditeAnno,venditeAnno.max());
        for(int i=0; i<venditeNorm.getSize(); ++i){
            QPointF punto(i+1, venditeNorm[i]);
            punti.push_back(punto);
        }
    }
    if(dynamic_cast<const ValoriVenditeItem*>(&val)) {
        const ValoriVenditeItem& venditeItem = dynamic_cast<const ValoriVenditeItem&>(val);
        ValoriVenditeNorm venditeNorm(venditeItem,venditeItem.max());
        for(int i=0; i<venditeNorm.getSize(); ++i){
            QPointF punto(i+1, venditeNorm[i]);
            punti.push_back(punto);
        }
    }
}

QPointF& PointChart::operator [](int i) const {
    std::vector<QPointF>::const_iterator cit = punti.begin()+i;
    return const_cast<QPointF&>(*cit);
}
