//
//  direction.h
//  Lab07
//
//  Created by Michael LeFevre on 6/15/22.
//

#pragma once
#include <math.h>
#include "physics.h"
#define M_PI 3.14159
class TestDirection;

class Direction
{
public:
   Direction(): radians(0) {}
   Direction(double degrees)
   {
      setDegrees(degrees);
   }
  // Direction(Direction &rhs)
   //{
    //  radians = rhs.radians;
   //}
   void operator = (Direction &rhs)
   {
      radians = rhs.radians;
   }
   void setRadians(double radians) { this->radians = normalize(radians); }
   void setDegrees(double degrees) { this->radians = normalize(convertToRadians(degrees)); }
   void setDxDy(double dx, double dy) { radians = normalize(angleFromComponent(dx, dy)); }
   void setDown() { radians = M_PI; }
   void setUp() { radians = 0; }
   void setRight() { radians = 3 * M_PI / 2; }
   void setLeft() { radians = M_PI / 2; }
   void reverse()
   {
      if (radians == 0)
         radians = M_PI;
      
      if (radians == M_PI)
         radians = 0;
      
      radians = normalize(-radians);
   }
   double getRadians() {return radians;}
   double getDegrees() {return convertToDegrees(radians);}
   
   friend class TestDirection;
private:
   double radians;
   
   double normalize(double value)
   {
      double normalizedRadianValue = value - (2.0 * M_PI * floor(value / (2.0 * M_PI)));
      return normalizedRadianValue;
   }
};
