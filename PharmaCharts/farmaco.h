#ifndef FARMACO_H
#define FARMACO_H

#include <string>
#include <vector>
#include <stdexcept>

class Farmaco {
private:
    std::string nome;
    std::string marca;
    std::vector<unsigned int> vendite;
public:
    Farmaco(std::string n, std::string m, std::vector<unsigned int> v);
    virtual ~Farmaco() =default;
    virtual bool operator==(const Farmaco& f) const =0;
    virtual bool operator!=(const Farmaco& f) const =0;
    virtual Farmaco* clone() const =0;
    /**
    * @brief Calcola il prezzo finale in base al tipo di farmaco
    * @return prezzo del farmaco
    */
    virtual double calculatePrice() const =0;
    /**
    * @brief Ritorna il tipo di farmaco
    * @return stringa che rappresenta il tipo di farmaco
    */
    virtual std::string getType() const =0;
    /* Metodi getter*/
    std::string getName() const;
    std::string getBrand() const;
    std::vector<unsigned int> getSellings() const;
    /**
    * @brief Ritorna il numero di vendite nell'anno dato
    * @return intero che rappresenta il numero di ventite nell'anno y
    */
    unsigned int getSellingPerYear(unsigned int y) const;
    /* Metodi setter */
    void setName(std::string n);
    void setBrand(std::string m);
    void setSelling(unsigned int v, unsigned int a);
};

#endif // FARMACO_H

/*
 * La classe Farmaco è una classe base polimorfa astratta che rappresenta un generico farmaco.
 * Ogni farmaco è caratterizzato da un nome, una marca e il numero di vendite dal 2018 al 2021.
 * La classe definisce i seguenti metodi virtuali puri:
 * - double calculatePrice() : ritorna il prezzo finale in base al tipo di farmaco
 * - std::string getType() : ritorna il tipo di farmaco in forma di stringa
 * - Farmaco* clone() const : metodo di clonazione
*/
