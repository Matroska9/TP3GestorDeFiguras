#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "CirculoFactory.h"
#include "RectanguloFactory.h"
#include "TrianguloFactory.h"
#include "GestorDeFiguras.h"
#include <QGraphicsScene>
#include <tuple>

using CommandResult = std::tuple<QString, QString, QString>;

class Interpreter {
private:
    QList<int> *parametros;
    QList<FiguraFactory*> *figuraFactories;
    GestorDeFiguras *gestorDeFiguras;

    int commandIndex = 0;

    void limpiarParametros();

public:
    Interpreter(
        QList<FiguraFactory*> *ff,
        GestorDeFiguras* gdf
        );

    void crearFigura(int figuraType);

    void imprimirListaFiguras();
    void dibujarFiguras(QGraphicsScene& scene);
    void dibujarFigura(int index, QGraphicsScene& scene);

    void eliminarFigura(int indice);
    void trasladarFiguraX(int indice, int x);
    void trasladarFiguraY(int indice, int y);

    CommandResult procesarComando(int tipoFigura, int coorX, int coorY);

};

#endif // INTERPRETER_H
