#ifndef VARIABLESDIALOG_H
#define VARIABLESDIALOG_H

#include <QDialog>
#include <QRadioButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include "valoriprezzo.h"
#include "valorivenditeanno.h"
#include "valorivenditeitem.h"
#include "barchart.h"
#include "piechart.h"
#include "linechart.h"
#include "scatterchart.h"
#include "variabili.h"

class VariablesDialog : public QDialog {
    Q_OBJECT
private:
    Dataset* dataset;
    std::string chartType;
    QLineEdit* titolo;
    QRadioButton* prezziXnomi;
    QRadioButton* v18Xnomi;
    QRadioButton* v19Xnomi;
    QRadioButton* v20Xnomi;
    QRadioButton* v21Xnomi;
    QRadioButton* venditeXanni;
    QComboBox* itemIndex;
    QPushButton* okBtn;
    QPushButton* closeBtn;
public:
    VariablesDialog(Dataset* d, std::string t, QWidget * parent =nullptr);
    QLineEdit* getTitle() const;
    std::string getChartType() const;
    bool prezziNomiChecked() const;
    bool v18NomiChecked() const;
    bool v19NomiChecked() const;
    bool v20NomiChecked() const;
    bool v21NomiChecked() const;
    bool venditeAnniChecked() const;
    int getItemIndex() const;
private slots:
    /**
     * @brief Gestisce il comportamento di ItemIndex (ComboBox),
     * il quale viene abilitato sse viene selezionato il RadioButton venditeXAnni
     */
    void VenditeSelected(bool);
signals:
    void Create();
};

#endif // VARIABLESDIALOG_H

/*
 * La classe VariablesDialog serve a gestire il dialog che viene eseguito per la creazione di un grafico.
 * Nel dialog viene chiesto all'utente di inserire un titolo per il grafico
 * e di scegliere che variabili confrontare nel grafico
 * (prezzi per ogni farmaco, vendite di un determinato anno per ogni farmaco, vendite dal 2018 al 2021 per il farmaco scelto)
 */
