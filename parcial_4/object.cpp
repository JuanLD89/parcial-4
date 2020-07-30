#include "object.h"
#include "QDebug"
#include <stdlib.h>     /* srand, rand, abs */
#include <time.h>       /* time */

object::object()
{
    int random_number = rand() % 1100;
    setPixmap(QPixmap(":/imagen/bolaazul (1).png").scaled(50,50));
    float posx, posy, velx , vely ,r, mass, K, e;
    posx = random_number;
    posy = 550;
    r = 65;
    mass = 50;
    velx = 40;
    vely = 60;
    K = 0.08;
    e = 0.2;

    objett = new actualizaciones(posx,posy,velx,vely,mass,r,K,e);
}

object::~object()
{
    delete objett;
}

void object::actualizar1(float v_lim)
{
    objett->actualizar();
    setPos(objett->get_posX(),(v_lim-objett->get_posY()));
}

actualizaciones *object::getobject()
{
    return objett;
}
