#include "maincontent.h"

MainContent::MainContent(QWidget* parent, InsertView* ins): QWidget(parent), insertView(ins) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    /* layout bottoni grafico */
    QHBoxLayout* chartBtnLayout = new QHBoxLayout();
    barBtn = new QPushButton(QIcon(":/images/barchart.png"), tr(""), this);
    barBtn->setIconSize(QSize(50,50));
    barBtn->setToolTip("Crea BarChart (grafico a barre)");
    pieBtn = new QPushButton(QIcon(":/images/piechart.png"), tr(""), this);
    pieBtn->setIconSize(QSize(50,50));
    pieBtn->setToolTip("Crea PieChart (grafico a torta)");
    lineBtn = new QPushButton(QIcon(":/images/linechart.png"), tr(""), this);
    lineBtn->setIconSize(QSize(50,50));
    lineBtn->setToolTip("Crea LineChart (grafico a linea)");
    scatterBtn = new QPushButton(QIcon(":/images/scatterchart.png"), tr(""), this);
    scatterBtn->setIconSize(QSize(50,50));
    scatterBtn->setToolTip("Crea ScatterChart (grafico a punti)");
    chartBtnLayout->addWidget(barBtn);
    chartBtnLayout->addWidget(pieBtn);
    chartBtnLayout->addWidget(lineBtn);
    chartBtnLayout->addWidget(scatterBtn);
    mainLayout->addLayout(chartBtnLayout);

    /* layout bottoni azioni sulla tabella */
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    removeBtn = new QPushButton(QIcon(":/images/remove.png"), tr("Rimuovi dato"), this);
    removeBtn->setToolTip("Rimuove la riga selezionata dalla tabella");
    addBtn = new QPushButton(QIcon(":/images/add.png"), tr("Aggiungi dato"), this);
    addBtn->setToolTip("Aggiunge un nuovo dato nella tabella");
    updateBtn = new QPushButton(QIcon(":/images/update.png"), tr("Aggiorna grafico"), this);
    updateBtn->setToolTip("Aggiorna il grafico con i nuovi dati");
    buttonsLayout->addWidget(removeBtn);
    buttonsLayout->addWidget(addBtn);
    buttonsLayout->addWidget(updateBtn);
    mainLayout->addLayout(buttonsLayout);

    proxy = new ProxyModelAdapter(this);
    adapter = new TableModelAdapter(this);
    tabella = new Tabella(this);

    mainLayout->addWidget(tabella,0);
    setLayout(mainLayout);

    connect(removeBtn, SIGNAL(clicked()), this, SIGNAL(Remove()));
    connect(addBtn, SIGNAL(clicked()), this, SIGNAL(Add()));
    connect(updateBtn, SIGNAL(clicked()), this, SIGNAL(Update()));
    connect(barBtn, SIGNAL(clicked()), this, SIGNAL(DrawBarChart()));
    connect(pieBtn, SIGNAL(clicked()), this, SIGNAL(DrawPieChart()));
    connect(lineBtn, SIGNAL(clicked()), this, SIGNAL(DrawLineChart()));
    connect(scatterBtn, SIGNAL(clicked()), this, SIGNAL(DrawScatterChart()));
}

InsertView* MainContent::getInsView() const {
    return insertView;
}

TableModelAdapter* MainContent::getAdapter() const {
    return adapter;
}

ProxyModelAdapter* MainContent::getProxy() const {
    return proxy;
}

Tabella* MainContent::getTable() const {
    return tabella;
}

QPushButton* MainContent::getRemoveBtn() const {
    return removeBtn;
}

QPushButton* MainContent::getAddBtn() const {
    return addBtn;
}

QPushButton* MainContent::getUpdateBtn() const {
    return updateBtn;
}

QPushButton* MainContent::getBarBtn() const {
    return barBtn;
}

QPushButton* MainContent::getPieBtn() const {
    return pieBtn;
}

QPushButton* MainContent::getLineBtn() const {
    return lineBtn;
}

QPushButton* MainContent::getScatterBtn() const {
    return scatterBtn;
}
