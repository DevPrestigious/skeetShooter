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
      point = Point(0,0);
      isAlive();
      velocity = Velocity(1,1);
      points = 1;
   }
   
   void draw() override
   {
      drawToughBird(getPoint(), 15, life);
   }
   
};



#endif /* toughBird_hpp */
