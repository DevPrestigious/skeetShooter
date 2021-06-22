//
//  bird.h
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//
#include "flyingObject.h"
#include "uiDraw.h"
#include "toughBird.h"
#include "sacredBird.h"
#ifndef bird_hpp
#define bird_hpp

class Bird : public FlyingObject
{
protected:
   int points;
   int life;
public:
   
   Bird()
   {
      life = 1;
      point = Point(0,0);
      isAlive();
      velocity = Velocity(1,1);
      points = -1;
   }
   
   virtual void draw()
   {
      drawCircle(getPoint(), 15);
   };
   
   Point getPoint()
   {
      return FlyingObject::getPoint();
   };
   
   Velocity getVelocity()
   {
      return FlyingObject::getVelocity();
   };
   
   bool isAlive()
   {
      return FlyingObject::isAlive();
      
   };
   
   void setPoint(const Point & point)
   {
      FlyingObject::setPoint(point);
   };
   
   void setVelocity(const Velocity & velocity)
   {
      FlyingObject::setVelocity(velocity);
   };
   
   int hit()
   {
      if (life > 1)
      {
         --life;
      }
      else if (life == 1)
      {
         kill();
         return points + 2;
      }
      return points;
      
      
};
   
   void kill()
   {
      FlyingObject::kill();
   };
   
   void advance()
   {
      point.addX(velocity.getDx());
      point.addY(velocity.getDy());
   }
   
};


#endif
