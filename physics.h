//
//  physics.h
//  Lab03
//
//  Created by Michael LeFevre on 5/26/22.
//
#pragma once
#include <vector>
#include <math.h>

using namespace std;

struct Pair
{
   double domain;
   double range;
};

/******************************************************************************
 * Collection of Physics Equations 
 ******************************************************************************/
float computeDistance(float position, float velocity, float acceleration, float time);
float computeAcceleration(float force, float mass);
float computeVelocity(float velocity, float acceleration, float time);
float computeVerticalComponent(float angle, float totalVelocity);
double computeHorizontalComponent(double a, double total);
double computeTotalComponent(double x, double y);
double radiansFromDegrees(double d);
double dragFroceEquation(double c, double p, double v, double a);
double calculateArea(double r);
double angleFromComponent(double x, double y);
double solveRange(double d0, double r0, double d1, double r1, double d);
double solveDomain(double d0, double r0, double d1, double r1, double r);
double getValueFromTable(vector<Pair> table, double domain);
double getAirDensity(double alititude);
double getDragCoefficient(double mach);
double getSpeedOfSound(double altitude);
double getGravity(double altitude);
double convertToDegrees(double radians);
double convertToRadians(double degrees);
