#include "Interpreter.h"
#include <QDebug>

Interpreter::Interpreter(
    QList<FiguraFactory*> *ff,
    GestorDeFiguras *gdf
    )
{
    figuraFactories = ff;
    gestorDeFiguras = gdf;
    parametros = new QList<int>();
}

void Interpreter::crearFigura(int figuraType) {
    Figura* figura = (figuraFactories->at(figuraType))->crearFigura(*parametros);
    if (figura) {
        gestorDeFiguras->agregarFigura(figura);
    }
}

void Interpreter::imprimirListaFiguras() {
    gestorDeFiguras->mostrarFiguras();
}

void Interpreter::dibujarFiguras(QGraphicsScene& scene) {
    gestorDeFiguras->dibujarFiguras(scene);
}

void Interpreter::dibujarFigura(int index, QGraphicsScene& scene) {
    gestorDeFiguras->dibujarFigura(index, scene);
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


CommandResult Interpreter::procesarComando(int tipoFigura, int paramA, int paramB) {
    QString msg;
    QString paramLabelA;
    QString paramLabelB;

    switch (tipoFigura) {
    case 0: // Circulo
        switch (commandIndex) {
        case 0:
            msg = "Ingresar las coordenadas del centro del círculo";
            paramLabelA = "Coordenada X:";
            paramLabelB = "Coordenada Y:";
            commandIndex++;
            break;
        case 1:
            *parametros << paramA << paramB;
            msg = "Ingresar radio del círculo";
            paramLabelA = "Radio:";
            commandIndex++;
            break;
        case 2:
            *parametros << paramA; // El radio se ingresa en paramA
            crearFigura(tipoFigura);
            limpiarParametros();
            break;
        default:
            break;
        }
        break;

    case 1: // Rectangulo
        switch (commandIndex) {
        case 0:
            msg = "Ingresar las coordenadas del vértice superior izquierdo del rectángulo";
            paramLabelA = "Coordenada X:";
            paramLabelB = "Coordenada Y:";
            commandIndex++;
            break;
        case 1:
            *parametros << paramA << paramB;
            msg = "Ingresar las coordenadas del vértice inferior derecho del rectángulo";
            paramLabelA = "Coordenada X:";
            paramLabelB = "Coordenada Y:";
            commandIndex++;
            break;
        case 2:
            *parametros << paramA << paramB;
            crearFigura(tipoFigura);
            limpiarParametros();
            break;
        default:
            break;
        }
        break;

    case 2: // Triangulo
        switch (commandIndex) {
        case 0:
            msg = "Ingresar las coordenadas del primer vértice del triángulo";
            paramLabelA = "Coordenada X:";
            paramLabelB = "Coordenada Y:";
            commandIndex++;
            break;
        case 1:
            *parametros << paramA << paramB;
            msg = "Ingresar las coordenadas del segundo vértice del triángulo";
            paramLabelA = "Coordenada X:";
            paramLabelB = "Coordenada Y:";
            commandIndex++;
            break;
        case 2:
            *parametros << paramA << paramB;
            msg = "Ingresar las coordenadas del tercer vértice del triángulo";
            paramLabelA = "Coordenada X:";
            paramLabelB = "Coordenada Y:";
            commandIndex++;
            break;
        case 3:
            *parametros << paramA << paramB;
            crearFigura(tipoFigura);
            limpiarParametros();
            break;
        default:
            break;
        }
        break;

    case 3: // trasladar
        switch (commandIndex) {
        case 0:
            msg = "Ingresar El desplazamiento en las coordenadas X e Y";
            paramLabelA = "Desplazamiento en X:";
            paramLabelB = "Desplazamiento en Y:";
            *parametros << paramA;
            commandIndex++;
            break;
        case 1:
            trasladarFiguraX((*parametros)[0], paramA);
            trasladarFiguraY((*parametros)[0], paramB);
            limpiarParametros();
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }

    return std::make_tuple(msg, paramLabelA, paramLabelB);
}

void Interpreter::limpiarParametros() {
    commandIndex = 0;
    parametros->clear();
}
