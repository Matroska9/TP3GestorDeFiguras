#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"

class Rectangulo : public Figura {
public:
    Rectangulo(const QPoint& topLeft, const QPoint& bottomRight);
    void mostrar() const override;
    QString describir() const override;
    void dibujar(QGraphicsScene& scene) const override;
    void trasladarX(int x) override;
    void trasladarY(int y) override;

private:
    QPoint topLeft;
    QPoint bottomRight;
};


#endif // RECTANGULO_H
