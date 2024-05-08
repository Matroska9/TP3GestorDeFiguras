#include "Interpreter.h"
#include <QDebug>

Interpreter::Interpreter(
    CirculoFactory* cf,
    RectanguloFactory* rf,
    TrianguloFactory* tf,
    GestorDeFiguras* gdf
    )
{
    circuloFactory = cf;
    rectanguloFactory = rf;
    trianguloFactory = tf;
    gestorDeFiguras = gdf;
}

void Interpreter::crearCirculo(int centro_x, int centro_y, int radio) {
    QList<int> parametros;
    parametros << centro_x << centro_y << radio;

    Figura* circulo = circuloFactory->crearFigura(parametros);
    if (circulo) {
        gestorDeFiguras->agregarFigura(circulo);
    } else {}
}

void Interpreter::crearRectangulo(int topLeft_x, int topLeft_y, int bottomRight_x, int bottomRight_y) {
    QList<int> parametros;
    parametros << topLeft_x << topLeft_y << bottomRight_x << bottomRight_y;

    Figura* rectangulo = rectanguloFactory->crearFigura(parametros);
    if (rectangulo) {
        gestorDeFiguras->agregarFigura(rectangulo);
    } else {}
}

void Interpreter::crearTriangulo(int c1_x, int c1_y, int c2_x, int c2_y, int c3_x, int c3_y) {
    QList<int> parametros;
    parametros << c1_x << c1_y << c2_x << c2_y << c3_x << c3_y;

    Figura* triangulo = trianguloFactory->crearFigura(parametros);
    if (triangulo) {
        gestorDeFiguras->agregarFigura(triangulo);
    } else {}
}

void Interpreter::imprimirListaFiguras() {
    gestorDeFiguras->mostrarFiguras();
}

void Interpreter::dibujarFiguras(QGraphicsScene& scene) {
    gestorDeFiguras->dibujarFiguras(scene);
}

void Interpreter::eliminarFigura(int indice) {
    gestorDeFiguras->eliminarFigura(indice);
}

void Interpreter::trasladarFiguraX(int indice, int x) {
    gestorDeFiguras->trasladarFiguraX(indice, x);
}

void Interpreter::trasladarFiguraY(int indice, int y) {
    gestorDeFiguras->trasladarFiguraY(indice, y);
}


CommandResult Interpreter::procesarComando(int tipoFigura, int coorX, int coorY) {
    QString msg;
    QString param1;
    QString param2;

    switch (tipoFigura) {
    case 0: // Circulo
        switch (commandIndex) {
        case 0:
            msg = "Ingresar las coordenadas del centro del círculo";
            param1 = "Coordenada X:";
            param2 = "Coordenada Y:";
            commandIndex++;
            break;
        case 1:
            parametros << coorX << coorY;
            msg = "Ingresar radio del círculo";
            param1 = "Radio:";
            commandIndex++;
            break;
        case 2:
            parametros << coorX; // El radio se ingresa en coorX
            crearCirculo(parametros[0], parametros[1], parametros[2]);
            commandIndex = 0;
            parametros.clear();
            break;
        default:
            break;
        }
        break;
    case 1: // Rectangulo
        switch (commandIndex) {
        case 0:
            msg = "Ingresar las coordenadas del vértice superior izquierdo del rectángulo";
            param1 = "Coordenada X:";
            param2 = "Coordenada Y:";
            commandIndex++;
            break;
        case 1:
            parametros << coorX << coorY;
            msg = "Ingresar las coordenadas del vértice inferior derecho del rectángulo";
            param1 = "Coordenada X:";
            param2 = "Coordenada Y:";
            commandIndex++;
            break;
        case 2:
            parametros << coorX << coorY;
            crearRectangulo(parametros[0], parametros[1], parametros[2], parametros[3]);
            commandIndex = 0;
            parametros.clear();
            break;
        default:
            break;
        }
        break;
    case 2: // Triangulo
        switch (commandIndex) {
        case 0:
            msg = "Ingresar las coordenadas del primer vértice del triángulo";
            param1 = "Coordenada X:";
            param2 = "Coordenada Y:";
            commandIndex++;
            break;
        case 1:
            parametros << coorX << coorY;
            msg = "Ingresar las coordenadas del segundo vértice del triángulo";
            param1 = "Coordenada X:";
            param2 = "Coordenada Y:";
            commandIndex++;
            break;
        case 2:
            parametros << coorX << coorY;
            msg = "Ingresar las coordenadas del tercer vértice del triángulo";
            param1 = "Coordenada X:";
            param2 = "Coordenada Y:";
            commandIndex++;
            break;
        case 3:
            parametros << coorX << coorY;
            crearTriangulo(parametros[0], parametros[1], parametros[2], parametros[3], parametros[4], parametros[5]);
            commandIndex = 0;
            parametros.clear();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    return std::make_tuple(msg, param1, param2);
}
