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

class TestProjectile;

struct PVT
{
   Position position;
   Velocity velocity;
   double time; 
};

class Projectile
{
public:
   Projectile() {}
   void reset() {}
   void fire(Position pos, double time, Direction angle, Velocity vel) {}
   void advance(double time) {}
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
   friend TestProjectile;
   
private:
   double mass;
   double radius;
   deque<PVT> flightPath;
};
