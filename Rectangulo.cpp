#include "Rectangulo.h"
#include <iostream>
#include <QDebug>

Rectangulo::Rectangulo(const QPoint& topLeft, const QPoint& bottomRight)
    : topLeft(topLeft), bottomRight(bottomRight) {}

void Rectangulo::mostrar() const {
    qDebug() << "Rectangulo: Esquina superior izquierda (" << topLeft.x() << ", " << topLeft.y() << "), Esquina inferior derecha (" << bottomRight.x() << ", " << bottomRight.y() << ")";
}

void Rectangulo::dibujar(QGraphicsScene& scene) const {
    QGraphicsRectItem* rectanguloItem = scene.addRect(topLeft.x(), topLeft.y(), bottomRight.x() - topLeft.x(), bottomRight.y() - topLeft.y());
}

void Rectangulo::trasladarX(int x) {
    topLeft.setX(topLeft.x() + x);
    bottomRight.setX(bottomRight.x() + x);
}

void Rectangulo::trasladarY(int y) {
    topLeft.setY(topLeft.y() + y);
    bottomRight.setY(bottomRight.y() + y);
}
