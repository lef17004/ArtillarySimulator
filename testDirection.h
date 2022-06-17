//
//  testDirection.h
//  Lab07
//
//  Created by Michael LeFevre on 6/15/22.
//
#include "direction.h"
#include <math.h>
#pragma once

/*
 Direction
 assign
 setRadians
 setDegrees
 SetDxDy
 SetDown
 setUp
 setRight
 setLeft
 reverse
 getRadians
 getDegrees
 getDx
 getDy
 */


class TestDirection
{
public:
   void run()
   {
      defaultConstructor();
      assignmentOperator();
      setDegrees();
   }
   
private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }
   
   void defaultConstructor()
   {
      // Setup and Exercise
      Direction direction;
      
      // Verify
      assert(direction.radians == M_PI / 2);
      // Teardown
   }
   
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
   
   void setDegrees()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDegrees(90);
      
      // Verify
      assert(direction.radians == M_PI);
   }
   
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
   
   void setDown()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDown();
      
      // Verify
      assert(direction.radians == 3 * M_PI / 2);
   }
   
   void setUp()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setDown();
      
      // Verify
      assert(direction.radians == M_PI / 2);
   }
   
   void setLeft()
   {
      // Setup
      Direction direction;
      direction.radians = 0;
      
      // Exercise
      direction.setLeft();
      
      // Verify
      assert(direction.radians == M_PI);
   }
   
   void setRight()
   {
      // Setup
      Direction direction;
      direction.radians = M_PI;
      
      // Exercise
      direction.setRight();
      
      // Verify
      assert(direction.radians == 0);
   }
   
   void reverse()
   {
      
   }
   
   void getRadians()
   {
      
   }
   
   void getDegrees()
   {
      
   }
   
   void getDx()
   {
      
   }
   
   void getDy()
   {
      
   }
};
