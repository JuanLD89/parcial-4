#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include "actualizaciones.h"
#include "objeto.h"
#include "object.h"
#include "obstaculos.h"

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
    void actualizar();
    void actualizar1();
    void creatobjeto();
    void platforms();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    QTimer *timer;
    QTimer *timert;

    int h_limit;                //longitud en X del mundo
    int v_limit;
    int x = 0;
    int w = 0;
    int k = 0;
    void bordercollision(actualizaciones *b);   //metodo para las colisiones con los bordes del mundo
    QList<objeto*> specialobject;   //lista con los cuerpos para mostrarlos.
    QList<object*> objetoo;   //lista con los cuerpos para mostrarlos.



};
#endif // MAINWINDOW_H
