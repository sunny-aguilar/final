# File: 	makefile
# Author: 	Sandro Aguilar
# Date: 	March 12 2019
# Description:	Makefile for Final Project

# Variables to control Makefile operation

CXX = g++

CXXFLAGS = -Wall
CXXFLAGS += -g
CXXFLAGS += -std=c++0x

OBJECTS = main.o
OBJECTS += game.o
OBJECTS += menu.o
OBJECTS += space.o
OBJECTS += player.o
OBJECTS += bossRoom.o
OBJECTS += breakRoom.o
OBJECTS += friendCubicle.o
OBJECTS += meetingRoom.o
OBJECTS += myCubicle.o
OBJECTS += waterCooler.o

HPPs = game.hpp
HPPs += menu.hpp
HPPs += space.hpp
HPPs += player.hpp
HPPs += bossRoom.hpp
HPPs += breakRoom.hpp
HPPs += friendCubicle.hpp
HPPs += meetingRoom.hpp
HPPs += myCubicle.hpp
HPPs += waterCooler.hpp

CPPs = main.cpp
CPPs += game.cpp
CPPs += menu.cpp
CPPs += space.cpp
CPPs += player.cpp
CPPs += bossRoom.cpp
CPPs += breakRoom.cpp
CPPs += friendCubicle.cpp
CPPs += meetingRoom.cpp
CPPs += myCubicle.cpp
CPPs += waterCooler.cpp


# Targets needed to bring the executable up to date
Final: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o Final $(OBJECTS)

main.o: main.cpp $(HPPs)
	$(CXX) $(CXXFLAGS) -c main.cpp

game.o: game.hpp

menu.o: menu.hpp

space.o: space.hpp

player.o: player.hpp

bossRoom.o: bossRoom.hpp

breakRoom.o: breakRoom.hpp

friendCubicle.o: friendCubicle.hpp

meetingRoom.o: meetingRoom.hpp

myCubicle.o: myCubicle.hpp

waterCooler.o: waterCooler.hpp


# Clean-up operations
clean:
	rm Final *.o

debug:
	valgrind -v --leak-check=full --show-leak-kinds=all --track-origins=yes ./Final

zip:
	zip -D Final_Aguilar_Sandro.zip $(CPPs) $(HPPs) $(TXTS) makefile *.txt *.pdf