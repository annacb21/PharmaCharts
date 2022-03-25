#ifndef VALORINORM_H
#define VALORINORM_H

#include "valori.h"

class ValoriNorm {
public:
    virtual ~ValoriNorm() =default;
    virtual int getSize() const =0;
    virtual bool isEmpty() const =0;
};

#endif // VALORINORM_H

/*
* La classe ValoriNorm rappresenta i valori normalizzati in modo da visualizzarli nei chart in modo proporzionato.
* La classe è astratta e da lei derivano le classi concrete dei prezzi e delle vendite normalizzati
*/
