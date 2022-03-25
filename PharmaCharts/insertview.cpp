#include "insertview.h"

InsertView::InsertView(QWidget *parent): QWidget(parent) {
    int row = 0;
    QGridLayout* gridLayout = new QGridLayout(this);

    QLabel* nameLabel = new QLabel("Nome farmaco *");
    nome = new QLineEdit();
    gridLayout->addWidget(nameLabel,row,0);
    gridLayout->addWidget(nome,row++,1);

    QLabel* brandLabel = new QLabel("Marca farmaco *");
    marca = new QLineEdit();
    gridLayout->addWidget(brandLabel,row,0);
    gridLayout->addWidget(marca,row++,1);

    QLabel* formatLabel = new QLabel("Formato");
    formato = new FormatComboBox();
    formato->setCurrentIndex(0);
    gridLayout->addWidget(formatLabel,row,0);
    gridLayout->addWidget(formato,row++,1);

    QLabel* mlLabel = new QLabel("Quantità in ml * - max. 1000");
    ml = new QDoubleSpinBox();
    ml->setLocale(QLocale::C);
    ml->setValue(0.0);
    ml->setMinimum(0.0);
    ml->setMaximum(1000.0);
    ml->setAccelerated(true);
    ml->setEnabled(true);
    gridLayout->addWidget(mlLabel,row,0);
    gridLayout->addWidget(ml,row++,1);

    QLabel* compLabel = new QLabel("Numero compresse * - max. 100");
    comp = new QSpinBox();
    comp->setValue(0);
    comp->setRange(0,100);
    comp->setAccelerated(true);
    comp->setEnabled(false);
    gridLayout->addWidget(compLabel,row,0);
    gridLayout->addWidget(comp,row++,1);

    QLabel* priceMlLabel = new QLabel("Prezzo al ml * - max. 10");
    prezzoMl = new QDoubleSpinBox();
    prezzoMl->setLocale(QLocale::C);
    prezzoMl->setValue(0.0);
    prezzoMl->setMinimum(0.0);
    prezzoMl->setMaximum(10.0);
    prezzoMl->setAccelerated(true);
    prezzoMl->setEnabled(true);
    gridLayout->addWidget(priceMlLabel,row,0);
    gridLayout->addWidget(prezzoMl,row++,1);

    QLabel* priceCompLabel = new QLabel("Prezzo a compressa * - max.10");
    prezzoComp = new QDoubleSpinBox();
    prezzoComp->setLocale(QLocale::C);
    prezzoComp->setValue(0.0);
    prezzoComp->setMinimum(0.0);
    prezzoComp->setMaximum(10.0);
    prezzoComp->setAccelerated(true);
    prezzoComp->setEnabled(false);
    gridLayout->addWidget(priceCompLabel,row,0);
    gridLayout->addWidget(prezzoComp,row++,1);

    QLabel* v18Label = new QLabel("Vendite 2018 - max. 60000");
    v18 = new QSpinBox();
    v18->setValue(0);
    v18->setRange(0,60000);
    v18->setAccelerated(true);
    gridLayout->addWidget(v18Label,row,0);
    gridLayout->addWidget(v18,row++,1);

    QLabel* v19Label = new QLabel("Vendite 2019 - max. 60000");
    v19 = new QSpinBox();
    v19->setValue(0);
    v19->setRange(0,60000);
    v19->setAccelerated(true);
    gridLayout->addWidget(v19Label,row,0);
    gridLayout->addWidget(v19,row++,1);

    QLabel* v20Label = new QLabel("Vendite 2020 - max. 60000");
    v20 = new QSpinBox();
    v20->setValue(0);
    v20->setRange(0,60000);
    v20->setAccelerated(true);
    gridLayout->addWidget(v20Label,row,0);
    gridLayout->addWidget(v20,row++,1);

    QLabel* v21Label = new QLabel("Vendite 2021 - max. 60000");
    v21 = new QSpinBox();
    v21->setValue(0);
    v21->setRange(0,60000);
    v21->setAccelerated(true);
    gridLayout->addWidget(v21Label,row,0);
    gridLayout->addWidget(v21,row++,1);

    /* layout bottoni*/
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    insertBtn = new QPushButton("Inserisci");
    insertBtn->setDefault(true);
    insertBtn->setAutoDefault(true);
    cancelBtn = new QPushButton("Annulla");
    buttonsLayout->addWidget(insertBtn);
    buttonsLayout->addWidget(cancelBtn);
    gridLayout->addLayout(buttonsLayout,row,0,1,3);

    setLayout(gridLayout);

    connect(cancelBtn, SIGNAL(clicked()), this, SIGNAL(Close())); //gestito in MainWindow
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(Reset()));
    connect(insertBtn, SIGNAL(clicked()), this, SIGNAL(Insert())); //gestito in MainWindow
    connect(formato, SIGNAL(currentIndexChanged(int)),this,SLOT(changeFormat(int)));
}

QLineEdit* InsertView::getName() const {
    return nome;
}

QLineEdit* InsertView::getBrand() const {
    return marca;
}

std::string InsertView::getFormat() const {
    return formato->currentText().toStdString();
}

bool InsertView::isFlacone() const {
    return formato->currentIndex()==0;
}

bool InsertView::isCompressa() const {
    return formato->currentIndex()==1;
}

double InsertView::getMl() const {
    return ml->value();
}

unsigned int InsertView::getComp() const {
    return comp->value();
}

double InsertView::getPriceMl() const {
    return prezzoMl->value();
}

double InsertView::getPriceComp() const {
    return prezzoComp->value();
}

unsigned int InsertView::getSell2018() const {
    return v18->value();
}

unsigned int InsertView::getSell2019() const {
    return v19->value();
}

unsigned int InsertView::getSell2020() const {
    return v20->value();
}

unsigned int InsertView::getSell2021() const {
    return v21->value();
}

QPushButton* InsertView::getInsertBtn() const {
    return insertBtn;
}

QPushButton* InsertView::getCancelBtn() const {
    return cancelBtn;
}

void InsertView::changeFormat(int i) {
    if(i==0) {
        ml->setEnabled(true);
        comp->setEnabled(false);
        prezzoMl->setEnabled(true);
        prezzoComp->setEnabled(false);
    }
    if(i==1) {
        ml->setEnabled(false);
        comp->setEnabled(true);
        prezzoMl->setEnabled(false);
        prezzoComp->setEnabled(true);
    }
}

void InsertView::Reset() {
    nome->setText("");
    marca->setText("");
    formato->setCurrentIndex(0);
    ml->setValue(0);
    comp->setValue(0);
    prezzoMl->setValue(0);
    prezzoComp->setValue(0);
    v18->setValue(0);
    v19->setValue(0);
    v20->setValue(0);
    v21->setValue(0);
}
