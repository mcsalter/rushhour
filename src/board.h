//
// Created by MCS on 7/1/21.
//

#ifndef RUSHHOUR_CLION_BOARD_H
#define RUSHHOUR_CLION_BOARD_H

#include <iostream>
#include <vector>
#include "vehicle.h"

class board {
    std::vector<vehicle> vehicles;
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
    int updateVehicleSize(int newX, int newY);
    void printBoard();
    virtual ~board();
};


#endif //RUSHHOUR_CLION_BOARD_H
