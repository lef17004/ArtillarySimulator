#pragma once
#include "direction.h"
#include "physics.h"
#include "direction.h"
class Velocity
{
private:
   double dx;
   double dy;

public:
   Velocity(): dx(0), dy(0) {}
   Velocity(double totalSpeed, Direction angle)
   {
      dx = computeHorizontalComponent(angle.getRadians(), totalSpeed);
      dy = computeVerticalComponent(angle.getRadians(), totalSpeed);
   }
   
   double getDx() { return dx; }
   double getDy() { return dy; }
   double getSpeed() { return computeTotalComponent(dx, dy); }
   Direction getDirection();
   void setDx(double dx)
   {
      this->dx = dx;
   }
   void setDy(double dy)
   {
      this->dy = dy;
   }
   void setDxDy(double dx, double dy)
   {
      this->dx = dx;
      this->dy = dy;
   }
   //void setDirection(Direction direction);
   void setSpeed(double speed, Direction angle)
   {
      dx = computeHorizontalComponent(angle.getRadians(), speed);
      dy = computeVerticalComponent(angle.getRadians(), speed);
   }
   void addDx(double dx)
   {
      this->dx += dx;
   }
   void addDy(double dy)
   {
      this->dy = dy;
   }
   void addV(Velocity velocity)
   {
      dx += velocity.getDx();
      dy += velocity.getDy();
   }
   
   double getAngle()
   {
      return angleFromComponent(dx, dy);
   }
   //void reverse();


};
