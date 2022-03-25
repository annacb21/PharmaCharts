#ifndef MODEL_H
#define MODEL_H

#include "xmlutil.h"

class Model {
private:
    Dataset* dataset;
public:
    Model() =default;
    ~Model() =default;
    Farmaco* operator[](unsigned int i) const;
    /**
     * @brief dimensione del dataset
     * @return intero uguale a dataset.size()
     */
    int getSize() const;
    /**
     * @brief salva il file xml
     */
    void saveFile(const QString& f) const;
    /**
     * @brief carica il file xml
     */
    void loadFile(const QString& f);
    /**
     * @brief inserisce un nuovo farmaco nel dataset
     */
    void insert(Farmaco*);
    /**
     * @brief rimuove il farmaco con indice i nel dataset
     */
    void remove(unsigned int i);
    /**
     * @brief ritorna il farmaco con indice i nel dataset
     * @return puntatore al farmaco con indice i
     */
    Farmaco* getItemAtIndex(unsigned int i) const;
    /**
    * @brief modifica il nome del farmaco in posizione i nel dataset
    */
    void updateName(unsigned int i, std::string n);
    /**
    * @brief modifica la marca del farmaco in posizione i nel dataset
    */
    void updateBrand(unsigned int i, std::string m);
    /**
    * @brief modifica la vendita del farmaco in un anno in posizione i nel dataset
    */
    void updateSelling(unsigned int i, unsigned int v, unsigned int a);
    /**
    * @brief modifica gli ml del farmaco in posizione i nel dataset
    */
    void updateMl(unsigned int i, double m);
    /**
    * @brief modifica le compresse del farmaco in posizione i nel dataset
    */
    void updateCompresse(unsigned int i, unsigned int c);
    /**
    * @brief modifica il prezzo base del farmaco in posizione i nel dataset
    */
    void updateBasePrice(unsigned int i, double p);
    /**
     * @brief getter del dataset
     */
    Dataset* getDataset() const;
};

#endif // MODEL_H
