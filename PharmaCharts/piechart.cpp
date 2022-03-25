#include "piechart.h"

PieChart::PieChart(std::string t, const Variabili& var, const Valori& val): Chart(t,var,val) {
    series = new QPieSeries();
    if(dynamic_cast<const ValoriPrezzo*>(&val)) {
        const ValoriPrezzo& prezzi = dynamic_cast<const ValoriPrezzo&>(val);
        ValoriPrezziNorm prezziNorm(prezzi,prezzi.max());
        if(dynamic_cast<const VariabiliAnno*>(&var)) {
            const VariabiliAnno& varAnni = dynamic_cast<const VariabiliAnno&>(var);
            for(int i=0; i<prezziNorm.getSize(); ++i) {
                series->append(QString::fromStdString(varAnni[i]),prezziNorm[i]);
            }
        }
        if(dynamic_cast<const VariabiliNome*>(&var)) {
            const VariabiliNome& varNomi = dynamic_cast<const VariabiliNome&>(var);
            for(int i=0; i<prezziNorm.getSize(); ++i) {
                series->append(QString::fromStdString(varNomi[i]),prezziNorm[i]);
            }
        }
    }
    if(dynamic_cast<const ValoriVenditeAnno*>(&val)) {
        const ValoriVenditeAnno& venditeAnno = dynamic_cast<const ValoriVenditeAnno&>(val);
        ValoriVenditeNorm venditeNorm(venditeAnno,venditeAnno.max());
        if(dynamic_cast<const VariabiliAnno*>(&var)) {
            const VariabiliAnno& varAnni = dynamic_cast<const VariabiliAnno&>(var);
            for(int i=0; i<venditeNorm.getSize(); ++i) {
                series->append(QString::fromStdString(varAnni[i]),venditeNorm[i]);
            }
        }
        if(dynamic_cast<const VariabiliNome*>(&var)) {
            const VariabiliNome& varNomi = dynamic_cast<const VariabiliNome&>(var);
            for(int i=0; i<venditeNorm.getSize(); ++i) {
                series->append(QString::fromStdString(varNomi[i]),venditeNorm[i]);
            }
        }
    }
    if(dynamic_cast<const ValoriVenditeItem*>(&val)) {
        const ValoriVenditeItem& venditeItem = dynamic_cast<const ValoriVenditeItem&>(val);
        ValoriVenditeNorm venditeNorm(venditeItem,venditeItem.max());
        if(dynamic_cast<const VariabiliAnno*>(&var)) {
            const VariabiliAnno& varAnni = dynamic_cast<const VariabiliAnno&>(var);
            for(int i=0; i<venditeNorm.getSize(); ++i) {
                series->append(QString::fromStdString(varAnni[i]),venditeNorm[i]);
            }
        }
        if(dynamic_cast<const VariabiliNome*>(&var)) {
            const VariabiliNome& varNomi = dynamic_cast<const VariabiliNome&>(var);
            for(int i=0; i<venditeNorm.getSize(); ++i) {
                series->append(QString::fromStdString(varNomi[i]),venditeNorm[i]);
            }
        }
    }
}

std::string PieChart::getChartType() const{
    return "PieChart";
}

QPieSeries& PieChart::getSeries() const {
    return *series;
}

QChart* PieChart::createChart() const {
    QChart* chart = new QChart();
    series->setLabelsVisible(true);
    chart->addSeries(series);
    chart->setTitle(QString::fromStdString(getTitle()));
    chart->setTitleFont(QFont("Roboto", 18, QFont::Bold));
    chart->setAnimationOptions(QChart::AllAnimations);
    return chart;
}
