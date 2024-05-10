#ifndef CIRCULOFACTORY_H
#define CIRCULOFACTORY_H

#include "FiguraFactory.h"
#include "Circulo.h"

class CirculoFactory : public FiguraFactory {
public:
    virtual ~CirculoFactory() {}
    Figura* crearFigura(QList<int>& parametros) override {
        if (parametros.size() != 3)
            return nullptr;
        return new Circulo(QPoint(parametros.at(0), parametros.at(1)), parametros.at(2));
    }
};
#endif // CIRCULOFACTORY_H
