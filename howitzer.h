#pragma once
#include "position.h"
#include "direction.h"
#include "uiDraw.h"
#include "velocity.h"


class Howitzer
{
private:
   Position position;
   double muzzleVelocity;
   Direction elevation;

public:
   void draw(ogstream gout, double flightTime);
   Position getPosition();
   void generatePosition(double size);
   Velocity getMuzzleVelocity();
   void setMuzzleVelocity(Velocity velocity);
   void rotate(double radians);
   void raise(double radians);
};