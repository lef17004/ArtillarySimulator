#pragma once
#include "direction.h"
#include "physics.h"
class Velocity
{
private:
   double totalSpeed;

public:
   Velocity(): totalSpeed(0) {}
   Velocity(double totalSpeed): totalSpeed(totalSpeed) {};
   
   double getDx(Direction angle) {return computeHorizontalComponent(angle.getRadians(), totalSpeed);}
   double getDy(Direction angle) {return computeVerticalComponent(angle.getRadians(), totalSpeed);}
   double getSpeed() {return totalSpeed;}
   Direction getDirection();
   void setDx(double dx, Direction angle)
   {
      double dy = computeVerticalComponent(angle.getRadians(), totalSpeed);
      totalSpeed = computeTotalComponent(dx, dy);
   }
   void setDy(double dy, Direction angle)
   {
      double dx = computeHorizontalComponent(angle.getRadians(), totalSpeed);
      totalSpeed = computeTotalComponent(dx, dy);
   }
   void setDxDy(double dx, double dy) {totalSpeed = computeTotalComponent(dx, dy);}
   //void setDirection(Direction direction);
   void setSpeed(double speed) {totalSpeed = speed;}
   void addDx(double dx, Direction angle)
   {
      double currentDx = getDx(angle);
      double currentDy = getDy(angle);
      currentDx += dx;
      setDxDy(currentDx, currentDy);
   }
   void addDy(double dy, Direction angle)
   {
      double currentDx = getDx(angle);
      double currentDy = getDy(angle);
      currentDy += dy;
      setDxDy(currentDx, currentDy);
   }
   void addV(Velocity velocity) {totalSpeed += velocity.getSpeed();}
   //void reverse();


};
