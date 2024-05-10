#ifndef GESTORDEFIGURAS_H
#define GESTORDEFIGURAS_H

#include <QObject>
#include <QList>
#include <QString>
#include <QDebug>
#include "Figura.h"

class GestorDeFiguras : public QObject {
    Q_OBJECT
public:
    GestorDeFiguras();
    ~GestorDeFiguras();

    void agregarFigura(Figura* figura);
    void eliminarFigura(int indice);

    void mostrarFiguras();
    void dibujarFiguras(QGraphicsScene& scene);
    void dibujarFigura(int index, QGraphicsScene& scene);

    void trasladarFiguraX(int index, int x);
    void trasladarFiguraY(int index, int y);

signals:
    void figurasActualizada(int index, const QString& descripcion);

private:
    QList<Figura*> figuras;

};

#endif // GESTORDEFIGURAS_H
