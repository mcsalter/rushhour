//
// Created by MCS on 7/1/21.
//

#ifndef RUSHHOUR_CLION_BOARD_H
#define RUSHHOUR_CLION_BOARD_H

#include "vehicle.h"

class board {
    std::vector<vehicle*> vehicles;
    int xCarIndex;
    char existingCars[32];
    int numOfCars;
    const int boardSize;
public:
    board()
            : boardSize(6)
            , numOfCars(0)
            , xCarIndex(256) // a dummy that indicates not set to correct value
    { }
    int addVehicle(char letter, int startX, int startY, int len, orientation orient);
    int moveVehicle(char letter, int newX, int newY);
    int runHeuristic(std::function<int> heuristic);
    void printBoard();
    virtual ~board();
};


#endif //RUSHHOUR_CLION_BOARD_H
