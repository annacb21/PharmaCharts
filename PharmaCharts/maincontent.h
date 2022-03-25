#ifndef MAINCONTENT_H
#define MAINCONTENT_H

#include <QWidget>
#include <QIcon>
#include "insertview.h"
#include "tablemodeladapter.h"
#include "proxymodeladapter.h"
#include "tabella.h"

class MainContent : public QWidget {
    Q_OBJECT
private:
    InsertView* insertView;
    TableModelAdapter* adapter;
    ProxyModelAdapter* proxy;
    Tabella* tabella;
    QPushButton* removeBtn;
    QPushButton* addBtn;
    QPushButton* updateBtn;
    QPushButton* barBtn;
    QPushButton* pieBtn;
    QPushButton* lineBtn;
    QPushButton* scatterBtn;
public:
    MainContent(QWidget* parent =nullptr, InsertView* ins =nullptr);
    InsertView* getInsView() const;
    TableModelAdapter* getAdapter() const;
    ProxyModelAdapter* getProxy() const;
    Tabella* getTable() const;
    QPushButton* getRemoveBtn() const;
    QPushButton* getAddBtn() const;
    QPushButton* getUpdateBtn() const;
    QPushButton* getBarBtn() const;
    QPushButton* getPieBtn() const;
    QPushButton* getLineBtn() const;
    QPushButton* getScatterBtn() const;
signals:
    void Remove();
    void Add();
    void Update();
    void DrawBarChart();
    void DrawPieChart();
    void DrawLineChart();
    void DrawScatterChart();
};

#endif // MAINCONTENT_H

/*
 * La classe MainContent rappresenta la view con la tabella dei dati e i bottoni con le azioni
 * da fare sulla tabella e sui grafici.
 * Tutte le azioni dei bottoni vengono gestite in MainWindow
*/
