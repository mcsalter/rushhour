//
// Created by MCS on 7/1/21.
//
#include "board.h"

// adds a vehicle to the board
// has 2 return values:
//  0 -- worked correctly
// -1 -- error -- printed to stderr
int board::addVehicle(char letter, int startX, int startY){
    // making an offset because the piece can either be horizontal or vertical,
    // and I do not need to check both possible offsets, only one.
    int testLst[2] = {startX, startY};
    int check = 1;
    for(int itr : testLst){
        if(itr > boardSize){check = 0;}
    }
    if(check == 0){
        //error detected, out of boundary
        std::cerr << "piece placement out of bounds" << std::endl;
        return -1;
    }
    else{
        // code to run once the verification that it is within the boardspace
        //vehicle newVehicle = vehicle(letter, startX, startY, len, orient);
        vehicles.emplace_back(letter, startX, startY);
        existingCars[numOfCars] = letter;
        if(letter == 'x') {xCarIndex = numOfCars;}
        numOfCars++;
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
        vehicle tempVehicle = vehicles[carIndex];
        //int offset[2] = {startY+len, startX+len};
        int** piece = tempVehicle.getPositions();
        bool directionOffset = (bool) tempVehicle.getOrientation();
        //int testLst[3] = {startX, startY, offset[orient]};
        int check = 1;
        for(int itr = 0; itr < (sizeof(piece)/sizeof(piece[0])); itr++){
            if(piece[itr][directionOffset] > boardSize){check = 0;}
        }
        if(check == 0){
            //error detected, out of boundary
            std::cerr << "piece placement out of bounds" << std::endl;
            return -1;
        }

        // the car exists, the offset is safe, and this is it's position
        vehicles[carIndex].move(newX, newY);
    }
    return 0;
}

// takes in the name of the vehicle, checks that it exists, then increases the vehicle size
int board::updateVehicleSize(char letter, int newx, int newy){
    //checking to make sure it exists:
    auto vehicleIndex = std::find(std::begin(existingCars), std::end(existingCars), letter);
    if(vehicleIndex == std::end(existingCars)){
        std::cerr << "car does not exist" << std::endl;
        return -1;
    }
    int offset = std::distance(existingCars,vehicleIndex);
    // calculating the orientation
    int** positions = vehicles[offset].getPositions();
    int origin[2] = {positions[0][0], positions[0][1]};
    orientation orient;
    if(origin[0] == newx){
        // the x axis has not changed in value, means that it is a vertical block
        orient = vertical;
    }else if(origin[1] == newy){
        // the y axis has not changed in value, means that it is a horizontal block
        orient = horizontal;
    }else{
        //the new coordinates make no sense
        std::cerr << "the given coordinates make no sense" << std::endl;
        return -1;
    }
    vehicles[offset].increaseSize(orient);
    return 0;
}

std::vector<char> board::getVehicles() {
    std::vector<char> vehiList;
    vehiList.reserve(numOfCars);
    for(int itr = 0; itr < numOfCars; itr++){
        // checking the vehicle names and updating existingCars if needed
        vehiList.emplace_back(vehicles[itr].getName());
        existingCars[itr] = vehicles[itr].getName();
    }
    return vehiList;
}

void board::printBoard() {

}

int **board::findXCar() {
    return vehicles[xCarIndex].getPositions();
}

int** board::getPositions(char vehicleLetter) {
    for (vehicle car : vehicles){
        if(car.getName() == vehicleLetter){return car.getPositions();}
    }
    abort();
}

int board::numCars() {
    return numOfCars;
}

board::~board() {

}


