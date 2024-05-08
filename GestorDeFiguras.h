#ifndef GESTORDEFIGURAS_H
#define GESTORDEFIGURAS_H

#include "Figura.h"
#include <QDebug>
#include <QList>
#include <QGraphicsScene>

class GestorDeFiguras {
public:
    GestorDeFiguras();
    ~GestorDeFiguras();

    void agregarFigura(Figura* figura);
    void eliminarFigura(int indice);

    void mostrarFiguras();
    void dibujarFiguras(QGraphicsScene& scene);

    void trasladarFiguraX(int index, int x);
    void trasladarFiguraY(int index, int y);

private:
    QList<Figura*> figuras;
};

#endif // GESTORDEFIGURAS_H
