#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "actualizaciones.h"
#include "objeto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void niveles();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    QTimer *timer;

    int h_limit;                //longitud en X del mundo
    int v_limit;
    int x = 0;
    int w = 0;
    QList<objeto*> specialobject;   //lista con los cuerpos para mostrarlos.



};
#endif // MAINWINDOW_H
