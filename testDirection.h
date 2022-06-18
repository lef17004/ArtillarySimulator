//
//  testDirection.h
//  Lab07
//
//  Created by Michael LeFevre on 6/15/22.
//
#include "direction.h"
#include <math.h>
#include <cassert>
#pragma once

class TestDirection
{
public:
   void run()
   {
      defaultConstructor();
      assignmentOperator();
      SetDegreesNormal();
      SetDegreesHigh();
      SetDegreesLow();
      setRadians();
      setRadiansHigh();
      setRadiansLow();
      setDxDy();
      setDown();
      setUp();
      setLeft();
      setRight();
      reverse();
      reverseWhenZero();
      getRadians();
      getDegrees();
   }
   
private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }
   
   // Tests default contructor
   void defaultConstructor()
   {
      // Setup and Exercise
      Direction direction;
      
      // Verify
      assert(direction.radians == 0);
      // Teardown
   }
   
   // Test assignment operator makes copy
   void assignmentOperator()
   {
      // Setup
      Direction direction1;
      Direction direction2;
      direction1.radians = 0;
      direction2.radians = M_PI;
      
      // Exercise
      direction1 = direction2;
      
      // Verify
      assert(direction1.radians == M_PI);
   }
   
   // Tests setting degrees to 90
   void SetDegreesNormal()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDegrees(90);
      
      // Verify
      assert(direction.radians == M_PI / 2);
   }
   
   // Tests setting degrees to a number greater than 360
   void SetDegreesHigh()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDegrees(540.0);
      
      // Verify
      assert(direction.radians == M_PI);
   }
   
   // Tests setting degrees to a number below 0
   void SetDegreesLow()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDegrees(-180.0);
      
      // Verify
      assert(direction.radians == M_PI);
   }
   
   // Tests setting radians to pi
   void setRadians()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setRadians(M_PI);
      
      // Verify
      assert(direction.radians = M_PI);
   }
   
   // Tests setting radians to a value greater than 2pi.
   void setRadiansHigh()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setRadians(3 * M_PI);
      
      // Verify
      assert(direction.radians = M_PI);
   }
   
   // Tests setting radians to a value lower than 0.
   void setRadiansLow()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setRadians(-M_PI);
      
      // Verify
      assert(direction.radians = M_PI);
   }
   
   // Tests setting angle with dx and dy
   void setDxDy()
   {
      // Setup
      double dx = 3.0;
      double dy = 4.0;
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDxDy(dx, dy);
      
      // Verify
      assert(closeEnough(direction.radians, 0.6435, 0.001));
   }
   
   // Test setting angle down
   void setDown()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDown();
      
      // Verify
      assert(direction.radians == M_PI);
   }
   
   // Tests setting angle up
   void setUp()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDown();
      
      // Verify
      assert(direction.radians == 0);
   }
   
   // Tests setting angle to the left
   void setLeft()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setLeft();
      
      // Verify
      assert(direction.radians == M_PI / 2);
   }
   
   // Tests setting angle to the right
   void setRight()
   {
      // Setup
      Direction direction;
      direction.radians = M_PI;
      
      // Exercise
      direction.setRight();
      
      // Verify
      assert(direction.radians == 3 * M_PI / 2);
   }
   
   // Tests reversing the direction of the angle
   void reverse()
   {
      // Setup
      Direction direction;
      direction.radians = M_PI;
      
      // Exercise
      direction.reverse();
      
      // Verify
      closeEnough(direction.radians, 0, 0.001);
      assert(direction.radians == 0);
   }
   
   // Makes sure angle reverses corectly when 0.
   void reverseWhenZero()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.reverse();
      
      // Verify
      closeEnough(direction.radians, M_PI, 0.001);
      assert(direction.radians == 0);
   }
   
   // Tests getting radians
   void getRadians()
   {
      // Setup
      Direction direction;
      direction.radians = M_PI;
      
      // Exercise
      double radians = direction.getRadians();
      
      // Verify
      assert(radians == M_PI);
   }
   
   // Tests getting degrees
   void getDegrees()
   {
      // Setup
      Direction direction;
      direction.radians = M_PI;
      
      // Exercise
      double degrees = direction.getDegrees();
      
      // Verify
      assert(closeEnough(degrees, 180.0, 0.001));
   }
};
