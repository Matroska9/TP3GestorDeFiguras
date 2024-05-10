#include "Triangulo.h"
#include <iostream>
#include <QDebug>

Triangulo::Triangulo(const QPoint& c1, const QPoint& c2, const QPoint& c3)
    : c1(c1), c2(c2), c3(c3) {}

void Triangulo::mostrar() const {
    qDebug() << "Triangulo: Vértices (" << c1.x() << ", " << c1.y() << "), (" << c2.x() << ", " << c2.y() << "), (" << c3.x() << ", " << c3.y() << ")";
}

QString Triangulo::describir() const {
    return QString("Triangulo:\nVértices (" + QString::number(c1.x()) + ", " + QString::number(c1.y()) + "), (" + QString::number(c2.x()) + ", " + QString::number(c2.y()) + "), (" + QString::number(c3.x()) + ", " + QString::number(c3.y()) + ")\n");
}

void Triangulo::dibujar(QGraphicsScene& scene) const {
    QPolygonF polygon;
    polygon << QPointF(c1.x(), c1.y()) << QPointF(c2.x(), c2.y()) << QPointF(c3.x(), c3.y());
    QGraphicsPolygonItem* trianguloItem = scene.addPolygon(polygon);
}

void Triangulo::trasladarX(int x) {
    c1.setX(c1.x() + x);
    c2.setX(c2.x() + x);
    c3.setX(c3.x() + x);
}

void Triangulo::trasladarY(int y) {
    c1.setY(c1.y() + y);
    c2.setY(c2.y() + y);
    c3.setY(c3.y() + y);
}
