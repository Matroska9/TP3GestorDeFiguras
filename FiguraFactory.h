#ifndef FIGURAFACTORY_H
#define FIGURAFACTORY_H

#include "Figura.h"

class FiguraFactory {
public:
    virtual Figura* crearFigura(const QList<int>& parametros) = 0;
};

#endif // FIGURAFACTORY_H
