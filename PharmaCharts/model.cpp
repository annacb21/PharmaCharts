#include "model.h"

Farmaco* Model::operator[](unsigned int i) const {
    return dataset->operator [](i);
}

int Model::getSize() const {
    return dataset->getSize();
}

void Model::saveFile(const QString& f) const {
    XmlUtil xml(f);
    xml.writeXml(*dataset);
}

void Model::loadFile(const QString& f) {
    XmlUtil xml(f);
    dataset = xml.readXml();
}

void Model::insert(Farmaco* f) {
    dataset->insertData(*f);
}

void Model::remove(unsigned int i) {
    dataset->eraseData(i);
}

Farmaco* Model::getItemAtIndex(unsigned int i) const {
    return dataset->operator [](i);
}

void Model::updateName(unsigned int i, std::string n) {
    (dataset->operator [](i))->setName(n);
}

void Model::updateBrand(unsigned int i, std::string m) {
    (dataset->operator [](i))->setBrand(m);
}

void Model::updateSelling(unsigned int i, unsigned int v, unsigned int a) {
    (dataset->operator [](i))->setSelling(v,a);
}

void Model::updateMl(unsigned int i, double m) {
    if(dynamic_cast<Flacone*>(dataset->operator [](i))) {
        Flacone* f = dynamic_cast<Flacone*>(dataset->operator [](i));
        f->setMl(m);
    }
}

void Model::updateCompresse(unsigned int i, unsigned int c) {
    if(dynamic_cast<Compresse*>(dataset->operator [](i))) {
        Compresse* comp = dynamic_cast<Compresse*>(dataset->operator [](i));
        comp->setComp(c);
    }
}

void Model::updateBasePrice(unsigned int i, double p) {
    if(dynamic_cast<Flacone*>(dataset->operator [](i))) {
        Flacone* f = dynamic_cast<Flacone*>(dataset->operator [](i));
        f->setPriceMl(p);
    }
    if(dynamic_cast<Compresse*>(dataset->operator [](i))) {
        Compresse* comp = dynamic_cast<Compresse*>(dataset->operator [](i));
        comp->setPriceComp(p);
    }
}

Dataset* Model::getDataset() const {
    return dataset;
}
