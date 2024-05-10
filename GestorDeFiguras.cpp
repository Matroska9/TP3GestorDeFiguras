#include "GestorDeFiguras.h"

GestorDeFiguras::GestorDeFiguras() { }

GestorDeFiguras::~GestorDeFiguras() {
    qDeleteAll(figuras);
}

void GestorDeFiguras::agregarFigura(Figura* figura) {
    figuras.append(figura);
    emit figurasActualizada(figuras.size() - 1, figura->describir());
}

void GestorDeFiguras::eliminarFigura(int indice) {
    if (indice >= 0 && indice < figuras.size()) {
        delete figuras.takeAt(indice);
        emit figurasActualizada(indice, "");
    }
}

void GestorDeFiguras::mostrarFiguras() {
    qDebug() << "Figuras:";
    for (Figura* figura : figuras) {
        figura->mostrar();
    }
}

void GestorDeFiguras::dibujarFiguras(QGraphicsScene& scene) {
    for (const auto& figura : figuras) {
        figura->dibujar(scene);
    }
}

void GestorDeFiguras::dibujarFigura(int index, QGraphicsScene& scene) {
    figuras[index]->dibujar(scene);
}

void GestorDeFiguras::trasladarFiguraX(int index, int x) {
    if (index >= 0 && index < figuras.size()) {
        figuras[index]->trasladarX(x);
        emit figurasActualizada(index, figuras[index]->describir());
    }
}

void GestorDeFiguras::trasladarFiguraY(int index, int y) {
    if (index >= 0 && index < figuras.size()) {
        figuras[index]->trasladarY(y);
        emit figurasActualizada(index, figuras[index]->describir());
    }
}
