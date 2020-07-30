#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>

class obstaculos: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    obstaculos();

public slots:
    void move3();
};

#endif // OBSTACULOS_H
