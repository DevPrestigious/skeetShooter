//
//  flyingObject.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//

#include "flyingObject.h"
#define BULLET_SPEED 10.0
float angle = 30;
float dx = BULLET_SPEED * (-cos(M_PI / 180.0 * angle));
float dy = BULLET_SPEED * (sin(M_PI / 180.0 * angle));

void FlyingObject::advance()
{
      point.addX(BULLET_SPEED * (-cos(M_PI / 180.0 * angle)));
      point.addY(BULLET_SPEED * (sin(M_PI / 180.0 * angle)));
}
