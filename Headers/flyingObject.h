//
//  flyingObject.h
//  flyingObject
//
//  Created by Alexander Dohms on 6/14/21.
//

#ifndef FLYING_OBJECT_H
#define FLYING_OBJECT_H

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"
#include "rifle.h"


class FlyingObject
{
protected:
   Point point;
   Velocity velocity;
   bool alive;

public:
   FlyingObject() { alive = true; }
   virtual ~FlyingObject() { }

   Point getPoint() const { return point; }
   
   Velocity getVelocity() const { return velocity; }

   void setAlive(bool alive) { this->alive = alive; }
   virtual bool isAlive() const { return alive; }
   
   void setPoint(const Point & point) { this->point = point; }
   void setVelocity(const Velocity & velocity) { this->velocity = velocity ;}
   void kill() { alive = false;}
   
   virtual void advance();
   virtual void draw() = 0;


};

#endif
