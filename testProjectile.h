#pragma once
#include "projectile.h"
#include <cassert>
#include "position.h"
#include "direction.h"
#include "velocity.h"

class TestProjectile
{
public:
   void run()
   {
      defaultConstructor();
      reset();
      fire();
      advance();
      advanceWhen10ItemsInDeque();
      flying_false();
      flying_true();
      getAltitude();
      getAltitudeWhenMultipleThingsInFlightPath();
      getPosition();
      getPositionWhenMultipleThingsInFlightPath();
      getFlightTime();
      getFlightTimeWhenMultipleThingsInFlightPath();
      getFlightDistnace();
      getFlightDistanceWhenMultipleThingsInFlightPath();
      getSpeed();
      getSpeedWhenMultipleThingsInFlightPath();
      setMass();
      setRadius();
      setMassBelowZero();
      setRadiusBelowZero();
   }

private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   // Test Default Constructor
   void defaultConstructor()
   {
      // set up and exersice
      Projectile projectile;
      // verify
      assert(closeEnough(projectile.mass,46.7,0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      assert(projectile.flightPath.size() == 0);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));

      // Teardown
   }

   // Make sure values reset to default values
   void reset()
   {
      // set up and exersice
      Projectile projectile;
      projectile.reset();
      // verify
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      assert(projectile.flightPath.size() == 0);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      // Teardown

   }

   // Projectile is set to correct values when fire is called
   void fire()
   {
      // set up
      Projectile projectile;
      Position position(0, 0);
      double time = 1.0;
      Direction direction;
      direction.setRadians(0.5);
      Velocity velocity;
      velocity.setDxDy(1, 5);
      // excersie
      projectile.fire(position, time, direction, velocity);
      // verify
      assert(projectile.flightPath.size() == 1);
      assert(projectile.flightPath[0].position.getMetersX() == 0);
      assert(projectile.flightPath[0].position.getMetersY() == 0);
      assert(projectile.flightPath[0].velocity.getDx() == 1);
      assert(projectile.flightPath[0].velocity.getDy() == 5);
      assert(projectile.flightPath[0].time == 1);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
     
      // Teardown
   }

