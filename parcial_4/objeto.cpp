#include "objeto.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */

objeto::objeto()
{
    int random_number = rand() % 1100;
    setPixmap(QPixmap(":/imagen/bolaroja (1).png").scaled(50,50));
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = random_number;
    posy = 600;
    r = 65;
    mass = 50;
    velx = 0;
    vely = 0;
    K = 0.08;
    e = 0.2;

    object = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);
}

objeto::~objeto()
{
    delete object;
}

void objeto::actualizar(float v_lim)
{
    object->actualizar();
    setPos(object->get_posX(),(v_lim-object->get_posY()));
}

actualizaciones *objeto::getobject()
{
    return object;
}
