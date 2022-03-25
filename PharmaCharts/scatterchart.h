#ifndef SCATTERCHART_H
#define SCATTERCHART_H

#include "pointchart.h"
#include <QScatterSeries>
#include <QCategoryAxis>

class ScatterChart : public PointChart {
private:
    QScatterSeries* series;
public:
    ScatterChart(std::string t, const Variabili& var, const Valori& val);
    QChart* createChart() const;
    std::string getChartType() const;
    /* metodi getter */
    QScatterSeries& getSeries() const;
};

#endif // SCATTERCHART_H

/* La classe ScatterChart rappresenta un grafico a punti,
 * ed è caratterizzato dalla serie contenente i dati e le variabili (punti)
 */
