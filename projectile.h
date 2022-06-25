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

   // Resets to default values
   void reset()
   {
      flightPath.clear();
      mass = 46.7;
      radius = 0.077445;
   }

   // Fire launches projectile
   void fire(Position pos, double time, Direction angle, Velocity vel)
   {
      PVT pvt;
      pvt.position = pos;
      pvt.velocity = vel;
      pvt.time = time;

      flightPath.push_back(pvt);
   }

   // Advance moves the projetile by the specified time
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

   // Flying cheks if there is a projectile in the air
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
      return flightPath.back().time;
   }

   double getFlightDistance() {return flightPath.back().position.getMetersX(); }

   double getSpeed() {return flightPath.back().velocity.getSpeed(); }

   double getCurrentTime() {return 0;}

   void setMass(double mass) 
   { 
      if (mass >= 0)
         this->mass = mass;
      else
         this->mass = 46.7;
   }

   void setRadius(double radius) 
   {
      if (radius >= 0)
         this->radius = radius;
      else
         this->radius = 0.077445;
   }

   friend class TestProjectile;

private:
   double mass;
   double radius;
   deque<PVT> flightPath;
};
