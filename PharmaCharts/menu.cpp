#include "menu.h"

Menu::Menu(QWidget *m): p(m), fileMenu(new QMenu("File", this)), editMenu(new QMenu("Modifica", this)), newAction(new QAction("Nuovo", fileMenu)), saveAction(new QAction("Salva", fileMenu)),
    saveWithNameAction(new QAction("Salva con nome", fileMenu)), loadAction( new QAction("Carica", fileMenu)), quitAction(new QAction("Esci", fileMenu)),
    insertAction(new QAction("Inserisci",editMenu)), barchartAction(new QAction("Crea BarChart",editMenu)), piechartAction(new QAction("Crea PieChart",editMenu)),
    linechartAction(new QAction("Crea LineChart",editMenu)), scatterchartAction(new QAction("Crea ScatterChart",editMenu)) {

    QList<QAction*>actionFileList;
    actionFileList.push_back(newAction);
    actionFileList.push_back(loadAction);
    actionFileList.push_back(saveAction);
    actionFileList.push_back(saveWithNameAction);
    actionFileList.push_back(quitAction);
    fileMenu->addActions(actionFileList);
    actionFileList.clear();
    addMenu(fileMenu);

    QList<QAction*>actionEditList;
    actionEditList.push_back(insertAction);
    actionEditList.push_back(barchartAction);
    actionEditList.push_back(piechartAction);
    actionEditList.push_back(linechartAction);
    actionEditList.push_back(scatterchartAction);
    editMenu->addActions(actionEditList);
    actionEditList.clear();
    addMenu(editMenu);

    connect(newAction,SIGNAL(triggered()),p,SLOT(NewFile()));
    connect(saveAction,SIGNAL(triggered()),p,SLOT(Save()));
    connect(saveWithNameAction,SIGNAL(triggered()),p,SLOT(SaveWithName()));
    connect(loadAction,SIGNAL(triggered()),p, SLOT(Load()));
    connect(quitAction,SIGNAL(triggered()),p, SLOT(close()));
    connect(insertAction, SIGNAL(triggered()), p,SLOT(ShowInsertView()));
    connect(barchartAction, SIGNAL(triggered()), p,SLOT(CreateBarChart()));
    connect(piechartAction, SIGNAL(triggered()), p,SLOT(CreatePieChart()));
    connect(linechartAction, SIGNAL(triggered()), p,SLOT(CreateLineChart()));
    connect(scatterchartAction, SIGNAL(triggered()), p,SLOT(CreateScatterChart()));
}

QMenu* Menu::getFileMenu() const{
    return fileMenu;
}

QMenu* Menu::getEditMenu() const{
    return editMenu;
}

QAction* Menu::getSaveAction() const{
    return saveAction;
}

QAction* Menu::getSaveWithNameAction() const{
    return saveWithNameAction;
}

QAction* Menu::getLoadAction() const{
    return loadAction;
}

QAction* Menu::getQuitAction() const{
    return quitAction;
}

QAction* Menu::getBarAction() const{
    return barchartAction;
}

QAction* Menu::getPieAction() const{
    return piechartAction;
}

QAction* Menu::getLineAction() const{
    return linechartAction;
}

QAction* Menu::getScatterAction() const{
    return scatterchartAction;
}
