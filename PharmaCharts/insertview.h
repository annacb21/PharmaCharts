#ifndef INSERTVIEW_H
#define INSERTVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QLineEdit>
#include <QHBoxLayout>
#include "formatcombobox.h"

class InsertView : public QWidget {
    Q_OBJECT
private:
    QLineEdit* nome;
    QLineEdit* marca;
    FormatComboBox* formato;
    QDoubleSpinBox* ml;
    QSpinBox* comp;
    QDoubleSpinBox* prezzoMl;
    QDoubleSpinBox* prezzoComp;
    QSpinBox* v18;
    QSpinBox* v19;
    QSpinBox* v20;
    QSpinBox* v21;
    QPushButton* insertBtn;
    QPushButton* cancelBtn;
public:
    InsertView(QWidget *parent =nullptr);
    QPushButton* getInsertBtn() const;
    QPushButton* getCancelBtn() const;
    QLineEdit* getName() const;
    QLineEdit* getBrand() const;
    std::string getFormat() const;
    double getMl() const;
    unsigned int getComp() const;
    double getPriceMl() const;
    double getPriceComp() const;
    unsigned int getSell2018() const;
    unsigned int getSell2019() const;
    unsigned int getSell2020() const;
    unsigned int getSell2021() const;
    bool isFlacone() const;
    bool isCompressa() const;
public slots:
    /**
     * @brief Resetta tutti gli input una volta finito l'inserimento
     */
    void Reset();
private slots:
    /**
    * @brief Viene invocato quando si cambia il formato del farmaco,
    * per gestire l'abilitazione degli input legati al tipo di farmaco (Flacone o Compresse)
    */
    void changeFormat(int i);
signals:
    void Insert();
    void Close();
};

#endif // INSERTVIEW_H

/*
 * La classe InsertView rappresenta il widget per l'inserimento di un nuovo dato nella tabella.
*/
