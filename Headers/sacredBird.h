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
   // Constructor for SacredBird, -12 because it helps handle toughBirds clause.
   // I could've done it a little better to actually make it -10
   SacredBird()
   {
      point = Point(-200,startY);
      isAlive();
      velocity = Velocity(random(3,7),velY(startY));
      points = -12;
   }
   // Recreates the draw to drawSacredBird
   void draw() override
   {
      drawSacredBird(getPoint(), 15);
   }
   
};



#endif /* sacredBird_h*/
