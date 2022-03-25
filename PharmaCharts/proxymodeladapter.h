#ifndef PROXYMODELADAPTER_H
#define PROXYMODELADAPTER_H

#include <QSortFilterProxyModel>

class ProxyModelAdapter : public QSortFilterProxyModel {
public:
    ProxyModelAdapter(QObject* parent =nullptr);
    /**
     * @brief inserisce una o più righe nella tabella
     * @return true sse l'inserimento ha avuto successo
     */
    bool insertRows(int i, int c =1, const QModelIndex& p =QModelIndex()) override;
    /**
     * @brief svuota la tabella
     */
    void clearProxy();
};

#endif // PROXYMODELADAPTER_H
