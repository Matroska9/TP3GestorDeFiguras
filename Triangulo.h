#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura {
public:
    Triangulo(const QPoint& c1, const QPoint& c2, const QPoint& c3);
    void mostrar() const override;
    void dibujar(QGraphicsScene& scene) const override;
    void trasladarX(int x) override;
    void trasladarY(int y) override;

private:
    QPoint c1, c2, c3;
};

#endif // TRIANGULO_H
