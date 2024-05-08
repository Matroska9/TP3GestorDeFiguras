#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"

class Circulo : public Figura {
public:
    Circulo(const QPoint& centro, int radio);
    void mostrar() const override;
    void dibujar(QGraphicsScene& scene) const override;
    void trasladarX(int x) override;
    void trasladarY(int y) override;

private:
    QPoint centro;
    int radio;
};

#endif // CIRCULO_H
