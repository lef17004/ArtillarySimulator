//
//  status.h
//  Lab07
//
//  Created by Michael LeFevre on 6/23/22.
//
#include <memory>
#include "projectile.h"
#include "howitzer.h"
using namespace std;
#pragma once
class Status
{
public:
   
private:
   unique_ptr<Projectile> observedProjectile;
   unique_ptr<Howitzer> observedHowitzer;
};
