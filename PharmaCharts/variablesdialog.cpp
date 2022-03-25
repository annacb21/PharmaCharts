#include "variablesdialog.h"

VariablesDialog::VariablesDialog(Dataset* d, std::string t, QWidget * parent): QDialog(parent), dataset(d), chartType(t) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    setWindowTitle("Creazione del grafico");

    QLabel* titleLabel = new QLabel("Titolo del grafico", this);
    titolo = new QLineEdit();
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(titolo);

    QVBoxLayout* choiceLayout = new QVBoxLayout();
    QLabel* choiceLabel = new QLabel("Scegli cosa confrontare nel grafico");
    prezziXnomi = new QRadioButton("Prezzi per ogni farmaco", this);
    v18Xnomi = new QRadioButton("Vendite nel 2018 per ogni farmaco", this);
    v19Xnomi = new QRadioButton("Vendite nel 2019 per ogni farmaco", this);
    v20Xnomi = new QRadioButton("Vendite nel 2020 per ogni farmaco", this);
    v21Xnomi = new QRadioButton("Vendite nel 2021 per ogni farmaco", this);
    QHBoxLayout* vaLayout = new QHBoxLayout();
    venditeXanni = new QRadioButton("Vendite dal 2018 al 2021 per il farmaco alla riga", this);
    itemIndex = new QComboBox(this);
    for(int i=0; i<d->getSize(); i++){
        itemIndex->addItem(QString::number(i+1));
    }
    itemIndex->setEnabled(false);
    vaLayout->addWidget(venditeXanni);
    vaLayout->addWidget(itemIndex);
    choiceLayout->addWidget(choiceLabel);
    choiceLayout->addWidget(prezziXnomi);
    choiceLayout->addWidget(v18Xnomi);
    choiceLayout->addWidget(v19Xnomi);
    choiceLayout->addWidget(v20Xnomi);
    choiceLayout->addWidget(v21Xnomi);
    choiceLayout->addLayout(vaLayout);
    mainLayout->addLayout(choiceLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    okBtn = new QPushButton("Ok");
    closeBtn = new QPushButton("Annulla");
    buttonsLayout->addWidget(okBtn);
    buttonsLayout->addWidget(closeBtn);
    mainLayout->addLayout(buttonsLayout);

    setLayout(mainLayout);

    connect(venditeXanni, SIGNAL(toggled(bool)),this,SLOT(VenditeSelected(bool)));
    connect(closeBtn, SIGNAL(clicked()), this, SLOT(close()));
    connect(okBtn, SIGNAL(clicked()), this, SIGNAL(Create())); //gestito in MainWindow
}

/* METODI GETTER */

QLineEdit* VariablesDialog::getTitle() const {
    return titolo;
}

std::string VariablesDialog::getChartType() const {
    return chartType;
}

bool VariablesDialog::prezziNomiChecked() const {
    return prezziXnomi->isChecked();
}

bool VariablesDialog::v18NomiChecked() const {
    return v18Xnomi->isChecked();
}

bool VariablesDialog::v19NomiChecked() const {
    return v19Xnomi->isChecked();
}

bool VariablesDialog::v20NomiChecked() const {
    return v20Xnomi->isChecked();
}

bool VariablesDialog::v21NomiChecked() const {
    return v21Xnomi->isChecked();
}

bool VariablesDialog::venditeAnniChecked() const {
    return venditeXanni->isChecked();
}

int VariablesDialog::getItemIndex() const {
    return itemIndex->currentText().toInt();
}

/* PRIVATE SLOTS */

void VariablesDialog::VenditeSelected(bool s) {
    if(s)
        itemIndex->setEnabled(true);
    else
        itemIndex->setEnabled(false);
}
