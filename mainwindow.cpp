#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    circuloFactory = new CirculoFactory();
    rectanguloFactory = new RectanguloFactory();
    trianguloFactory = new TrianguloFactory();

    gestorDeFiguras = new GestorDeFiguras();
    interpreter = new Interpreter(circuloFactory, rectanguloFactory, trianguloFactory, gestorDeFiguras);

    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gestorDeFiguras;
    delete interpreter;
    delete circuloFactory;
    delete rectanguloFactory;
    delete trianguloFactory;
}

void MainWindow::on_pintarButton_clicked()
{
    ui->graphicsView->scene()->clear();
    QGraphicsScene* scene = ui->graphicsView->scene();
    interpreter->dibujarFiguras(*scene);
}

void MainWindow::on_imprimirButton_clicked()
{
    interpreter->imprimirListaFiguras();
}

void MainWindow::on_pushButtonCreate_clicked()
{
    if(ui->radioButtonCirculo->isChecked()) {
        figureIndex = 0;
    } else if(ui->radioButtonRectangulo->isChecked()) {
        figureIndex = 1;
    } else {
        figureIndex = 2;
    }
    setupFigureCreationGUI(true);

    CommandResult result = interpreter->procesarComando(figureIndex, 0, 0);

    ui->lineEditCommand->setText(std::get<0>(result));
    ui->label_x->setText(std::get<1>(result));
    ui->label_y->setText(std::get<2>(result));

}


void MainWindow::on_pushButtonSend_clicked()
{
    int coorX = ui->lineEditCoorX->text().toInt();
    int coorY = ui->lineEditCoorY->text().toInt();

    CommandResult result = interpreter->procesarComando(figureIndex, coorX, coorY);
    ui->lineEditCoorY->setEnabled(!std::get<2>(result).isEmpty());
    ui->lineEditCommand->setText(std::get<0>(result));
    ui->label_x->setText(std::get<1>(result));
    ui->label_y->setText(std::get<2>(result));

    if(std::get<0>(result) == "") {
        setupFigureCreationGUI(false);
    }
    ui->lineEditCoorX->setText("");
    ui->lineEditCoorY->setText("");
}


void MainWindow::setupFigureCreationGUI(bool inProcess) {
    ui->radioButtonCirculo->setEnabled(!inProcess);
    ui->radioButtonRectangulo->setEnabled(!inProcess);
    ui->radioButtonTriangulo->setEnabled(!inProcess);

    ui->lineEditCoorX->setEnabled(inProcess);
    ui->lineEditCoorY->setEnabled(inProcess);

    ui->pushButtonSend->setEnabled(inProcess);
    ui->pushButtonCreate->setEnabled(!inProcess);
    ui->pushButtonEliminarIn->setEnabled(!inProcess);
    ui->pushButtonPintarIn->setEnabled(!inProcess);
    ui->pushButtonTrasladarIn->setEnabled(!inProcess);
    ui->pintarButton->setEnabled(!inProcess);
    ui->imprimirButton->setEnabled(!inProcess);
}

