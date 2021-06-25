/*************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * Description: Contains the implementations of the
 *  method bodies for the game class.
 *
 * Please DO NOT share this code with other students from
 *  other sections or other semesters. They may not receive
 *  the same code that you are receiving.
 *************************************************************/

#include "game.h"

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "string.h"
#include <exception>
#include <memory>
#include <vector>
using namespace std;

#define OFF_SCREEN_BORDER_AMOUNT 5


/***************************************
 * GAME CONSTRUCTOR
 ***************************************/
Game :: Game(Point tl, Point br)
 : topLeft(tl), bottomRight(br), rifle(br)
{
   // Set up the initial conditions of the game
   score = 0;
   //Had this here just to pull the highscore of the game, at creation.
   highScoreHandler();
   // TODO: Set your bird pointer to a good initial value (e.g., NULL)
   bird = NULL;
   displayInstructions();
   

}

/****************************************
 * GAME DESTRUCTOR
 ****************************************/
Game :: ~Game()
{
   // TODO: Check to see if there is currently a bird allocated
   //       and if so, delete it.
   if (bird)
   {
      delete bird;
      bird = NULL;
   }

}

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   advanceBullets();
   advanceBird();

   handleCollisions();
   cleanUpZombies();
}

/***************************************
 * GAME :: ADVANCE BULLETS
 * Go through each bullet and advance it.
 ***************************************/
void Game :: advanceBullets()
{
   // Move each of the bullets forward if it is alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, so tell it to move forward
         bullets[i].advance();
         
         if (!isOnScreen(bullets[i].getPoint()))
         {
            // the bullet has left the screen
            bullets[i].kill();
         }
         
      }
   }
}

/**************************************************************************
 * GAME :: ADVANCE BIRD
 *
 * 1. If there is no bird, create one with some probability
 * 2. If there is a bird, and it's alive, advance it
 * 3. Check if the bird has gone of the screen, and if so, "kill" it
 **************************************************************************/
void Game :: advanceBird()
{
   if (bird == NULL)
   {
      // there is no bird right now, possibly create one
      
      // "resurrect" it will some random chance
      if (random(0, 30) == 0)
      {
         // create a new bird
         bird = createBird();
      }
   }
   else
   {
      // we have a bird, make sure it's alive
      if (bird->isAlive())
      {
         // move it forward
         bird->advance();
         // check if the bird has gone off the screen
         if (!isOnScreen(bird->getPoint()))
         {
            // We have missed the bird
            bird->kill();
         }
      }
   }
   
}

/**************************************************************************
 * GAME :: CREATE BIRD
 * Create a bird of a random type according to the rules of the game.
 **************************************************************************/
Bird* Game :: createBird()
{
   /*Create bird is special here because it will only create a
   total of 10 Tough or Angry birds, making the highscore more
   challenging, and also to make the game not feel like an endless
   loop*/
   // TODO: Fill this in
   
   int randomNum = random(1, 4);
   Bird* newBird = NULL;
   switch (randomNum)
   {
      case 1:
         newBird = new Bird();
         if (birdAmount < 1) {
            return 0;
         }
         --birdAmount;
         return newBird;
      case 2:
         newBird = new ToughBird();
         if (birdAmount < 1) {
            return 0;
         }
         --birdAmount;
         return newBird;
      case 3:
         newBird = new SacredBird();
         if (birdAmount < 1) {
            return 0;
         }
         //Sacred bird does not affect birdAmount
         return newBird;
      
   }
   return 0;
}

/**************************************************************************
 * GAME :: IS ON SCREEN
 * Determines if a given point is on the screen.
 **************************************************************************/
bool Game :: isOnScreen(const Point & point)
{
   return (point.getX() >= topLeft.getX() - OFF_SCREEN_BORDER_AMOUNT
      && point.getX() <= bottomRight.getX() + OFF_SCREEN_BORDER_AMOUNT
      && point.getY() >= bottomRight.getY() - OFF_SCREEN_BORDER_AMOUNT
      && point.getY() <= topLeft.getY() + OFF_SCREEN_BORDER_AMOUNT);
}

/**************************************************************************
 * GAME :: HANDLE COLLISIONS
 * Check for a collision between a bird and a bullet.
 **************************************************************************/
void Game :: handleCollisions()
{
   // now check for a hit (if it is close enough to any live bullets)
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         // this bullet is alive, see if its too close

         // check if the bird is at this point (in case it was hit)
         if (bird != NULL && bird->isAlive())
         {
            // BTW, this logic could be more , but this will
            // get the job done for now...
            if (fabs(bullets[i].getPoint().getX() - bird->getPoint().getX()) < CLOSE_ENOUGH
                && fabs(bullets[i].getPoint().getY() - bird->getPoint().getY()) < CLOSE_ENOUGH)
            {
               //we have a hit!
               
               // hit the bird
               int points = bird->hit();
               score += points;
               //Needed this here anytime score gets updated
               if (wastedBullets == 0)
               {
                  highScoreHandler();
               }
               else
               {
               }
               // the bullet is dead as well
               bullets[i].kill();
            }
         }
      } // if bullet is alive
      
   } // for bullets
}

/**************************************************************************
 * GAME :: CLEAN UP ZOMBIES
 * Remove any dead objects (take bullets out of the list, deallocate bird)
 **************************************************************************/
