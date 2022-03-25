#ifndef LINECHART_H
#define LINECHART_H

#include "pointchart.h"
#include <QLineSeries>
#include <QScatterSeries>

class LineChart : public PointChart {
private:
    QLineSeries* series;
    QScatterSeries* scatterSeries;
public:
    LineChart(std::string t, const Variabili& var, const Valori& val);
    QChart* createChart() const;
    std::string getChartType() const;
    /* metodi getter */
    QLineSeries& getSeries() const;
};

#endif // LINECHART_H

/* La classe LineChart rappresenta un grafico a linea,
 * ed è caratterizzato dalla serie contenente i dati e le variabili (punti)
 */
