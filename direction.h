//
//  direction.h
//  Lab07
//
//  Created by Michael LeFevre on 6/15/22.
//

#pragma once
#include <cmath>
class TestDirection;

class Direction
{
public:
   Direction() {}
   Direction(double degrees)
   {
      setDegrees(degrees);
   }
   void operator = (Direction rhs) {}
   void setRadians(double radians) {}
   void setDegrees(double degrees) {}
   void setDxDy(double dx, double dy) {}
   void setDown() {}
   void setUp() {}
   void setRight() {}
   void setLeft() {}
   void reverse() {}
   double getRadians() {return 0;}
   double getDegrees() {return 0;}
   
   friend class TestDirection;
private:
   double radians;
   
   double normalize(double value)
   {
      double normalizedRadianValue = value - (2.0 * M_PI * floor(value / (2.0 * M_PI)));
      return normalizedRadianValue;
   }
};
