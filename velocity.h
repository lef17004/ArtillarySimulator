#pragma once
#include "direction.h"

class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity(): dx(0), dy(0) {}
   Velocity(double dx, double dy): dx(dx), dy(dy) {}
   Velocity(double totalVelocity)
   {
      
   }
   double getDx();
   double getDy();
   double getSpeed();
   Direction getDirection();
   void setDx(double dx);
   void setDy(double dy);
   void setDxDy(double dx, double dy);
   void setDirection(Direction direction);
   void setSpeed(double speed);
   void addDx(double dx);
   void addDy(double dy);
   void addV(Velocity velocity);
   void reverse();


};
