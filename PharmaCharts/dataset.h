#ifndef DATASET_H
#define DATASET_H

#include "flacone.h"
#include "compresse.h"

class Dataset {
private:
    std::vector<Farmaco*> farmaci;
public:
    Dataset();
    ~Dataset();
    Farmaco* operator[](unsigned int i) const;
    std::vector<Farmaco*>::const_iterator begin() const;
    std::vector<Farmaco*>::const_iterator end() const;
    /**
    * @brief Ritorna la dimensione del dataset
    * @return intero che rappresenta la dimensione del dataset
    */
    int getSize() const;
    /**
    * @brief Ritorna un booleano che indica se il dataset è vuoto oppure no
    * @return true sse size()==0
    */
    bool isEmpty() const;
    /**
    * @brief Svuota il dataset deallocando tutti i puntatori
    */
    void clearAll();
    /**
    * @brief Inserisce un nuovo farmaco nel dataset
    */
    void insertData(const Farmaco& f);
    /**
    * @brief Elimina il farmaco in posizione i dal dataset
    */
    void eraseData(unsigned int i);
};

#endif // DATASET_H

/*
 * La classe Dataset rappresenta la collezione di farmaci contenuti in memoria, tramite puntatori polimorfi.
*/
