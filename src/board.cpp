#include <functional>
#include "board.h"


// adds a vehicle to the board
// has 2 return values:
//  0 -- worked correctly
// -1 -- error -- printed to stderr 
int addVehicle(char letter, int startx, int starty, int len, orientation orient){

    vehicle* newVehicle = vehicle();
    this.vehicles.append(newVehicle);
}


// checks to see if a vehicle exists, then moves it
// error return codes:
//  0 -- worked
// -1 -- error, printed to stderr
int board::moveVehicle(char letter, int newx, int newy){
    int carIndex = 256;
    int retval = -1;
    //first thing to check is if the car exists in the existingCars list
    for(int itr = 0; itr < numOfCars; itr++){
        if(existingCars[itr] == letter){
            carIndex = itr;
        }
    }
    if(carIndex == 256){ 
        std::cerr << "vehicle does not exist\n" << endl;
        return retval;
    }
    // the car exists, and this is it's position

}

