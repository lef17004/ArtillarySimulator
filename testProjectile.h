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
      defaultConstrucotr();
      reset();
      fire();
      advance();
      flying_false();
      flying_true();
      getAltitude();
      getPosition();
      getFlightTime();
      getFlightDistnace();
      getSpeed();
      setMass();
      setRadius();
   }

private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   void defaultConstrucotr()
   {
      // set up and exersice
      Projectile projectile;
      // verify
      assert(closeEnough(projectile.mass,46.7,0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      assert(projectile.flightPath.size() == 0);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));


   }

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


   }

   void fire()
   {
      // set up
      Projectile projectile;
      Position position(0, 0);
      double time = 1.0;
      Direction direction;
      direction.setRadians(0.5);
      Velocity velocity(1, 5);
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

      assert(projectile.flightPath.size() == 0);

   }

   void advance()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(0, 0);
      Velocity velocity;
      velocity.setSpeed(827.0);
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exersice
      projectile.advance(time);
      // verify
      assert(projectile.flightPath[0].position.getMetersX() == 0);
      assert(projectile.flightPath[0].position.getMetersY() == 0);
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827, 0.001));
      assert(closeEnough(projectile.flightPath[0].time, 0, 0.001));

      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15964, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(closeEnough(projectile.flightPath[1].time, 0.01, 0.001));

      assert(projectile.flightPath.size() == 2);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));

   }
   
   // Advance When Deque has 10 items on it. When looking at the demo, only 10 colored in pixels can be seen despite the array
   // holding 20. When Deque gets bigger than 10, pop of the front.
   void advance2()
   {
      // set up
      Projectile projectile;
      double time = 0;
      Position position(0, 0);
      Velocity velocity;
      velocity.setSpeed(827.0);
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exersice
      projectile.advance(time);
      // verify
      assert(projectile.flightPath[0].position.getMetersX() == 0);
      assert(projectile.flightPath[0].position.getMetersY() == 0);
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827, 0.001));
      assert(closeEnough(projectile.flightPath[0].time, 0, 0.001));
      
      assert(closeEnough(projectile.flightPath[1].position.getMetersX(), 4.1339, 0.001));
      assert(closeEnough(projectile.flightPath[1].position.getMetersY(), 7.15964, 0.001));
      assert(closeEnough(projectile.flightPath[1].velocity.getSpeed(), 826.476, 0.001));
      assert(closeEnough(projectile.flightPath[1].time, 0.01, 0.001));
      
      assert(projectile.flightPath.size() == 2);
      
      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
   }

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


   }

   void flying_true()
   {
      //set up 
      Projectile projectile;
      double time = 0;
      Position position(0, 0);
      Velocity velocity;
      velocity.setSpeed(827.0);
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

   }

   void getAltitude()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(0, 42);
      Velocity velocity;
      velocity.setSpeed(827.0);
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
   }

   void getPosition()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(2, 9);
      Velocity velocity;
      velocity.setSpeed(827.0);
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exercise
      Position position = projectile.getPosition();
      double dx = position.getMetersX();
      double dy = position.getMetersY();
      // verify
      assert(dx == 2);
      assert(dy == 9);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
   }

   void getFlightTime()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(2, 9);
      Velocity velocity;
      velocity.setSpeed(827.0);
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // excercise
      double time = projectile.getFlightTime();
      // verify
      assert(time == 0);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
      
   }

   void getFlightDistnace()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(20, 13);
      Velocity velocity;
      velocity.setSpeed(827.0);
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // excersie
      double distance = projectile.getFlightDistance();
      // verify
      assert(distance == 20);
   }

   void getSpeed()
   {
      // set up 
      Projectile projectile;
      double time = 0;
      Position position(12, 19);
      Velocity velocity;
      velocity.setSpeed(827.0);
      PVT firstProjectile;
      firstProjectile.position = position;
      firstProjectile.velocity = velocity;
      firstProjectile.time = time;
      projectile.flightPath.push_back(firstProjectile);
      // exersice
      double speed = projectile.getSpeed();
      // verify
      assert(projectile.flightPath[0].position.getMetersX() == 0);
      assert(projectile.flightPath[0].position.getMetersY() == 0);
      assert(closeEnough(projectile.flightPath[0].velocity.getSpeed(), 827, 0.001));
      assert(closeEnough(projectile.flightPath[0].time, 0, 0.001));
      assert(speed == 827);
      assert(projectile.flightPath.size() == 1);

      assert(closeEnough(projectile.mass, 46.7, 0.001));
      assert(closeEnough(projectile.radius, 0.077445, 0.001));
   }

   void setMass()
   {
      // set up
      Projectile projectile;
      projectile.mass = -1;
      // exercise
      projectile.setMass(40);
      // verify
      assert(projectile.mass == 40);
   }

   void setRadius()
   {
      // set up
      Projectile projectile;
      projectile.radius = -1;
      // exercise
      projectile.setRadius(3);
      // verify
      assert(projectile.mass == 3);
   }



   PVT makePVT(double x, double y, double dx, double dy, double time)
   {
      
   }


};
