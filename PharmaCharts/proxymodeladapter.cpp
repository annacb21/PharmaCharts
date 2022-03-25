#include "proxymodeladapter.h"

ProxyModelAdapter::ProxyModelAdapter(QObject* parent): QSortFilterProxyModel(parent) {}

bool ProxyModelAdapter::insertRows(int i, int c, const QModelIndex& p) {
    return sourceModel()->insertRows(i, c, p);
}

void ProxyModelAdapter::clearProxy() {
    while(rowCount()) {
        removeRows(0,1);
    }
}
