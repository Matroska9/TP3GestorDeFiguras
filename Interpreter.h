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
    CirculoFactory *circuloFactory;
    RectanguloFactory *rectanguloFactory;
    TrianguloFactory *trianguloFactory;
    GestorDeFiguras *gestorDeFiguras;

    int commandIndex = 0;
    QList<int> parametros;

public:
    Interpreter(
        CirculoFactory* cf,
        RectanguloFactory* rf,
        TrianguloFactory* tf,
        GestorDeFiguras* gdf
        );

    void crearCirculo(int centro_x, int centro_y, int radio);
    void crearRectangulo(int topLeft_x, int topLeft_y, int bottomRight_x, int bottomRight_y);
    void crearTriangulo(int c1_x, int c1_y, int c2_x, int c2_y, int c3_x, int c3_y);

    void imprimirListaFiguras();
    void dibujarFiguras(QGraphicsScene& scene);

    void eliminarFigura(int indice);
    void trasladarFiguraX(int indice, int x);
    void trasladarFiguraY(int indice, int y);

    CommandResult procesarComando(int tipoFigura, int coorX, int coorY);

    // Otros métodos para interpretar acciones del usuario
};

#endif // INTERPRETER_H
