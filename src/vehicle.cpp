//
// Created by MCS on 7/1/21.
//

#include "vehicle.h"

void vehicle::move(int newx, int newy){
    // do not need to check the board positions as that will already have been done by
    // board::moveVehicle()
    this->startPos[0]=newx;
    this->startPos[1] = newy;
}