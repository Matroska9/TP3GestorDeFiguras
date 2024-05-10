#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    figuraFactories = new QList<FiguraFactory*>();
    figuraFactories->append(new CirculoFactory());
    figuraFactories->append(new RectanguloFactory());
    figuraFactories->append(new TrianguloFactory());

    gestorDeFiguras = new GestorDeFiguras();
    interpreter = new Interpreter(figuraFactories, gestorDeFiguras);
    listModel = new QStringListModel(this);

    connect(gestorDeFiguras, &GestorDeFiguras::figurasActualizada, this, &MainWindow::actualizarListView);

    ui->setupUi(this);
    ui->graphicsView->setScene(new QGraphicsScene(this));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gestorDeFiguras;
    delete interpreter;
    delete figuraFactories;
    delete listModel;
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
    updateFigureCoordsGUI(result);
}

void MainWindow::on_pushButtonSend_clicked()
{
    int coorX = ui->lineEditCoorX->text().toInt();
    int coorY = ui->lineEditCoorY->text().toInt();
    CommandResult result = interpreter->procesarComando(figureIndex, coorX, coorY);
    updateFigureCreationGUI(result);
}

void MainWindow::on_pushButtonPintarIn_clicked()
{
    int index = ui->lineEditIndex->text().toInt();
    QGraphicsScene* scene = ui->graphicsView->scene();
    interpreter->dibujarFigura(index, *scene);
}


void MainWindow::on_pushButtonTrasladarIn_clicked()
{
    setupFigureCreationGUI(true);
    figureIndex = 3;
    int index = ui->lineEditIndex->text().toInt();
    CommandResult result = interpreter->procesarComando(3, index, 0);
    updateFigureCoordsGUI(result);
}


void MainWindow::on_pushButtonEliminarIn_clicked()
{
    int index = ui->lineEditIndex->text().toInt();
    interpreter->eliminarFigura(index);
}

void MainWindow::on_listViewFigures_clicked(const QModelIndex &index)
{
    if (index.isValid()) {
        QString itemText = index.data().toString();
        QStringList parts = itemText.split(". ");
        if (parts.size() > 1) {
            QString indexText = parts.first();
            ui->lineEditIndex->setText(indexText);
        }
    }
}


void MainWindow::actualizarListView(int index, const QString& descripcion) {
    QStringList stringList = listModel->stringList();
    QString indexedDescription = QString::number(index) + ". " + descripcion;

    if (index >= 0 && index < stringList.size()) {
        stringList[index] = indexedDescription;
    } else {
        stringList << indexedDescription;
    }

    if (descripcion.isEmpty()) {
        stringList.removeAt(index);
        for (int i = index; i < stringList.size(); ++i) {
            QString description = stringList.at(i);
            int currentIndex = description.indexOf(".");
            stringList[i] = QString::number(i) + description.mid(currentIndex);
        }
    }
    listModel->setStringList(stringList);
    ui->listViewFigures->setModel(listModel);
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

void MainWindow::updateFigureCreationGUI(CommandResult result) {
    ui->lineEditCoorY->setEnabled(!std::get<2>(result).isEmpty());
    updateFigureCoordsGUI(result);

    if(std::get<0>(result) == "") {
        setupFigureCreationGUI(false);
    }
    ui->lineEditCoorX->setText("");
    ui->lineEditCoorY->setText("");
}

void MainWindow::updateFigureCoordsGUI(CommandResult result) {
    ui->lineEditCommand->setText(std::get<0>(result));
    ui->label_x->setText(std::get<1>(result));
    ui->label_y->setText(std::get<2>(result));
}




