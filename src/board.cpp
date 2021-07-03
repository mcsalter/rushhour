//
// Created by MCS on 7/1/21.
//
#include "board.h"

// adds a vehicle to the board
// has 2 return values:
//  0 -- worked correctly
// -1 -- error -- printed to stderr
int board::addVehicle(char letter, int startX, int startY, int len, orientation orient){
    // making an offset because the piece can either be horizontal or vertical,
    // and I do not need to check both possible offsets, only one.
    int offset[2] = {startY+len, startX+len};
    int testLst[3] = {startX, startY, offset[orient]};
    int check = 1;
    for(int itr = 0; itr < 3; itr++){
        if(testLst[itr] > this->boardSize){check = 0;}
    }
    if(check == 0){
        //error detected, out of boundary
        std::cerr << "piece placement out of bounds" << std::endl;
        return -1;
    }
    else{
        // code to run once the verification that it is within the boardspace
        //vehicle newVehicle = vehicle(letter, startX, startY, len, orient);
        this->vehicles.emplace_back(letter, startX, startY, len);
        this->numOfCars++;
        this->existingCars[numOfCars] = letter;
        if(letter == 'x') {this->xCarIndex = this->numOfCars;}
        return 0;
    }
}


// checks to see if a vehicle exists, then moves it
// error return codes:
//  0 -- worked
// -1 -- error, printed to stderr
int board::moveVehicle(char letter, int newX, int newY) {
    int carIndex = 256;
    int retVal = -1;
    //first thing to check is if the car exists in the existingCars list
    for (int itr = 0; itr < numOfCars; itr++) {
        if (existingCars[itr] == letter) {
            carIndex = itr;
        }
    }
    if (carIndex == 256) {
        std::cerr << "vehicle does not exist\n" << std::endl;
        return retVal;
    } else {
        vehicle* tempVehicle = &this->vehicles[carIndex];
        //int offset[2] = {startY+len, startX+len};
        int* piece = tempVehicle->getPositions();
        int directionOffset = tempVehicle->getOrientation();
        //int testLst[3] = {startX, startY, offset[orient]};
        int check = 1;
        for(int itr = 0; itr < 3; itr++){
            if(piece[itr][directionOffset] > this->boardSize){check = 0;}
        }
        if(check == 0){
            //error detected, out of boundary
            std::cerr << "piece placement out of bounds" << std::endl;
            return -1;
        }

        // the car exists, the offset is safe, and this is it's position
        this->vehicles[carIndex].move(newX, newY);
    }
}

int updateVehicleSize(int newX, int newY){

}

void board::printBoard() {

}

board::~board() {

}
