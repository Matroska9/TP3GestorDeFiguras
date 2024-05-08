#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>
#include <QGraphicsScene>

class Figura {
public:
    virtual ~Figura() {}
    virtual void mostrar() const = 0;
    virtual void dibujar(QGraphicsScene& scene) const = 0;
    virtual void trasladarX(int x) = 0;
    virtual void trasladarY(int y) = 0;
};

#endif // FIGURA_H
