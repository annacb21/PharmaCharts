#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QChartView>
#include "menu.h"
#include "maincontent.h"
#include "variablesdialog.h"
#include "barchart.h"
#include "linechart.h"
#include "piechart.h"
#include "scatterchart.h"

class MainWindow : public QWidget {
    Q_OBJECT
private:
    Menu* menu;
    QString file;
    QHBoxLayout* mainLayout;
    InsertView* insertView;
    MainContent* mainContent;
    Dataset* dataset;
    VariablesDialog* dialog;
    Chart* chart;
    QChartView* chartView;
public:
    MainWindow(QWidget *parent =nullptr, bool load =true);
    virtual void closeEvent(QCloseEvent* e) override;
    ~MainWindow() override =default;
    /**
     * @brief Decide quali bottoni sono disabilitati e quali no in base alla dimensione del dataset
     */
    void ToggleButtons();
private slots:
    void NewFile();
    void Save();
    void SaveWithName();
    void Load();
    void ShowInsertView();
    void ShowTable();
    void InsertData();
    void RemoveData();
    void CreateBarChart();
    void CreatePieChart();
    void CreateLineChart();
    void CreateScatterChart();
    void CreateChart();
    void UpdateChart();
};

#endif // MAINWINDOW_H
