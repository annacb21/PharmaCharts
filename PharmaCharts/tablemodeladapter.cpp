#include "tablemodeladapter.h"

TableModelAdapter::TableModelAdapter(QObject* parent): QAbstractTableModel(parent), model(new Model()) {}

TableModelAdapter::~TableModelAdapter() {
    delete model;
}

int TableModelAdapter::rowCount(const QModelIndex&) const {
    return model->getSize();
}

int TableModelAdapter::columnCount(const QModelIndex&) const {
    return 11;
}

QVariant TableModelAdapter::headerData(int i, Qt::Orientation o, int r) const {
    if(r != Qt::DisplayRole)
        return QVariant();
    if(o == Qt::Horizontal){
        switch (i){
        case 0:
            return QString("Nome");
            break;
        case 1:
            return QString("Marca");
            break;
        case 2:
            return QString("Formato");
            break;
        case 3:
            return QString("Tot ml");
            break;
        case 4:
            return QString("Tot compresse");
            break;
        case 5:
            return QString("Prezzo unitario (€)");
            break;
        case 6:
            return QString("Vendite 2018");
            break;
        case 7:
            return QString("Vendite 2019");
            break;
        case 8:
            return QString("Vendite 2020");
            break;
        case 9:
            return QString("Vendite 2021");
            break;
        case 10:
            return QString("Prezzo finale (€)");
            break;
        default:
            return QVariant();
            break;
        }
    }
    if(o == Qt::Vertical){
        return QString::number(i+1);
    }
    return QVariant();
}

QVariant TableModelAdapter::data(const QModelIndex& i, int r) const {
    if(!i.isValid() || i.row()>=model->getSize() || i.row()<0)
        return QVariant();
    switch (r) {
        case Qt::DisplayRole:
            switch (i.column()){
                case 0:
                    return QString::fromStdString(model->getItemAtIndex(i.row())->getName());
                    break;
                case 1:
                    return QString::fromStdString(model->getItemAtIndex(i.row())->getBrand());
                    break;
                case 2:
                    return QString::fromStdString(model->getItemAtIndex(i.row())->getType());
                    break;
                case 3:
                    if(dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()))) {
                        Flacone* f = dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()));
                        return f->getMl();
                    }
                    else
                        return QVariant();
                    break;
                case 4:
                    if(dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()))) {
                        Compresse* c = dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()));
                        return c->getComp();
                    }
                    else
                        return QVariant();
                    break;
                case 5:
                    if(dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()))) {
                        Flacone* f = dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()));
                        return f->getPriceMl();
                    }
                    else if(dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()))) {
                        Compresse *c = dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()));
                        return c->getPriceComp();
                    }
                    else
                        return QVariant();
                    break;
                case 6:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2018);
                    break;
                case 7:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2019);
                    break;
                case 8:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2020);
                    break;
                case 9:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2021);
                    break;
                case 10:
                    return model->getItemAtIndex(i.row())->calculatePrice();
                    break;
                default:
                    return QVariant();
                    break;
            }
        case Qt::EditRole:
            switch (i.column()){
                case 0:
                    return QString::fromStdString(model->getItemAtIndex(i.row())->getName());
                    break;
                case 1:
                    return QString::fromStdString(model->getItemAtIndex(i.row())->getBrand());
                    break;
                case 3:
                    if(dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()))) {
                        Flacone* f = dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()));
                        return f->getMl();
                    }
                    else
                        return QVariant();
                    break;
                case 4:
                    if(dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()))) {
                        Compresse* c = dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()));
                        return c->getComp();
                    }
                    else
                        return QVariant();
                    break;
                case 5:
                    if(dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()))) {
                        Flacone* f = dynamic_cast<Flacone*>(model->getItemAtIndex(i.row()));
                        return f->getPriceMl();
                    }
                    else if(dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()))) {
                        Compresse *c = dynamic_cast<Compresse*>(model->getItemAtIndex(i.row()));
                        return c->getPriceComp();
                    }
                    else
                        return QVariant();
                    break;
                case 6:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2018);
                    break;
                case 7:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2019);
                    break;
                case 8:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2020);
                    break;
                case 9:
                    return model->getItemAtIndex(i.row())->getSellingPerYear(2021);
                    break;
                default:
                    return QVariant();
                    break;
            }
        case Qt::TextAlignmentRole:
            return QVariant (Qt::AlignVCenter | Qt::AlignHCenter);
            break;
        case Qt::BackgroundRole:
            if(i.row() % 2)
                return QBrush(QColor(205,234,239,75));
            else
                return QBrush(QColor(79,106,143,75));
            break;
        case Qt::FontRole:
            return QFont("Roboto", 16, QFont::Normal);
            break;
        default:
            break;
    }
    return QVariant();
}

Qt::ItemFlags TableModelAdapter::flags(const QModelIndex& i) const {
    Qt::ItemFlags flags = QAbstractTableModel::flags(i);
    if (i.column() != 10 && i.column() !=2)
        flags |= Qt::ItemIsEditable;
    return flags;
}

bool TableModelAdapter::setData(const QModelIndex& i, const QVariant& v, int r) {
    bool ok = false;
    if (i.column()==10 || i.column()==2 || r!=Qt::EditRole)
        return ok;
    switch (i.column()) {
    case 0:
        model->updateName(i.row(), v.toString().toStdString());
        ok = true;
        break;
    case 1:
        model->updateBrand(i.row(), v.toString().toStdString());
        ok = true;
        break;
    case 3:
        if(v.toDouble()>1000) model->updateMl(i.row(),1000);
        else model->updateMl(i.row(), v.toDouble());
        ok = true;
        break;
    case 4:
        if(v.toUInt()>100) model->updateCompresse(i.row(),100);
        else model->updateCompresse(i.row(), v.toUInt());
        ok = true;
        break;
    case 5:
        if(v.toDouble()>10) model->updateBasePrice(i.row(),10);
        else model->updateBasePrice(i.row(), v.toDouble());
        ok = true;
        break;
    case 6:
        if(v.toDouble()>60000) model->updateSelling(i.row(), 60000,2018);
        else model->updateSelling(i.row(), v.toUInt(),2018);
        ok = true;
        break;
    case 7:
        if(v.toDouble()>60000) model->updateSelling(i.row(), 60000,2019);
        else model->updateSelling(i.row(), v.toUInt(),2019);
        ok = true;
        break;
    case 8:
        if(v.toDouble()>60000) model->updateSelling(i.row(), 60000,2020);
        else model->updateSelling(i.row(), v.toUInt(),2020);
        ok = true;
        break;
    case 9:
        if(v.toDouble()>60000) model->updateSelling(i.row(), 60000,2021);
        else model->updateSelling(i.row(), v.toUInt(),2021);
        ok = true;
        break;
    default:
        ok = false;
        break;
    }
    return ok;
}

void TableModelAdapter::insertItem(Farmaco& f) {
    farmaco = &f;
}

bool TableModelAdapter::insertRows(int i, int c, const QModelIndex& p) {
    beginInsertRows(p,i,i+c-1);
    model->insert(farmaco);
    endInsertRows();
    return true;
}

bool TableModelAdapter::removeRows(int i, int c, const QModelIndex& p) {
    beginRemoveRows(p,i,i+c-1);
    model->remove(i);
    endRemoveRows();
    return true;
}

void TableModelAdapter::saveToFile(const QString& f) const {
    model->saveFile(f);
}

void TableModelAdapter::loadFromFile(const QString& f) {
    model->loadFile(f);
}

Model* TableModelAdapter::getModel() const {
    return model;
}
