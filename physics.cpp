#include <iostream>  // for CIN and COUT
#include <string>    // for STRING
#include <math.h>    // for SIN, COS, and POW
#include <vector>
#include "physics.h"
using namespace std;

#define WEIGHT 15103.00   // Weight in KG
#define GRAVITY -1.625    // Vertical acceleration due to gravity, in m/s^2
#define THRUST 45000.00   // Thrust of main engine, in Newtons (kg m/s^2)
#ifndef PI
#define PI 3.14159        // PI
#endif





/***************************************************
 * COMPUTE DISTANCE
 * Apply inertia to compute a new position using the distance equation.
 * The equation is:
 *     s = s + v t + 1/2 a t^2
 * INPUT
 *     s : original position, in meters
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     s : new position, in meters
 **************************************************/
float computeDistance(float position, float velocity, float acceleration, float time)
{
   return position + (velocity * time) + (0.5 * acceleration * (time * time));
}

/**************************************************
 * COMPUTE ACCELERATION
 * Find the acceleration given a thrust and mass.
 * This will be done using Newton's second law of motion:
 *     f = m * a
 * INPUT
 *     f : force, in Newtons (kg * m / s^2)
 *     m : mass, in kilograms
 * OUTPUT
 *     a : acceleration, in meters/second^2
 ***************************************************/
float computeAcceleration(float force, float mass)
{
   return force / mass;
}
/***********************************************
 * COMPUTE VELOCITY
 * Starting with a given velocity, find the new
 * velocity once acceleration is applied. This is
 * called the Kinematics equation. The
 * equation is:
 *     v = v + a t
 * INPUT
 *     v : velocity, in meters/second
 *     a : acceleration, in meters/second^2
 *     t : time, in seconds
 * OUTPUT
 *     v : new velocity, in meters/second
 ***********************************************/
float computeVelocity(float velocity, float acceleration, float time)
{
   return velocity + (acceleration * time);
}


/***********************************************
 * COMPUTE VERTICAL COMPONENT
 * Find the vertical component of a velocity or acceleration.
 * The equation is:
 *     cos(a) = y / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     y : the vertical component of the total
 ***********************************************/
float computeVerticalComponent(float angle, float totalVelocity)
{
   return totalVelocity * cos(angle);
}


/***********************************************
 * COMPUTE HORIZONTAL COMPONENT
 * Find the horizontal component of a velocity or acceleration.
 * The equation is:
 *     sin(a) = x / total
 * This can be expressed graphically:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    |a/
 *    |/
 * INPUT
 *     a : angle, in radians
 *     total : total velocity or acceleration
 * OUTPUT
 *     x : the vertical component of the total
 ***********************************************/
double computeHorizontalComponent(double a, double total)
{
   return sin(a) * total;
}

/************************************************
 * COMPUTE TOTAL COMPONENT
 * Given the horizontal and vertical components of
 * something (velocity or acceleration), determine
 * the total component. To do this, use the Pythagorean Theorem:
 *    x^2 + y^2 = t^2
 * where:
 *      x
 *    +-----
 *    |   /
 *  y |  / total
 *    | /
 *    |/
 * INPUT
 *    x : horizontal component
 *    y : vertical component
 * OUTPUT
 *    total : total component
 ***********************************************/
double computeTotalComponent(double x, double y)
{
   return sqrt((x * x) + (y * y));
}


/*************************************************
 * RADIANS FROM DEGEES
 * Convert degrees to radians:
 *     radians / 2pi = degrees / 360
 * INPUT
 *     d : degrees from 0 to 360
 * OUTPUT
 *     r : radians from 0 to 2pi
 **************************************************/
double radiansFromDegrees(double d)
{
   return (d * 2.0 * PI) / 360.0;
}

/******************************************************************************
 * DRAG FORCE EQUATION
 * Finds the force of drag.
 * INPUT:
 *    c : Drag Coefficent
 *    p : Air Density
 *    v : Total Velocity
 *    a : Surface Area
 * OUTPUT
 *    d : Force in Newtons
 ******************************************************************************/
double dragFroceEquation(double c, double p, double v, double a)
{
   return 0.5 * c * p * v * v * a;
}

/******************************************************************************
 * CALCULATE AREA
 * Finds the area of a circle.
 * INPUT:
 *    r : radius
 * OUTPUT:
 *    a : Surface Area
 ******************************************************************************/
double calculateArea(double r)
{
   return PI * r * r;
}

/******************************************************************************
 * ANGLE FROM COMPONENT
 * Gets the angle from two non hypotenuse sides of right triangle.
 * INPUT
 *    x : side1
 *    y: side2
 * OUTPUT
 *    a: angle in radians
 ******************************************************************************/
