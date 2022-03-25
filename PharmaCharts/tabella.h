#ifndef TABELLA_H
#define TABELLA_H

#include <QTableView>
#include <QMouseEvent>

class Tabella : public QTableView {
public:
    Tabella(QWidget* parent =nullptr);
    /**
     * @brief definisce la larghezza della tabella
     */
    QSize getSize() const;
    /**
     * @brief definisce la larghezza delle colonne nella tabella
     */
    void columnSize();
    void mousePressEvent(QMouseEvent* e);
};

#endif // TABELLA_H
