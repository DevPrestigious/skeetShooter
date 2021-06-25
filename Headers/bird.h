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
   // Constructor for bird, -1 because it helps handle the semi-poorly written but functioning
   // score function.
   Bird()
   {
      life = 1;
      point = Point(-200,random(-200, 200));
      isAlive();
      velocity = Velocity(random(3,7),velY(startY));
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
