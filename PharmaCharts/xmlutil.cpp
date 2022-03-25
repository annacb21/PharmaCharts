#include "xmlutil.h"

XmlUtil::XmlUtil(const QString& f): file(f) {}

Dataset* XmlUtil::readXml() const {
    Dataset* dataset = new Dataset();
    QFile qfile(file);
    if(!qfile.open(QIODevice::ReadOnly)) {
        qWarning() << "Errore, non è stato possibile aprire il file" << qfile.errorString();
        return dataset;
    }
    if(file == "untitled") {
        qfile.close();
        return dataset;
    }
    QXmlStreamReader reader(&qfile);
    if(reader.readNextStartElement() && (reader.name() == "Farmaci" || reader.name() == "farmaci")){
        while(reader.readNextStartElement()){
            QStringRef type = reader.name();
            while(reader.readNextStartElement()) {
                std::string nome = reader.readElementText().toStdString();
                reader.readNextStartElement();
                std::string marca = reader.readElementText().toStdString();
                std::vector<unsigned int> vendite;
                while(reader.readNextStartElement()) {
                    reader.readNextStartElement();
                    unsigned int v18 = reader.readElementText().toUInt();
                    vendite.push_back(v18);
                    reader.readNextStartElement();
                    unsigned int v19 = reader.readElementText().toUInt();
                    vendite.push_back(v19);
                    reader.readNextStartElement();
                    unsigned int v20 = reader.readElementText().toUInt();
                    vendite.push_back(v20);
                    reader.readNextStartElement();
                    unsigned int v21 = reader.readElementText().toUInt();
                    vendite.push_back(v21);
                }
                reader.readNextStartElement();
                if(type == "Flacone" || type == "flacone") {
                    double ml = reader.readElementText().toDouble();
                    reader.readNextStartElement();
                    double prezzoB = reader.readElementText().toDouble();
                    try {
                        Flacone* f = new Flacone(nome,marca,vendite,ml,prezzoB);
                        dataset->insertData(*f);
                    }
                    catch(std::exception) {
                        QMessageBox box(QMessageBox::Warning, "Errore", "Impossibile caricare dati da file", QMessageBox::Ok);
                        box.exec();
                    }
                }
                else if(type == "Compresse" || type == "compresse") {
                    unsigned int comp = reader.readElementText().toUInt();
                    reader.readNextStartElement();
                    double prezzoB = reader.readElementText().toDouble();
                    try {
                        Compresse* c = new Compresse(nome,marca,vendite,comp,prezzoB);
                        dataset->insertData(*c);
                    }
                    catch(std::exception) {
                        QMessageBox box(QMessageBox::Warning, "Errore", "Impossibile caricare dati da file", QMessageBox::Ok);
                        box.exec();
                    }
                }
                else {
                    QMessageBox box(QMessageBox::Warning, "Errore", "File corrotto o non valido. L'applicazione verrà chiusa", QMessageBox::Ok);
                    box.exec();
                    exit(0);
                }
            }
        }
    }
    else {
        QMessageBox box(QMessageBox::Warning, "Errore", "File corrotto o non valido. L'applicazione verrà chiusa", QMessageBox::Ok);
        box.exec();
        exit(0);
    }
    qfile.close();
    return dataset;
}

void XmlUtil::writeXml(const Dataset& d) const {
    QSaveFile sfile(file);
    if(!sfile.open(QIODevice::WriteOnly))
        throw std::exception();
    QXmlStreamWriter writer(&sfile);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("Farmaci");
    for(auto cit=d.begin(); cit!=d.end(); ++cit){
        const Farmaco* farmaco = (*cit)->clone();
        writer.writeStartElement(QString::fromStdString(farmaco->getType()));
        writer.writeStartElement("Nome");
        writer.writeCharacters(QString::fromStdString(farmaco->getName()));
        writer.writeEndElement();
        writer.writeStartElement("Marca");
        writer.writeCharacters(QString::fromStdString(farmaco->getBrand()));
        writer.writeEndElement();
        writer.writeStartElement("Vendite");
        writer.writeStartElement("Vendite2018");
        writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<unsigned int>(farmaco->getSellingPerYear(2018)))));
        writer.writeEndElement();
        writer.writeStartElement("Vendite2019");
        writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<unsigned int>(farmaco->getSellingPerYear(2019)))));
        writer.writeEndElement();
        writer.writeStartElement("Vendite2020");
        writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<unsigned int>(farmaco->getSellingPerYear(2020)))));
        writer.writeEndElement();
        writer.writeStartElement("Vendite2021");
        writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<unsigned int>(farmaco->getSellingPerYear(2021)))));
        writer.writeEndElement();
        writer.writeEndElement();
        if(farmaco->getType() == "Flacone") {
            writer.writeStartElement("Ml");
            QString ml = QString::number(static_cast<const Flacone*>(farmaco)->getMl());
            writer.writeCharacters(ml);
            writer.writeEndElement();
            writer.writeStartElement("PrezzoMl");
            QString prezzoml = QString::number(static_cast<const Flacone*>(farmaco)->getPriceMl());
            writer.writeCharacters(prezzoml);
            writer.writeEndElement();
        }
        if(farmaco->getType() == "Compresse") {
            writer.writeStartElement("Comp");
            writer.writeCharacters(QString::fromStdString(std::to_string(static_cast<unsigned int>(static_cast<const Compresse*>(farmaco)->getComp()))));
            writer.writeEndElement();
            writer.writeStartElement("PrezzoComp");
            QString prezzocomp = QString::number(static_cast<const Compresse*>(farmaco)->getPriceComp());
            writer.writeCharacters(prezzocomp);
            writer.writeEndElement();
        }
        writer.writeEndElement();
        if(writer.hasError())
            throw std::exception();
    }
    writer.writeEndElement();
    writer.writeEndDocument();
    sfile.commit();
}
