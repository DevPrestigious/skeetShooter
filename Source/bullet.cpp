//
//  bullet.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//

#include "bullet.h"
#define BULLET_SPEED 10.0

void Bullet::draw()
{
   drawDot(Bullet::getPoint());
}

void Bullet::fire(Point point, float angle)
{
   this->angle = angle;
   this->point = point;
};
