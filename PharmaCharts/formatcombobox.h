#ifndef FORMATCOMBOBOX_H
#define FORMATCOMBOBOX_H

#include<QComboBox>

class FormatComboBox : public QComboBox {
    Q_OBJECT
public:
    FormatComboBox(QWidget *parent =nullptr);
};

#endif // FORMATCOMBOBOX_H

/* La classe FormatComboBox rappresenta una combo box contenente i
 * possibili formati di un farmaco (flacone o compressa)
*/
