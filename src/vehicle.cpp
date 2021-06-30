#include "vehicle.h"

void vehicle::move(int newx, int newy){
    // do not need to check the board positions as that will already have been done by 
    // board::moveVehicle()
    this.startPos={newx,newy}
}
