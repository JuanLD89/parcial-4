#include "obstaculos.h"

obstaculos::obstaculos()
{
    int random_number = rand() % 1100;
    int random_number1 = rand() %700;

    setPos(random_number,random_number1);

    setPixmap(QPixmap(":/imagen/linea_azul.png").scaled(100,20));

    //Conexion
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move3()));

    timer->start(500);
}

void obstaculos::move3()
{
    scene()->removeItem(this);
    delete this;
}
