#include "actualizaciones.h"
#include <math.h>
#include <cmath>

actualizaciones::actualizaciones(float posX_, float posY_, float velX_, float velY_, float masa_, float radio_, float K_, float e_)

{
    PX = posX_;
    PY = posY_;
    mass = masa_;
    R = radio_;
    VX = velX_;
    VY = velY_;
    AX = 0;
    AY = 0;
    G = 10;
    K = K_;
    e = e_;
    V = 0;
    dt = 0.1;
}

actualizaciones::~actualizaciones()
{

}

float actualizaciones::get_posX()
{
    return PX;
}

float actualizaciones::get_posY()
{
    return PY;
}

float actualizaciones::get_Radio()
{
    return R;
}

float actualizaciones::get_e()
{
    return e;
}

float actualizaciones::get_velX()
{
    return VX;
}

float actualizaciones::get_velY()
{
    return VY;
}

float actualizaciones::get_masa()
{
    return mass;
}

void actualizaciones::set_vel(float velx, float vely, float px, float py)
{
    VX = velx;
    VY = vely;
    PX = px;
    PY = py;
}

void actualizaciones::actualizar()
{
    V = pow(((VX*VX)+(VY*VY)),1/2);
    angulo = atan2(VY, VX);
    if (VX >= 0){
        AX = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-1;
    }
    if (VX < 0){
        AX = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))+1;
    }    AY = (-((1/(2*mass))*(V*V)*(50*50)*0.1)*cos(angulo))-G;
    PX = PX + (VX*dt) + ((AX*(dt*dt))/2);
    PY = PY + (VY*dt) + ((AY*(dt*dt))/2);
    VX = VX + AX*dt;
    VY = VY + AY*dt;
}
