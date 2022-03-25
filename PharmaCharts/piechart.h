#ifndef PIECHART_H
#define PIECHART_H

#include "chart.h"
#include <QPieSeries>
#include <QPieSlice>

class PieChart : public Chart {
private:
    QPieSeries* series;
public:
    PieChart(std::string t, const Variabili& var, const Valori& val);
    std::string getChartType() const;
    QChart* createChart() const;
    /* Metodi getter*/
    QPieSeries& getSeries() const;
};

#endif // PIECHART_H

/* La classe PieChart rappresenta un pie chart, ovvero un grafico a torta.
 * Ogni piechart è caratterizzato dalla serie contenente i valori normalizzati e le variabili
*/
