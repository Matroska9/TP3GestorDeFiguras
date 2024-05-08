#ifndef RECTANGULOFACTORY_H
#define RECTANGULOFACTORY_H

#include "FiguraFactory.h"
#include "Rectangulo.h"

class RectanguloFactory : public FiguraFactory {
public:
    virtual ~RectanguloFactory() {}
    Figura* crearFigura(const QList<int>& parametros) override {
        if (parametros.size() != 4)
            return nullptr;
        return new Rectangulo(QPoint(parametros.at(0), parametros.at(1)), QPoint(parametros.at(2), parametros.at(3)));
    }
};


#endif // RECTANGULOFACTORY_H