void Game :: cleanUpZombies()
{
   // check for dead bird
   if (bird != NULL && !bird->isAlive())
   {
      // the bird is dead, but the memory is not freed up yet
      
      // TODO: Clean up the memory used by the bird
      delete bird;
      bird = NULL;
      //Sometimes needed this because points are added later
      if (wastedBullets == 0)
      {
         highScoreHandler();
      }
      else
      {
      }
   }
   
   // Look for dead bullets
   vector<Bullet>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet bullet = *bulletIt;
      // Asteroids Hint:
      // If we had a list of pointers, we would need this line instead:
      //Bullet* pBullet = *bulletIt;
      
      if (!bullet.isAlive())
      {
         // If we had a list of pointers, we would need to delete the memory here...
         
         
         // remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }
   
}

/***************************************
 * GAME :: HANDLE INPUT
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // Change the direction of the rifle
   if (ui.isLeft())
   {
      rifle.moveLeft();
   }
   
   if (ui.isRight())
   {
      rifle.moveRight();
   }
   
   // Check for "Spacebar
   if (ui.isSpace())
   {
      if (birdAmount <= 0 && bird == NULL)
      {
         if (wastedBullets == 0)
         {
            std::cout << std::endl;
            ++wastedBullets;
         }
         else if (wastedBullets < 5)
         {
            std::cout << "No more birds, game over, please stop pushing my spacebar, I'm sensitive." << std::endl;
            ++wastedBullets;
         }
         
         else if (wastedBullets <= 10)
         {
            std::cout << "No seriously, the game is over. Quit pushing my buttons!" << std::endl;
            ++wastedBullets;
         }
         else if (wastedBullets < 15)
         {
            std::cout << std::endl;
            std::cout << "Wow you really want to play this game?" << std::endl;
            std::cout << "Fine I submit, you insolent peasant" << std::endl;
            std::cout << "go, go kill all the birds you wish," << std::endl;
            std::cout << "but this won't count towards highscore, sucka!" << std::endl;
            ++wastedBullets;
            birdAmount = 9001;
         }
      }
      Bullet newBullet;
      newBullet.fire(rifle.getPoint(), rifle.getAngle());
      bullets.push_back(newBullet);
   }
}

void Game :: highScoreHandler()
{
   std::string highscoreFileName = "highscore";
   /*Lets check if the file name exists if it doesn't then create
    a new highscore file and save the current score to it*/
   ifstream fin(highscoreFileName);
   //Declare fout, used to run function ofstream.
   ofstream fout;
      if (fin.fail())
   {
      //Create a new file with the name of the file the user declared.
      if (birdAmount >= 0) {
         fout.open(highscoreFileName);
         {
            //Write to the file
            fout << score;
            //Close the file we were writing to.
            fout.close();
            return;
         }
      }
      
   }
   //Update highscore file if (score > highscore)
   else
   {
         fin >> highscore;
      if (birdAmount >= 0) {
         if (score > highscore)
         {
            //Open a new file with the name of the file the user declared.
            fout.open(highscoreFileName);
            fout << score;
         }
      }
      
   }
   fin.close();
   return;
}

void Game :: displayInstructions()
{
   std::cout << "Welcome to the most prestigious game of all the lands,\n";
   std::cout << "kings and queens cross the empire to play such debachery!\n";
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << "The instructions are simple; kill the birds to get points.\n";
   std::cout << "But watch out for the sacred bird, marked ironically as a spinning\n";
   std::cout << "satanic symbol!\n";
   std::cout << "Can you try to beat the high score listed in the top right?\n";
   std::cout << "Pay attention your bird count in the top middle, there are only so many birds we'll\n";
   std::cout << "allow killed on the Kings land!";
   std::cout << std::endl;
   std::cout << std::endl;
   std::cout << system("pause");
   std::cout << std::endl << "MAKE SURE TO CLICK INTO THE GAME WINDOW!\n";
}


/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   // draw the bird
   // TODO: Check if you have a valid bird and if it's alive
   // then call it's draw method
   if (bird != NULL && bird->isAlive())
   {
  
      bird->draw();
   
   };
  

   // draw the rifle
   rifle.draw();
   // draw the bullets, if they are alive
   for (int i = 0; i < bullets.size(); i++)
   {
      if (bullets[i].isAlive())
      {
         bullets[i].draw();
      }
   }
   
   // Put the score on the screen
   Point scoreLocation;
   scoreLocation.setX(topLeft.getX() + 5);
   scoreLocation.setY(topLeft.getY() - 5);
   drawNumber(scoreLocation, score);
   
   // Puts the old or current highscore on the screen
   Point highScoreLocation;
   highScoreLocation.setX(175);
   highScoreLocation.setY(194);
   drawNumber(highScoreLocation, highscore);
   
   // Puts the amount of remaining birds on the top middle
   Point BirdsRemaining;
   BirdsRemaining.setX(-5);
   BirdsRemaining.setY(194);
   drawNumber(BirdsRemaining, birdAmount);
   
   Point textBirds;
   textBirds.setX(-105);
   textBirds.setY(186);
   drawText(textBirds,"Birds Remaining:");
   
   Point textScore;
   // Adjust the headers if there is a longer number to draw.
   if (score > 9 || score < 0)
   {
      textScore.setX(topLeft.getX() + 35);
      textScore.setY(topLeft.getY() - 14);
   }
   else
   {
      textScore.setX(topLeft.getX() + 20);
      textScore.setY(topLeft.getY() - 14);
   }

   drawText(textScore,":Score");
   
   Point textHighScore;
   textHighScore.setX(100);
   textHighScore.setY(186);
   drawText(textHighScore,"High Score:");



   
}


