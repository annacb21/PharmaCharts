#ifndef POINTCHART_H
#define POINTCHART_H

#include "chart.h"
#include <QPointF>
#include <QValueAxis>

class PointChart : public Chart {
protected:
    std::vector<QPointF> punti;
public:
    PointChart(std::string t, const Variabili& var, const Valori& val);
    QPointF& operator [](int i) const;
};

#endif // POINTCHART_H

/* La classe PointChart è una classe virtuale che serve a rappresentare tipi di grafico che usano i punti.
 * Ogni pointchart è caratterizzato da un vettore contenente i punti (variabili e dati)
*/
