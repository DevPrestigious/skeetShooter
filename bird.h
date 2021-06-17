//
//  bird.hpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//
#include "flyingObject.h"
#ifndef bird_hpp
#define bird_hpp

class Bird : public FlyingObject
{
private:
   int points;
   
public:
   
   void draw()
   {
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
      return points;
   };
   
   void kill()
   {
      FlyingObject::kill();
   };
   
};


#endif
