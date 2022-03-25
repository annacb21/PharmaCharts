#ifndef MENU_H
#define MENU_H

#include <QMenuBar>
#include <QMenu>

class Menu: public QMenuBar {
     Q_OBJECT
private:
    QWidget* p;
    QMenu* fileMenu;
    QMenu* editMenu;
    QAction* newAction;
    QAction* saveAction;
    QAction* saveWithNameAction;
    QAction* loadAction;
    QAction* quitAction;
    QAction* insertAction;
    QAction* barchartAction;
    QAction* piechartAction;
    QAction* linechartAction;
    QAction* scatterchartAction;
public:
    Menu(QWidget *parent =nullptr);
    QMenu* getFileMenu() const;
    QMenu* getEditMenu() const;
    QAction* getNewAction() const;
    QAction* getSaveAction() const;
    QAction* getLoadAction() const;
    QAction* getQuitAction() const;
    QAction* getSaveWithNameAction() const;
    QAction* getBarAction() const;
    QAction* getPieAction() const;
    QAction* getLineAction() const;
    QAction* getScatterAction() const;
};
#endif // MENU_H

/* La classe Menu rappresenta il menu dell'applicazione
 * con le azioni principali da fare sul file (carica e salva), le azioni di modifica del dataset (inserisci)
 * e le azioni da fare sui charts.
 * Tutte le azioni del menu vengono gestite nella MainWindow
*/
