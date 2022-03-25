#ifndef XMLUTIL_H
#define XMLUTIL_H

#include <QFile>
#include <QString>
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMessageBox>
#include <QDebug>
#include "dataset.h"

class XmlUtil {
private:
    QString file;
public:
    XmlUtil(const QString& f);
    /**
     * @brief legge i dati da file xml
     * @return il dataset con i dati letti dal file xml
     */
    Dataset* readXml() const;
    /**
     * @brief scrive i dati del dataset su un file xml
     */
    void writeXml(const Dataset& d) const;
};

#endif // XMLUTIL_H

/*
 * La classe XmlUtil contiene i metodi per leggere e scrivere da/su un file Xml
*/
