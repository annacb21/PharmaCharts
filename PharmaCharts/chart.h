#ifndef CHART_H
#define CHART_H

#include <QChart>
#include "variabilianno.h"
#include "variabilinome.h"
#include "valoriprezzo.h"
#include "valorivenditeanno.h"
#include "valorivenditeitem.h"
#include "valoriprezzinorm.h"
#include "valorivenditenorm.h"

QT_CHARTS_USE_NAMESPACE

class Chart {
private:
    std::string titolo;
    Variabili* var;
    Valori* val;
public:
    Chart(std::string t, const Variabili& var, const Valori& val);
    virtual ~Chart();
    /**
    * @brief Ritorna il tipo di chart
    * @return stringa che rappresenta il tipo di chart
    */
    virtual std::string getChartType() const =0;
    /**
    * @brief Crea un chart a partire dai dati e dalle variabili date, e con il titolo dato
    * @return QChart da inserire in una QChartView
    */
    virtual QChart* createChart() const =0;
    /* Metodi getter */
    std::string getTitle() const;
    Valori* getValues() const;
    Variabili* getVariables() const;
};

#endif // CHART_H

/*
 * La classe Chart è una classe base polimorfa astratta che rappresenta un generico grafico (chart).
 * Ogni Chart è caratterizzato da un titolo, dalle sue variabili e dai suoi valori.
* La classe definisce due metodi virtuali puri:
 * -std::string getChartType(), che ritorna il tipo di grafico
 * -QChart& createChart(), che crea un chart tramite la classe QChart
*/
