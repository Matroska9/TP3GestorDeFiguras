#include "GestorDeFiguras.h"

GestorDeFiguras::GestorDeFiguras() { }

GestorDeFiguras::~GestorDeFiguras() {
    qDeleteAll(figuras);
}

void GestorDeFiguras::agregarFigura(Figura* figura) {
    figuras.append(figura);
}

void GestorDeFiguras::eliminarFigura(int indice) {
    if (indice >= 0 && indice < figuras.size()) {
        delete figuras.takeAt(indice);
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

void GestorDeFiguras::trasladarFiguraX(int index, int x) {
    if (index >= 0 && index < figuras.size()) {
        figuras[index]->trasladarX(x);
    }
}

void GestorDeFiguras::trasladarFiguraY(int index, int y) {
    if (index >= 0 && index < figuras.size()) {
        figuras[index]->trasladarY(y);
    }
}
