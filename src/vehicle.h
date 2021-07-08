//
// Created by MCS on 7/1/21.
//

#ifndef RUSHHOUR_CLION_VEHICLE_H
#define RUSHHOUR_CLION_VEHICLE_H

#include <iostream>


enum orientation {horizontal, vertical};
class vehicle {

    char vehiName;
    int startPos[2];
    int vehiSize;
    orientation vehiOrient;
public:
    vehicle(const char name, int x1, int y1)
            : vehiName(name)
            , startPos{x1, y1}
            , vehiSize(1)
            , vehiOrient(vertical)
    { }

    void move(int newx, int newy);
    void increaseSize(orientation orient);
    int** getPositions(); // should return a value containing the positions -- eg: [[0,0],[0,1],[0,2]]
    orientation getOrientation();
    char getName();
    virtual ~vehicle();
};


#endif //RUSHHOUR_CLION_VEHICLE_H
