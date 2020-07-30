#ifndef OBJECT_H
#define OBJECT_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */
#include "actualizaciones.h"

class object: public QObject, public QGraphicsPixmapItem
{
public:
    object();
    ~object();

    void actualizar1(float v_lim);
    actualizaciones* getobject();
    object *objectt1;

private:
    actualizaciones* objett;
};
#endif // OBJECT_H
