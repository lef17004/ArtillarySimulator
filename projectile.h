//
//  projectile.h
//  Lab07
//
//  Created by Michael LeFevre on 6/15/22.
//

#pragma once
#include <array>
#include "position.h"
#include "direction.h"
#include "velocity.h"
using namespace std;

struct PVT
{
   Position pos;
   Velocity vol;
   double time;
};

class Projectile
{
public:
   Projectile() {}
   void reset() {}
   void fire(Position pos, double time, Direction angle, Velocity vel)
   {
      PVT pvt;
   }
   void advance(double time) {}
   void draw() {}
   bool flying() {return false;}
   double getAltitude() {return 0;}
   Position getPosition() {return flightPath[0];}
   double getFlightTime() {return 0;}
   double getFlightDistance() {return 0;}
   double getSpeed() {return 0;}
   double getCurrentTime() {return 0;}
   void setMass(double mass) {}
   void setRadius(double radius) {}
   
private:
   double mass;
   double radius;
   array<Position, 20> flightPath;
};
