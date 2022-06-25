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
      double area = calculateArea(radius);
      PVT previousPVT = flightPath.back();
      Velocity prevVelocity = previousPVT.velocity;
      Position prevPosition = previousPVT.position;
      double altitude = previousPVT.position.getMetersY();
      double airDenisty = getAirDensity(altitude);
      double soundSpeed = getSpeedOfSound(altitude);
      double mach = prevVelocity.getSpeed() / soundSpeed;
      double dragCo = getDragCoefficient(mach);
      double dragForce = dragFroceEquation(dragCo, airDenisty, prevVelocity.getSpeed(), area);
      double gravity = -getGravity(altitude);
      
      double totalAcceleration = computeAcceleration(dragForce, mass);
      double ddx = -computeHorizontalComponent(prevVelocity.getAngle(), totalAcceleration);
      double ddy = gravity - computeVerticalComponent(prevVelocity.getAngle(), totalAcceleration);
      
      double newX = computeDistance(prevPosition.getMetersX(), prevVelocity.getDx(), ddx, time);
      double newY = computeDistance(prevPosition.getMetersY(), prevVelocity.getDy(), ddy, time);
      
      double newDx = computeVelocity(prevVelocity.getDx(), ddx, time);
      double newDy = computeVelocity(prevVelocity.getDy(), ddy, time);
      
      PVT newPVT;
      Velocity newVelocity;
      Position newPosition;
      //Direction newDirection;
      
      newPosition.setMeters(newX, newY);
      newVelocity.setDxDy(newDx, newDy);
      double newTime = previousPVT.time + time;
      newPVT.position = newPosition;
      newPVT.velocity = newVelocity;
      newPVT.time = newTime;
      
      flightPath.push_back(newPVT);
      if (flightPath.size() > 10)
         flightPath.pop_front();
      
   }
   void draw() {}
   bool flying()
   {
      if (flightPath.size())
         return true;
      return false;
   }
   double getAltitude() 
   {
      return flightPath.back().position.getMetersY();
   }
   Position getPosition() {return flightPath.back().position;}
   double getFlightTime() 
   {
      flightPath.back().time;
   }
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
