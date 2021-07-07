//
// Created by MCS on 7/1/21.
//

#include "vehicle.h"

void vehicle::move(int newx, int newy){
    // do not need to check the board positions as that will already have been done by
    // board::moveVehicle()
    startPos[0] = newx;
    startPos[1] = newy;
}

void vehicle::increaseSize(orientation orient) {
    vehiSize ++;
    vehiOrient = orient;
}

int** vehicle::getPositions() {
    int** positions = new int*[vehiSize]; //{startPos[0],startPos[1]};
    for(int itr=0; itr < vehiSize; itr++){positions[itr]= new int[2];}
    int baseSize[2] = {startPos[0],startPos[1]};
    for(int itr=0; itr < vehiSize; itr++){
        //x change is horizontal, y change is vertical
        //will be in the set up of [x,y]
        positions[itr][int((bool)vehiOrient)]=baseSize[int((bool)vehiOrient)]+itr;
        positions[itr][int(not((bool)vehiOrient))] = baseSize[int(not((bool)vehiOrient))];
    }
    return positions;
}
orientation vehicle::getOrientation() {
    return vehiOrient;
}

vehicle::~vehicle() {

}

