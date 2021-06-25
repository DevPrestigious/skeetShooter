//
//  toughBird.hpp
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/21/21.
//

#ifndef toughBird_hpp
#define toughBird_hpp
#include "bird.h"


class ToughBird : public Bird
{
protected:
   
public:
   
   
   ToughBird()
   {
      life = 3;
      point = Point(-204,random(-200,200));
      isAlive();
      velocity = Velocity(random(2,5),tVelY(startY));
      points = 1;
   }
   
   void draw() override
   {
      drawToughBird(getPoint(), 15, life);
   }
   
};



#endif /* toughBird_hpp */
