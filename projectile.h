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
#include <deque>
using namespace std;

struct PVT
{
   Position position;
   Velocity velocity;
   double time;
};

class TestProjectile;

class Projectile
{
public:
   Projectile() 
   {
      mass = 46.7;
      radius = 0.077445;

   }
   void reset()
   {
      flightPath.clear();
      mass = 46.7;
      radius = 0.077445;
   }
   void fire(Position pos, double time, Direction angle, Velocity vel)
   {
      PVT pvt;
      pvt.position = pos;
      pvt.velocity = vel;
      pvt.time = time;

      flightPath.push_back(pvt);
   }
   void advance(double time) 
   {

   }
   void draw() {}
   bool flying() {return false;}
   double getAltitude() {return 0;}
   Position getPosition() {return flightPath[0].position;}
   double getFlightTime() {return 0;}
   double getFlightDistance() {return 0;}
   double getSpeed() {return 0;}
   double getCurrentTime() {return 0;}
   void setMass(double mass) {}
   void setRadius(double radius) {}
   friend class TestProjectile;
private:
   double mass;
   double radius;
   deque<PVT> flightPath;
};
