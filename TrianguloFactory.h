#ifndef TRIANGULOFACTORY_H
#define TRIANGULOFACTORY_H

#include "FiguraFactory.h"
#include "Triangulo.h"

class TrianguloFactory : public FiguraFactory {
public:
    virtual ~TrianguloFactory() {}
    Figura* crearFigura(const QList<int>& parametros) override {
        if (parametros.size() != 6)
            return nullptr;
        return new Triangulo(
            QPoint(parametros.at(0), parametros.at(1)),
            QPoint(parametros.at(2), parametros.at(3)),
            QPoint(parametros.at(4), parametros.at(5))
            );
    }
};

#endif // TRIANGULOFACTORY_H
