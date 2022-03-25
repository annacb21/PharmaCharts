#include "tabella.h"

Tabella::Tabella(QWidget* parent): QTableView(parent) {
    setSelectionBehavior(QAbstractItemView::SelectRows);
}

QSize Tabella::getSize() const {
    return QSize(1200, 700);
}

void Tabella::columnSize() {
    setColumnWidth(0,300);
    setColumnWidth(1,200);
    setColumnWidth(2,150);
    setColumnWidth(3,100);
    setColumnWidth(4,100);
    setColumnWidth(5,150);
    setColumnWidth(6,150);
    setColumnWidth(7,150);
    setColumnWidth(8,150);
    setColumnWidth(9,150);
    setColumnWidth(10,150);
}

void Tabella::mousePressEvent(QMouseEvent* e) {
    if(!indexAt(e->pos()).isValid()){
        clearSelection();
        selectionModel()->clearCurrentIndex();
    }
    QTableView::mousePressEvent(e);
}
