#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, bool load): QWidget(parent), file(QString()) {
    setGeometry(180,100,1300,800);
    setWindowTitle("PharmaCharts");
    mainLayout = new QHBoxLayout(this);

    insertView = new InsertView(this);
    mainContent = new MainContent(this,insertView);
    menu = new Menu(this);
    chartView = new QChartView(this);

    mainLayout->setMenuBar(menu);
    mainLayout->addWidget(mainContent);
    mainLayout->addWidget(insertView);
    mainLayout->addWidget(chartView);
    insertView->hide();

    if(load) {
        file = QFileDialog::getOpenFileName(this,tr("Caricamento da file"), "", tr("XML (*.xml);;All Files (*)"));
        if(!file.isEmpty()){
            try{
                setWindowTitle("PharmaCharts - " + QFileInfo(file).fileName());
                mainContent->getAdapter()->loadFromFile(file);
                mainContent->getProxy()->setSourceModel(mainContent->getAdapter());
                mainContent->getTable()->setModel(mainContent->getProxy());
            } catch (std::exception) {
                QMessageBox box(QMessageBox::Warning, "Errore di caricamento", "Non è stato possibile caricare il file scelto", QMessageBox::Ok);
                box.exec();
            }
        }
        else {
            QMessageBox::information(this,tr("Creazione nuovo file"), tr("Se non viene scelto un file da cui caricare i dati verrà creato un nuovo file vuoto\n"), QMessageBox::Ok);
            NewFile();
        }
    }

    mainContent->getTable()->columnSize();
    dataset = mainContent->getAdapter()->getModel()->getDataset();
    ToggleButtons();
    setLayout(mainLayout);

    connect(insertView, SIGNAL(Insert()), this, SLOT(InsertData()));
    connect(insertView, SIGNAL(Close()), this, SLOT(ShowTable()));
    connect(mainContent, SIGNAL(Add()), this, SLOT(ShowInsertView()));
    connect(mainContent, SIGNAL(Remove()), this, SLOT(RemoveData()));
    connect(mainContent, SIGNAL(Update()), this, SLOT(UpdateChart()));
    connect(mainContent, SIGNAL(DrawBarChart()), this, SLOT(CreateBarChart()));
    connect(mainContent, SIGNAL(DrawLineChart()), this, SLOT(CreateLineChart()));
    connect(mainContent, SIGNAL(DrawPieChart()), this, SLOT(CreatePieChart()));
    connect(mainContent, SIGNAL(DrawScatterChart()), this, SLOT(CreateScatterChart()));
}

void MainWindow::closeEvent(QCloseEvent *e) {
    QMessageBox::StandardButton closeMsg = QMessageBox::question(this, tr("Conferma la chiusura"),tr("Stai per uscire dall'applicazione, vuoi salvare i dati?\n"), QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Save);
    if(closeMsg == QMessageBox::Save) {
        Save();
        e->accept();
    }
    else {
        if(closeMsg == QMessageBox::Cancel)
            e->ignore();
        else
            e->accept();
    }
}

void MainWindow::NewFile() {
    file = "untitled";
    QFile qfile(file);
    qfile.open(QIODevice::WriteOnly);
    mainContent->getAdapter()->loadFromFile(file);
    setWindowTitle("PharmaCharts - untitled*");
    mainContent->getProxy()->setSourceModel(mainContent->getAdapter());
    mainContent->getTable()->setModel(mainContent->getProxy());
    dataset = mainContent->getAdapter()->getModel()->getDataset();
    QChart* c = new QChart();
    chartView->setChart(c);
    ToggleButtons();
}

void MainWindow::Save() {
    if(!file.isEmpty() && file!="untitled") {
        try{
            mainContent->getAdapter()->saveToFile(file);
        }
        catch (std::exception){
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
            box.exec();
        }
    }
    else
        SaveWithName();
}

void MainWindow::SaveWithName() {
    file = QFileDialog::getSaveFileName(this, tr("Salva su un file"), "", tr("XML (*.xml);;All Files (*)"));
    if(!file.contains(".xml"))
        file.append(".xml");
    if(!file.isEmpty()){
        setWindowTitle(QFileInfo(file).fileName());
        try {
            mainContent->getAdapter()->saveToFile(file);
        } catch (std::exception) {
            QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
            box.exec();
        }
    }
}