double angleFromComponent(double x, double y)
{
   return atan2(x, y);
}

/******************************************************************************
 * SOLVE RANGE
 * Formula for linear interpolation solving for range.
 * INPUT
 *    d0: Domain 0
 *    r0: Range 0
 *    d1: Domain 1
 *    r1: Range 1
 *    d: Domain of range being solved for
 * OUTPUT
 *    r: Range solved for
 ******************************************************************************/
double solveRange(double d0, double r0, double d1, double r1, double d)
{
   return ((r1 - r0) / (d1 - d0)) * (d - d0) + r0;
}

/******************************************************************************
 * SOLVE Domain
 * Formula for linear interpolation solving for range.
 * INPUT
 *    d0: Domain 0
 *    r0: Range 0
 *    d1: Domain 1
 *    r1: Range 1
 *    r: Range of domain being solved for
 * OUTPUT
 *    d: Domain solved for
 ******************************************************************************/
double solveDomain(double d0, double r0, double d1, double r1, double r)
{
   return ((d1 - d0) * (r - r0)) / (r1 - r0) + d0;
}

/******************************************************************************
 *
 ******************************************************************************/
double getValueFromTable(vector<Pair> table, double domain)
{
   Pair prevPair = {table.front().domain, table.front().range};
   for (Pair pair : table)
   {
      
      if (pair.domain == domain)
         return pair.range;
      
      if (domain < pair.domain)
      {
         return solveRange(prevPair.domain, prevPair.range, pair.domain, pair.range, domain);
      }
      
      prevPair = pair;
   }
   
   
   return -1;
}

/******************************************************************************
 *
 ******************************************************************************/
double getAirDensity(double alititude)
{
   vector<Pair> airDensityTable = {
      {0,     1.2250000},
      {1000,  1.1120000},
      {2000,  1.0070000},
      {3000,  0.9093000},
      {4000,  0.8194000},
      {5000,  0.7364000},
      {6000,  0.6601000},
      {7000,  0.5900000},
      {8000,  0.5258000},
      {9000,  0.4671000},
      {10000, 0.4135000},
      {15000, 0.1948000},
      {20000, 0.0889100},
      {25000, 0.0400800},
      {40000, 0.0184100},
      {50000, 0.0039960},
      {50000, 0.0010270},
      {60000, 0.0003097},
      {70000, 0.0000828},
      {80000, 0.0000185}
   };
   
   return getValueFromTable(airDensityTable, alititude);
}

/******************************************************************************
 *
 ******************************************************************************/
double getDragCoefficient(double mach)
{
   vector<Pair> dragCoefficientTable = {
      {0.300, 0.1629},
      {0.500, 0.1659},
      {0.700, 0.2031},
      {0.890, 0.2597},
      {0.920, 0.3010},
      {0.960, 0.3287},
      {0.980, 0.4002},
      {1.000, 0.4258},
      {1.020, 0.4335},
      {1.060, 0.4483},
      {1.240, 0.4064},
      {1.530, 0.3663},
      {1.990, 0.2897},
      {2.870, 0.2297},
      {2.890, 0.2306},
      {5.000, 0.2656}
   };
   
   return getValueFromTable(dragCoefficientTable, mach);
}

/******************************************************************************
 *
 ******************************************************************************/
double getSpeedOfSound(double altitude)
{
   vector<Pair> soundSpeedTable = {
      {0,     340},
      {1000,  336},
      {2000,  332},
      {3000,  328},
      {4000,  324},
      {5000,  320},
      {6000,  316},
      {7000,  312},
      {8000,  308},
      {9000,  303},
      {10000, 299},
      {15000, 295},
      {20000, 295},
      {25000, 295},
      {30000, 305},
      {40000, 324}
   };
   
   return getValueFromTable(soundSpeedTable, altitude);
}

double getGravity(double altitude)
{
   vector<Pair> gravityTable = {
      {0,     9.807},
      {1000,  9.804},
      {2000,  9.801},
      {3000,  9.797},
      {4000,  9.794},
      {5000,  9.791},
      {6000,  9.788},
      {7000,  9.785},
      {8000,  9.782},
      {9000,  9.779},
      {10000, 9.776},
      {15000, 9.761},
      {20000, 9.745},
      {25000, 9.730}
   };
   
   return getValueFromTable(gravityTable, altitude);
}

double convertToDegrees(double radians) { return (180.0 * radians) / PI; }
double convertToRadians(double degrees) { return (degrees * 2.0 * PI) / 360.0; }