   // Projectile is advanced by one frame
   void advance()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(0, 0);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exersice
      projectile.advance(0.01);
      // verify
      assert(projectile.flightPath[0].position.getMetersX() == 0);
      assert(projectile.flightPath[0].position.getMetersY() == 0);
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827, 0.001));
      assert(closeEnough(projectile.flightPath[0].time, 0, 0));

      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15964, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(closeEnough(projectile.flightPath[1].time, 0.01, 0.01));

      assert(projectile.flightPath.size() == 2);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      // Teardown
   }
   
   // Advance when Deque has 10 items on it. When looking at the demo, only 10 colored in pixels can be seen despite the array
   // holding 20. When Deque gets bigger than 10, pop off the front.
   void advanceWhen10ItemsInDeque()
   {
      // set up
      Projectile projectile;
      PVT pvtZero = makePVT(0, 0, 827.0, 0.0, Direction(30));
      PVT pvtOne  = makePVT(4.1339, 7.15964, 826.476, 0.01, Direction(30.0034));
      PVT pvtTwo = makePVT(8.26561, 14.3145, 825.953, 0.02, Direction(30.0068));
      PVT pvtThree = makePVT(12.3951, 21.4646, 825.431, 0.03, Direction(30.0102));
      PVT pvtFour = makePVT(16.5225, 28.6099, 824.91, 0.04, Direction(30.0136));
      PVT pvtFive = makePVT(20.6476, 35.7505, 824.389, 0.05, Direction(30.017));
      PVT pvtSix = makePVT(24.7706, 42.8863, 823.869, 0.06, Direction(30.0204));
      PVT pvtSeven = makePVT(28.8914, 50.0174, 823.349, 0.07, Direction(30.0238));
      PVT pvtEight = makePVT(33.01, 57.1437, 822.831, 0.08, Direction(30.0273));
      PVT pvtNine = makePVT(37.1265, 64.2653, 822.313, 0.09, Direction(30.0307));
      //PVT pvtTen = makePVT(41.2408, 71.3822, 821.795, 0.1, Direction(30.0341));
      
      projectile.flightPath.push_back(pvtZero);
      projectile.flightPath.push_back(pvtOne);
      projectile.flightPath.push_back(pvtTwo);
      projectile.flightPath.push_back(pvtThree);
      projectile.flightPath.push_back(pvtFour);
      projectile.flightPath.push_back(pvtFive);
      projectile.flightPath.push_back(pvtSix);
      projectile.flightPath.push_back(pvtSeven);
      projectile.flightPath.push_back(pvtEight);
      projectile.flightPath.push_back(pvtNine);
      //projectile.flightPath.push_back(pvtTen);
      
      // exersice
      projectile.advance(0.01);
      // verify
      
      //Make sure new PVT was added to end of flight path
      assert(closeEnough(projectile.flightPath[9].position.getMetersX(), 41.2408, 0.001));
      assert(closeEnough(projectile.flightPath[9].position.getMetersY(), 71.3822, 0.001));
      assert(closeEnough(projectile.flightPath[9].velocity.getSpeed(), 821.795, 0.001));
      assert(closeEnough(projectile.flightPath[9].time, 0.1, 0.001));
      
      
      // Make sure the correct PVT is at the front
      assert(closeEnough(projectile.flightPath[0].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[0].position.getMetersY(), 7.15956, 0.001));
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 826.476, 0.001));
      assert(projectile.flightPath[0].time == 0.01);
      
      assert(projectile.flightPath.size() == 10);
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      // Teardown
   }

   // Returns false when not flying.
   void flying_false()
   {
      //set up
      Projectile projectile;
      // excerise
      bool isFlying = projectile.flying();
      // verify
      assert(!isFlying);
      assert(projectile.flightPath.size() == 0);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));

      assert(projectile.flightPath.size() == 0);

      // Teardown
   }

   // Return true when flying.
   void flying_true()
   {
      //set up 
      Projectile projectile;
      double time = 0;
      Position position(0, 0);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // excerise
      bool isFlying = projectile.flying();
      // verify
      assert(isFlying);
      assert(projectile.flightPath.size() == 1);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));

      assert(projectile.flightPath.size() == 1);
      // Teardown
   }

   // Gets correct altitude
   void getAltitude()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(0, 42);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // excersise
      double alitude = projectile.getAltitude();
      // verify
      assert(alitude == 42);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      assert(projectile.flightPath.size() == 1);
      // Teardown
   }
   
   // Get alititude when multiple things in flight path
   void getAltitudeWhenMultipleThingsInFlightPath()
   {
      // Setup
      Projectile projectile;
      PVT pvtOne = makePVT(0, 0, 827.0, 0.0, Direction(30));
      PVT pvtTwo = makePVT(4.1339, 7.15964, 826.476, 0.01, Direction(30.0034));
      projectile.flightPath.push_back(pvtOne);
      projectile.flightPath.push_back(pvtTwo);
      
      // Exercise
      double altitude = projectile.getAltitude();
      
      // Verify
      assert(closeEnough(altitude, 7.15956, 0.001));
      assert(projectile.flightPath.size() == 2);
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
      
      assert(closeEnough(projectile.flightPath[0].position.getMetersX(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].position.getMetersY(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827.0, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      
      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15956, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      // Teardown
   }

   // Gets position of projectile
   void getPosition()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(2, 9);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exercise
      Position testPosition = projectile.getPosition();
      double dx = testPosition.getMetersX();
      double dy = testPosition.getMetersY();
      // verify
      assert(dx == 2);
      assert(dy == 9);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      // Teardown
   }
   
   // Get position when multiple things in flight path
   void getPositionWhenMultipleThingsInFlightPath()
   {
      // Setup
      Projectile projectile;
      PVT pvtOne = makePVT(0, 0, 827.0, 0.0, Direction(30));
      PVT pvtTwo = makePVT(4.1339, 7.15964, 826.476, 0.01, Direction(30.0034));
      projectile.flightPath.push_back(pvtOne);
      projectile.flightPath.push_back(pvtTwo);
      
      // Exercise
      Position position = projectile.getPosition();
      
      // Verify
      assert(closeEnough(position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(position.getMetersY(), 7.15964, 0.001));
      assert(projectile.flightPath.size() == 2);
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
      
      assert(closeEnough(projectile.flightPath[0].position.getMetersX(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].position.getMetersY(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827.0, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      
      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15956, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      // Teardown
   }

   // Gets flight time and makes sure it's correct.
   void getFlightTime()
   {
      // set up 
      Projectile projectile;
      double time = 5;
      Position position(2, 9);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // excercise
      double testTime = projectile.getFlightTime();
      // verify
      assert(testTime == 5);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      // Teardown
   }
   
   // Get flight time when multiple things in flight path
   void getFlightTimeWhenMultipleThingsInFlightPath()
   {
      // Setup
      Projectile projectile;
      PVT pvtOne = makePVT(0, 0, 827.0, 0.0, Direction(30));
      PVT pvtTwo = makePVT(4.1339, 7.15964, 826.476, 0.01, Direction(30.0034));
      projectile.flightPath.push_back(pvtOne);
      projectile.flightPath.push_back(pvtTwo);
      
      // Exercise
      double flightTime = projectile.getFlightTime();
      
      // Verify
      assert(closeEnough(flightTime, 0.01, 0.001));
      assert(projectile.flightPath.size() == 2);
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
      
      assert(closeEnough(projectile.flightPath[0].position.getMetersX(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].position.getMetersY(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827.0, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      
      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15956, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      // Teardown
   }

   // Makes sure flight distance is correct.
   void getFlightDistnace()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(20, 13);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // excersie
      double distance = projectile.getFlightDistance();
      // verify
      assert(distance == 20);
      // Teardown
   }
   
   // Get flight distance when multiple things in flight path
   void getFlightDistanceWhenMultipleThingsInFlightPath()
   {
      // Setup
      Projectile projectile;
      PVT pvtOne = makePVT(0, 0, 827.0, 0.0, Direction(30));
      PVT pvtTwo = makePVT(4.1339, 7.15964, 826.476, 0.01, Direction(30.0034));
      projectile.flightPath.push_back(pvtOne);
      projectile.flightPath.push_back(pvtTwo);
      
      // Exercise
      double flightDistance = projectile.getFlightDistance();
      
      // Verify
      assert(closeEnough(flightDistance, 4.1339, 0.001));
      assert(projectile.flightPath.size() == 2);
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
      
      assert(closeEnough(projectile.flightPath[0].position.getMetersX(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].position.getMetersY(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827.0, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      
      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15956, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      // Teardown
   }

   // Makes sure speed from projectile is correct
   void getSpeed()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(12, 19);
      Velocity velocity;
      velocity.setSpeed(827.0, Direction(30));
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exersice
      double speed = projectile.getSpeed();
      // verify
      assert(projectile.flightPath[0].position.getMetersX() == 12);
      assert(projectile.flightPath[0].position.getMetersY() == 19);
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827, 0.001));
      assert(closeEnough(projectile.flightPath[0].time, 0, 0.001));
      assert(closeEnough(speed, 827, 0.001));
      assert(projectile.flightPath.size() == 1);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      // Teardown
   }
   
   // Test to make sure it is getting speed from the right part of flight path
   void getSpeedWhenMultipleThingsInFlightPath()
   {
      // Setup
      Projectile projectile;
      PVT pvtOne = makePVT(0, 0, 827.0, 0.0, Direction(30));
      PVT pvtTwo = makePVT(4.1339, 7.15964, 826.476, 0.01, Direction(30));
      projectile.flightPath.push_back(pvtOne);
      projectile.flightPath.push_back(pvtTwo);
      
      // Exercise
      double totalSpeed = projectile.getSpeed();
      
      // Verify
      assert(closeEnough(totalSpeed, 826.476, 0.001));
      assert(projectile.flightPath.size() == 2);
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
      
      assert(closeEnough(projectile.flightPath[0].position.getMetersX(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].position.getMetersY(), 0, 0.001));
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827.0, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      
      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15956, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(projectile.flightPath[1].time == 0.01);
      // Teardown
   }

   // Makes sure mass is set correctly
   void setMass()
   {
      // set up
      Projectile projectile;
      projectile.mass = -1;
      // exercise
      projectile.setMass(40);
      // verify
      assert(projectile.mass == 40);
      // Teardown
   }
   
   // Test that mass becomes default if set below 0.
   void setMassBelowZero()
   {
      // set up
      Projectile projectile;
      projectile.mass = 10;
      // exercise
      projectile.setMass(-10);
      // verify
      assert(projectile.mass == 46.7);
      // Teardown
   }

   // Tests that radius is set correctly
   void setRadius()
   {
      // set up
      Projectile projectile;
      projectile.radius = -1;
      // exercise
      projectile.setRadius(3);
      // verify
      assert(projectile.radius == 3);
      // Teardown
   }
   
   // Check if radius is set out of range that it becomes default value.
   void setRadiusBelowZero()
   {
      // set up
      Projectile projectile;
      projectile.radius = 1;
      // exercise
      projectile.setRadius(-5);
      // verify
      assert(projectile.radius == 0.077445);
      // Teardown
   }


   // Shortcut to make parts of flight path
   PVT makePVT(double x, double y, double totalVelocity, double time, Direction angle)
   {
      PVT newPVT;
      newPVT.position = Position(x, y);
      newPVT.velocity = Velocity(totalVelocity, angle);
      newPVT.time = time;
      return newPVT;
   }


};
