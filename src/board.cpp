//
// Created by MCS on 7/1/21.
//
#include <functional>
#include <iostream>
#include "board.h"

// adds a vehicle to the board
// has 2 return values:
//  0 -- worked correctly
// -1 -- error -- printed to stderr
int board::addVehicle(char letter, int startX, int startY, int len, orientation orient){

    vehicle newVehicle = vehicle(letter, startX, startY, len, orient);
    this->vehicles.append(newVehicle);
}


// checks to see if a vehicle exists, then moves it
// error return codes:
//  0 -- worked
// -1 -- error, printed to stderr
int board::moveVehicle(char letter, int newX, int newY){
    int carIndex = 256;
    int retVal = -1;
    //first thing to check is if the car exists in the existingCars list
    for(int itr = 0; itr < numOfCars; itr++){
        if(existingCars[itr] == letter){
            carIndex = itr;
        }
    }
    if(carIndex == 256){
        std::cerr << "vehicle does not exist\n" << endl;
        return retVal;
    }
    // the car exists, and this is it's position

}