void MainWindow::Load() {
    file = QFileDialog::getOpenFileName(this,tr("Caricamento da file"), "", tr("XML (*.xml);;All Files (*)"));
    if(!file.isEmpty()){
        try{
            setWindowTitle("PharmaCharts - " + QFileInfo(file).fileName());
            mainContent->getAdapter()->loadFromFile(file);
            mainContent->getProxy()->setSourceModel(mainContent->getAdapter());
            mainContent->getTable()->setModel(mainContent->getProxy());
            dataset = mainContent->getAdapter()->getModel()->getDataset();
            QChart* c = new QChart();
            chartView->setChart(c);
            ToggleButtons();
        } catch (std::exception) {
            QMessageBox box(QMessageBox::Warning, "Errore di caricamento", "Non è stato possibile caricare il file scelto", QMessageBox::Ok);
            box.exec();
        }
    }
}

void MainWindow::ShowInsertView() {
    setWindowTitle("Inserimento nuovi dati");
    mainContent->hide();
    insertView->show();
}

void MainWindow::ShowTable() {
    setWindowTitle("PharmaCharts - " + QFileInfo(file).fileName());
    insertView->hide();
    mainContent->show();
}

void MainWindow::InsertData() {
    if(insertView->getName()->text()!="") {
        if(insertView->getBrand()->text()!="") {
            std::vector<unsigned int> vendite;
            vendite.push_back(insertView->getSell2018());
            vendite.push_back(insertView->getSell2019());
            vendite.push_back(insertView->getSell2020());
            vendite.push_back(insertView->getSell2021());
            if(insertView->isFlacone()) {
                if(insertView->getMl()!=0.0){
                    if(insertView->getPriceMl()!=0.0) {
                        Flacone* f = new Flacone(insertView->getName()->text().toStdString(), insertView->getBrand()->text().toStdString(), vendite, insertView->getMl(),insertView->getPriceMl());
                        mainContent->getAdapter()->insertItem(*f);
                        mainContent->getProxy()->insertRows(mainContent->getProxy()->rowCount(),1);
                        mainContent->getTable()->clearSelection();
                        mainContent->getTable()->selectionModel()->clearCurrentIndex();
                        mainContent->getTable()->selectionModel()->select(mainContent->getProxy()->index(mainContent->getAdapter()->rowCount() - 1, 0), QItemSelectionModel::Select);
                        QMessageBox::information(this,tr("Inserimento"), tr("Nuovo farmaco inserito con successo\n"), QMessageBox::Ok);
                        ShowTable();
                        UpdateChart();
                        ToggleButtons();
                        insertView->Reset();
                    }
                    else
                        QMessageBox::warning(this,tr("Errore"), tr("Inserire il prezzo al ml del flacone\n"), QMessageBox::Ok);
                }
                else
                    QMessageBox::warning(this,tr("Errore"), tr("Inserire la quantità di ml del flacone\n"), QMessageBox::Ok);
            }
            if(insertView->isCompressa()) {
                if(insertView->getComp()!=0) {
                    if(insertView->getPriceComp()!=0.0) {
                        Compresse* c = new Compresse(insertView->getName()->text().toStdString(), insertView->getBrand()->text().toStdString(), vendite, insertView->getComp(),insertView->getPriceComp());
                        mainContent->getAdapter()->insertItem(*c);
                        mainContent->getProxy()->insertRows(mainContent->getProxy()->rowCount(),1);
                        mainContent->getTable()->clearSelection();
                        mainContent->getTable()->selectionModel()->clearCurrentIndex();
                        mainContent->getTable()->selectionModel()->select(mainContent->getProxy()->index(mainContent->getAdapter()->rowCount() - 1, 0), QItemSelectionModel::Select);
                        QMessageBox::information(this,tr("Inserimento"), tr("Nuovo farmaco inserito con successo\n"), QMessageBox::Ok);
                        ShowTable();
                        UpdateChart();
                        ToggleButtons();
                        insertView->Reset();
                    }
                    else
                        QMessageBox::warning(this,tr("Errore"), tr("Inserire il prezzo a compressa\n"), QMessageBox::Ok);
                }
                else
                    QMessageBox::warning(this,tr("Errore"), tr("Inserire il numero di compresse per confezione\n"), QMessageBox::Ok);
            }
        }
        else
            QMessageBox::warning(this,tr("Errore"), tr("Inserire una marca per il farmaco\n"), QMessageBox::Ok);
    }
    else
        QMessageBox::warning(this,tr("Errore"), tr("Inserire un nome per il farmaco\n"), QMessageBox::Ok);
}

