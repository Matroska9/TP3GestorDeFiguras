#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsView>
#include "CirculoFactory.h"
#include "RectanguloFactory.h"
#include "TrianguloFactory.h"
#include "GestorDeFiguras.h"
#include "Interpreter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pintarButton_clicked();

    void on_pushButtonCreate_clicked();

    void on_pushButtonSend_clicked();

    void on_imprimirButton_clicked();

private:
    Ui::MainWindow *ui;

    CirculoFactory *circuloFactory;
    RectanguloFactory *rectanguloFactory;
    TrianguloFactory *trianguloFactory;

    GestorDeFiguras *gestorDeFiguras;
    Interpreter *interpreter;

    void setupFigureCreationGUI(bool inProcess);
    int figureIndex = 0;

};

#endif // MAINWINDOW_H
