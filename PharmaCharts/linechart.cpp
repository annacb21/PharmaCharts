#include "linechart.h"

LineChart::LineChart(std::string t, const Variabili& var, const Valori& val): PointChart(t,var,val) {
    series = new QLineSeries();
    for(auto it=punti.begin(); it!=punti.end(); ++it) {
        series->append(*it);
    }
    scatterSeries = new QScatterSeries();
    for(auto it=punti.begin(); it!=punti.end(); ++it) {
        scatterSeries->append(*it);
    }
    if(dynamic_cast<const ValoriPrezzo*>(&val)) {
        series->setName("Prezzo totale");
    }
    if(dynamic_cast<const ValoriVenditeAnno*>(&val)) {
        const ValoriVenditeAnno& venditeAnno = dynamic_cast<const ValoriVenditeAnno&>(val);
        if(venditeAnno.getAnno() == 2018)
            series->setName("Vendite nel 2018");
        if(venditeAnno.getAnno() == 2019)
            series->setName("Vendite nel 2019");
        if(venditeAnno.getAnno() == 2020)
            series->setName("Vendite nel 2020");
        if(venditeAnno.getAnno() == 2021)
            series->setName("Vendite nel 2021");
    }
    if(dynamic_cast<const ValoriVenditeItem*>(&val)) {
        series->setName("Vendite dal 2018 al 2021");
    }
}

std::string LineChart::getChartType() const {
    return "LineChart";
}

QLineSeries& LineChart::getSeries() const {
    return *series;
}

QChart* LineChart::createChart() const {
    QChart* chart = new QChart();
    scatterSeries->setMarkerSize(10);
    series->setPen(QPen(QColor(0, 160, 229), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scatterSeries->setPen(QPen(QColor(0, 160, 229), 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    scatterSeries->setBrush(QBrush(Qt::white));
    chart->addSeries(series);
    chart->addSeries(scatterSeries);
    chart->setTitle(QString::fromStdString(getTitle()));
    chart->setTitleFont(QFont("Roboto", 18, QFont::Bold));
    chart->setAnimationOptions(QChart::AllAnimations);
    QValueAxis* axisX = new QValueAxis();
    QValueAxis* axisY = new QValueAxis();
    axisX->setLabelFormat("%d");
    axisX->setTickCount(getVariables()->getSize());
    axisY->setLabelFormat("%.2f");
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);
    return chart;
}