void MainWindow::RemoveData() {
    const QModelIndexList selection = mainContent->getTable()->selectionModel()->selectedIndexes();
    if(selection.size()>0) {
        mainContent->getProxy()->removeRows(selection.at(0).row(), 1);
        UpdateChart();
        ToggleButtons();
    }
}

void MainWindow::CreateBarChart() {
    dialog = new VariablesDialog(dataset,"bar", this);
    connect(dialog, SIGNAL(Create()), this, SLOT(CreateChart()));
    dialog->exec();
}

void MainWindow::CreateLineChart() {
    dialog = new VariablesDialog(dataset,"line", this);
    connect(dialog, SIGNAL(Create()), this, SLOT(CreateChart()));
    dialog->exec();
}

void MainWindow::CreatePieChart() {
    dialog = new VariablesDialog(dataset,"pie", this);
    connect(dialog, SIGNAL(Create()), this, SLOT(CreateChart()));
    dialog->exec();
}

void MainWindow::CreateScatterChart() {
    dialog = new VariablesDialog(dataset,"scatter", this);
    connect(dialog, SIGNAL(Create()), this, SLOT(CreateChart()));
    dialog->exec();
}

void MainWindow::CreateChart() {
    Variabili* var = NULL;
    Valori* val = NULL;

    if(dialog->getTitle()->text()!="") {
        if(dialog->prezziNomiChecked()) {
            var = new VariabiliNome(*dataset);
            val = new ValoriPrezzo(*dataset);
        }
        else if(dialog->v18NomiChecked()) {
            var = new VariabiliNome(*dataset);
            val = new ValoriVenditeAnno(*dataset,2018);
        }
        else if(dialog->v19NomiChecked()) {
            var = new VariabiliNome(*dataset);
            val = new ValoriVenditeAnno(*dataset,2019);
        }
        else if(dialog->v20NomiChecked()) {
            var = new VariabiliNome(*dataset);
            val = new ValoriVenditeAnno(*dataset,2020);
        }
        else if(dialog->v21NomiChecked()) {
            var = new VariabiliNome(*dataset);
            val = new ValoriVenditeAnno(*dataset,2021);
        }
        else if(dialog->venditeAnniChecked()) {
            var = new VariabiliAnno();
            val = new ValoriVenditeItem(*dataset,dialog->getItemIndex()-1);
        }
        else
            QMessageBox::warning(this,tr("Errore"), tr("Scegliere cosa confronatare nel grafico\n"), QMessageBox::Ok);
    }
    else
        QMessageBox::warning(this,tr("Errore"), tr("Inserire un titolo per il grafico\n"), QMessageBox::Ok);

    if(var!=NULL && val!=NULL) {
        QChart* c;
        if(dynamic_cast<ValoriVendite*>(val) && dynamic_cast<ValoriVendite*>(val)->max()==0) {
            c = new QChart();
            QMessageBox::warning(this,tr("Errore"), tr("Impossibile creare grafico poichè i valori delle vendite sono tutti uguali a 0\n"), QMessageBox::Ok);
        }
        else {
            if(dialog->getChartType() == "bar")
                chart = new BarChart(dialog->getTitle()->text().toStdString(),*var,*val);
            if(dialog->getChartType() == "pie")
                chart = new PieChart(dialog->getTitle()->text().toStdString(),*var,*val);
            if(dialog->getChartType() == "line")
                chart = new LineChart(dialog->getTitle()->text().toStdString(),*var,*val);
            if(dialog->getChartType() == "scatter")
                chart = new ScatterChart(dialog->getTitle()->text().toStdString(),*var,*val);
            c = chart->createChart();
        }
        chartView->setChart(c);
        dialog->accept();
    }
}

