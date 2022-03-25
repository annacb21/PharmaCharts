#ifndef TABLEMODELADAPTER_H
#define TABLEMODELADAPTER_H

#include <QAbstractTableModel>
#include "model.h"

class TableModelAdapter : public QAbstractTableModel {
private:
    Model* model;
    Farmaco* farmaco;
public:
    TableModelAdapter(QObject* parent =nullptr);
    ~TableModelAdapter() override;
    /**
     * @brief conta le righe della tabella
     * @return numero di righe della tabella
     */
    int rowCount(const QModelIndex& =QModelIndex()) const override;
    /**
     * @brief conta le colonne della tabella
     * @return numero di colonne della tabella
     */
    int columnCount(const QModelIndex& =QModelIndex()) const override;
    /**
     * @brief definisce il contenuto del header della tabella (=nomi delle colonne)
     */
    QVariant headerData(int i, Qt::Orientation o, int r) const override;
    /**
     * @brief definisce il contenuto delle righe della tabella
     */
    QVariant data(const QModelIndex& i, int r =Qt::DisplayRole) const override;
    /**
     * @brief definisce il comportamento delle righe della tabella (modificabili o no)
     */
    Qt::ItemFlags flags(const QModelIndex& i) const override;
    /**
     * @brief gestisce il comportamento delle righe della tabella quando sono modificabili
     * @return true sse la modifica avviene con successo
     */
    bool setData(const QModelIndex& i, const QVariant& v, int r) override;
    /**
    * @brief imposta il campo dati "farmaco" con il farmaco da inserire nella tabella
    */
    void insertItem(Farmaco& f);
    /**
     * @brief inserisce una o più righe nella tabella
     * @return true sse l'inserimento ha successo
     */
    bool insertRows(int i, int c =1, const QModelIndex& p =QModelIndex()) override;
    /**
     * @brief elimina una o più righe dalla tabella
     * @return true sse l'eliminazione ha successo
     */
    bool removeRows(int i, int c =1, const QModelIndex& p =QModelIndex()) override;
    /**
     * @brief salva i dati della tabella nel file xml
     */
    void saveToFile(const QString& f) const;
    /**
     * @brief carica nella tabella i dati dal file xml
     */
    void loadFromFile(const QString& f);
    /**
     * @brief getter modello
     */
    Model* getModel() const;
};

#endif // TABLEMODELADAPTER_H
