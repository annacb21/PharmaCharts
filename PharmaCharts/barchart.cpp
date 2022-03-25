#include "barchart.h"

BarChart::BarChart(std::string t, const Variabili& var, const Valori& val): Chart(t,var,val) {
    if(dynamic_cast<const ValoriPrezzo*>(&val)) {
        set = new QBarSet("Prezzo totale");
        const ValoriPrezzo& prezzi = dynamic_cast<const ValoriPrezzo&>(val);
        ValoriPrezziNorm prezziNorm(prezzi,prezzi.max());
        for(int i=0; i<prezziNorm.getSize(); ++i) {
            set->append(prezziNorm[i]);
        }
    }
    if(dynamic_cast<const ValoriVenditeAnno*>(&val)) {
        const ValoriVenditeAnno& venditeAnno = dynamic_cast<const ValoriVenditeAnno&>(val);
        if(venditeAnno.getAnno() == 2018)
            set = new QBarSet("Vendite nel 2018");
        if(venditeAnno.getAnno() == 2019)
            set = new QBarSet("Vendite nel 2019");
        if(venditeAnno.getAnno() == 2020)
            set = new QBarSet("Vendite nel 2020");
        if(venditeAnno.getAnno() == 2021)
            set = new QBarSet("Vendite nel 2021");
        ValoriVenditeNorm venditeNorm(venditeAnno,venditeAnno.max());
        for(int i=0; i<venditeNorm.getSize(); ++i) {
            set->append(venditeNorm[i]);
        }
    }
    if(dynamic_cast<const ValoriVenditeItem*>(&val)) {
        set = new QBarSet("Vendite dal 2018 al 2021");
        const ValoriVenditeItem& venditeItem = dynamic_cast<const ValoriVenditeItem&>(val);
        ValoriVenditeNorm venditeNorm(venditeItem,venditeItem.max());
        for(int i=0; i<venditeNorm.getSize(); ++i) {
            set->append(venditeNorm[i]);
        }
    }
    series = new QBarSeries();
    series->append(set);
    if(dynamic_cast<const VariabiliAnno*>(&var)) {
        const VariabiliAnno& varAnni = dynamic_cast<const VariabiliAnno&>(var);
        for(int i=0; i<varAnni.getSize(); ++i) {
            cat.append(QString::fromStdString(varAnni[i]));
        }
    }
    if(dynamic_cast<const VariabiliNome*>(&var)) {
        const VariabiliNome& varNomi = dynamic_cast<const VariabiliNome&>(var);
        for(int i=0; i<varNomi.getSize(); ++i) {
            cat.append(QString::fromStdString(varNomi[i]));
        }
    }
}

std::string BarChart::getChartType() const{
    return "BarChart";
}

QBarSeries& BarChart::getSeries() const {
    return *series;
}

QBarSet& BarChart::getSet() const {
    return *set;
}

QStringList BarChart::getCat() const {
    return cat;
}

QChart* BarChart::createChart() const {
    QChart* chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(QString::fromStdString(getTitle()));
    chart->setTitleFont(QFont("Roboto", 18, QFont::Bold));
    chart->setAnimationOptions(QChart::AllAnimations);
    QBarCategoryAxis* axisX = new QBarCategoryAxis();
    axisX->append(cat);
    QValueAxis* axisY = new QValueAxis();
    axisY->setLabelFormat("%.2f");
    chart->setAxisY(axisY, series);
    chart->setAxisX(axisX, series);
    return chart;
}
