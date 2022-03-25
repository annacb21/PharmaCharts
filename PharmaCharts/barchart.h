#ifndef BARCHART_H
#define BARCHART_H

#include "chart.h"
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>

class BarChart : public Chart {
private:
    QBarSeries* series;
    QStringList cat;
    QBarSet* set;
public:
    BarChart(std::string t, const Variabili& var, const Valori& val);
    std::string getChartType() const;
    QChart* createChart() const;
    /* Metodi getter*/
    QBarSeries& getSeries() const;
    QBarSet& getSet() const;
    QStringList getCat() const;
};

#endif // BARCHART_H

/* La classe BarChart rappresenta un bar chart, ovvero un grafico a barre.
 * Ogni barchart è caratterizzato dalla serie contenente i valori normalizzati
 * e dalle categorie in cui sono suddivise la barre, ovvero le variabili
*/
