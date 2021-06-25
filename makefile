###############################################################
# Program:
#     Milestone 08, Skeet
#     Brother Alvey, CS165
# Author:
#     Alexander Dohms
# Summary:
#     This is a classic game that you can shoot and destroy clay pigeons. 
#	  The purpose of this game is to help me understand and learn how to
#	  implement class and class inheritance. I will also be using 
#	  a fun tool called virtual functions which basically help me
#	  to use the same functions with different values in other 
#	  classes.
# Above and Beyond
#     I created a way to handle a highscore and limit the amount of
#     birds that were created
###############################################################


LFLAGS = -lglut -lGLU -lGL

###############################################################
# Build the main game
###############################################################
a.out: driver.o game.o uiInteract.o uiDraw.o point.o rifle.o 
	g++ driver.o game.o uiInteract.o uiDraw.o point.o rifle.o $(LFLAGS)

###############################################################
# Individual files
#    uiDraw.o      Draw polygons on the screen and do all OpenGL graphics
#    uiInteract.o  Handles input events
#    point.o       The position on the screen
#    ground.o      Handles the ground / world
#    game.o        Handles the game interaction
###############################################################
uiDraw.o: uiDraw.cpp uiDraw.h point.h
	g++ -c uiDraw.cpp

uiInteract.o: uiInteract.cpp uiInteract.h
	g++ -c uiInteract.cpp

point.o: point.cpp point.h
	g++ -c point.cpp

game.o: game.cpp uiDraw.h uiInteract.h point.h rifle.h bullet.h birds.h
	g++ -c game.cpp

driver.o: game.h uiInteract.h driver.cpp
	g++ -c driver.cpp

rifle.o: rifle.h point.h uiDraw.h rifle.cpp
	g++ -c rifle.cpp

#######################################################################
# ADD YOUR ADDITIONAL RULES HERE!
#
# Then, don't forget to add them to the dependecy list for a.out above.
#######################################################################
bird.o: bird.cpp bird.h
	g++ -c bird.cpp

bullet.o: bullet.cpp bullet.h
	g++ -c bullet.cpp

velocity.o: velocity.cpp velocity.cpp
	g++ -c velocity.cpp

###############################################################
# General rules
###############################################################
clean:
	rm a.out *.o
