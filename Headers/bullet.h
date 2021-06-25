//
//  bullet.hpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/14/21.
//

#ifndef bullet_h
#define bullet_h
#include "flyingObject.h"
#include "rifle.h"
#include <cmath> // used for sin, cos, and M_PI



class Bullet : public FlyingObject
{
protected:
   



public:
   Bullet()
   {
      
      point = Point(200,-200);
      velocity = Velocity();
      isAlive();
      
   }
   
   //finish draw functions using uiRectangle and circle., and advance.
   void draw();
   
   
   
   
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
   
   void kill()
   {
      FlyingObject::kill();
   };
   
   void fire(Point point, float angle);

   
   void advance()
   {
      FlyingObject::advance();
   }
   
   
};
   
#endif /* bullet_hpp */