void MainWindow::UpdateChart() {
    if(chartView->chart()->title()!=""){
        QChart* c;
        if(dataset->getSize()==0 || (dynamic_cast<PointChart*>(chart) && dataset->getSize()==1)){
            c = new QChart();
            QMessageBox::warning(this,tr("Errore"), tr("Impossibile aggiornare il grafico poichè i dati non sono sufficienti\n"), QMessageBox::Ok);
        }
        else {
            Variabili* var;
            Valori* val;
            if(dynamic_cast<VariabiliNome*>(chart->getVariables()))
                var = new VariabiliNome(*dataset);
            if(dynamic_cast<VariabiliAnno*>(chart->getVariables()))
                var = new VariabiliAnno();
            if(dynamic_cast<ValoriPrezzo*>(chart->getValues()))
                val = new ValoriPrezzo(*dataset);
            if(dynamic_cast<ValoriVenditeAnno*>(chart->getValues()))
                val = new ValoriVenditeAnno(*dataset,dynamic_cast<ValoriVenditeAnno*>(chart->getValues())->getAnno());
            if(dynamic_cast<ValoriVenditeItem*>(chart->getValues()))
                val = new ValoriVenditeItem(*dataset,dynamic_cast<ValoriVenditeItem*>(chart->getValues())->getIndex());

            if(dynamic_cast<ValoriVendite*>(val) && dynamic_cast<ValoriVendite*>(val)->max()==0) {
                c = new QChart();
                QMessageBox::warning(this,tr("Errore"), tr("Impossibile aggiornare grafico poichè i valori delle vendite sono tutti uguali a 0\n"), QMessageBox::Ok);
            }
            else {
                if(dynamic_cast<BarChart*>(chart)) {
                    chart = new BarChart(chart->getTitle(),*var,*val);
                }
                if(dynamic_cast<PieChart*>(chart)) {
                    chart = new PieChart(chart->getTitle(),*var,*val);
                }
                if(dynamic_cast<LineChart*>(chart)) {
                    chart = new LineChart(chart->getTitle(),*var,*val);
                }
                if(dynamic_cast<ScatterChart*>(chart)) {
                    chart = new ScatterChart(chart->getTitle(),*var,*val);
                }
                c = chart->createChart();
            }
        }
        chartView->setChart(c);
        chartView->update();
    }
}

void MainWindow::ToggleButtons() {
    if(dataset->getSize()==0){
        menu->getBarAction()->setEnabled(false);
        menu->getLineAction()->setEnabled(false);
        menu->getPieAction()->setEnabled(false);
        menu->getScatterAction()->setEnabled(false);

        mainContent->getBarBtn()->setEnabled(false);
        mainContent->getLineBtn()->setEnabled(false);
        mainContent->getPieBtn()->setEnabled(false);
        mainContent->getScatterBtn()->setEnabled(false);

        mainContent->getRemoveBtn()->setEnabled(false);
        mainContent->getUpdateBtn()->setEnabled(false);
    }
    else {
        if(dataset->getSize()==1) {
            menu->getLineAction()->setEnabled(false);
            menu->getScatterAction()->setEnabled(false);
            mainContent->getLineBtn()->setEnabled(false);
            mainContent->getScatterBtn()->setEnabled(false);
        }
        else {
            menu->getLineAction()->setEnabled(true);
            menu->getScatterAction()->setEnabled(true);
            mainContent->getLineBtn()->setEnabled(true);
            mainContent->getScatterBtn()->setEnabled(true);
        }
        menu->getBarAction()->setEnabled(true);
        menu->getPieAction()->setEnabled(true);
        mainContent->getBarBtn()->setEnabled(true);
        mainContent->getPieBtn()->setEnabled(true);
        mainContent->getRemoveBtn()->setEnabled(true);
        mainContent->getUpdateBtn()->setEnabled(true);
    }
}
