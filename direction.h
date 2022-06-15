//
//  direction.h
//  Lab07
//
//  Created by Michael LeFevre on 6/15/22.
//

#pragma once
class Direction
{
public:
   Direction() {}
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
   double getDx() {return 0;}
   double getDy() {return 0;}
   
private:
   double radians;
};
