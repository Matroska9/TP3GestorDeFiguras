#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsView>
#include <QStringListModel>
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

    void actualizarListView(int index, const QString& descripcion);

    void on_pushButtonPintarIn_clicked();

    void on_pushButtonTrasladarIn_clicked();

    void on_pushButtonEliminarIn_clicked();

    void on_listViewFigures_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    QList<FiguraFactory*> *figuraFactories;
    GestorDeFiguras *gestorDeFiguras;
    Interpreter *interpreter;

    QStringListModel *listModel;

    void setupFigureCreationGUI(bool inProcess);
    void updateFigureCreationGUI(CommandResult result);
    void updateFigureCoordsGUI(CommandResult result);

    int figureIndex = 0;

};

#endif // MAINWINDOW_H
