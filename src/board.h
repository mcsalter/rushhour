#pragma once
#include "vehicle.h"

enum orientation {vertical, horizontal};

class board{
    std::vector<vehicle*> vehicles;
    int xcarIndex;
    char existingCars[32];
    int numOfCars;
    const int boardSize;
public:
    board()
        : boardSize = 6
        , numOfCars = 0
        , xcarIndex = 256 // a dummy that indicates not set to correct value
        {}
    int addVehicle(char letter, int startx, int starty, int len, orientation orient);
    int moveVehicle(char letter, int newx, int newy);
    int runHeuristic(std::function<int> heuristic);
    void printBoard()
    virtual ~board()
};
