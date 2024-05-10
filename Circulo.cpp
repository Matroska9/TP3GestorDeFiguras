#include "Circulo.h"
#include <iostream>
#include <QDebug>

Circulo::Circulo(const QPoint& centro, int radio)
    : centro(centro), radio(radio) {}

void Circulo::mostrar() const {
    qDebug() << "Circulo: Centro (" << centro.x() << ", " << centro.y() << "), Radio " << radio;
}

QString Circulo::describir() const {
    return QString("Circulo:\nCentro (" + QString::number(centro.x()) + ", " + QString::number(centro.y()) + ")\nRadio " + QString::number(radio) + "\n");
}

void Circulo::dibujar(QGraphicsScene& scene) const {
    QGraphicsEllipseItem* circuloItem = scene.addEllipse(centro.x() - radio, centro.y() - radio, radio * 2, radio * 2);
}

void Circulo::trasladarX(int x) {
    centro.setX(centro.x() + x);
}

void Circulo::trasladarY(int y) {
    centro.setY(centro.y() + y);
}
