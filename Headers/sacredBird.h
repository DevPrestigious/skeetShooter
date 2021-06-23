//
//  sacredBird.h
//  skeetSkeet
//
//  Created by Alexander Dohms on 6/21/21.
//

#ifndef sacredBird_hpp
#define sacredBird_hpp
#include "bird.h"


class SacredBird : public Bird
{
protected:
   
   
public:
   
   SacredBird()
   {
      point = Point(-200,random(-200,200));
      isAlive();
      velocity = Velocity(1,1);
      points = -12;
   }
   
   void draw() override
   {
      drawSacredBird(getPoint(), 15);
   }
   
};



#endif /* sacredBird_h*/
