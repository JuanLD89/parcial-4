#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include "actualizaciones.h"

class objeto: public QObject, public QGraphicsPixmapItem
{
public:
    objeto();
    ~objeto();

    void actualizar(float v_lim);
    actualizaciones* getobject();
    objeto *object1;

private:
    actualizaciones* object;
};

#endif // OBJETO_H
