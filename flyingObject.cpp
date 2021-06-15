//
//  flyingObject.cpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//

#include "flyingObject.h"

void FlyingObject::advance()
{
      point.addX(velocity.getDx());
      point.addY(velocity.getDy());
}
