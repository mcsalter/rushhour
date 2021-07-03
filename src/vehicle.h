//
// Created by MCS on 7/1/21.
//

#ifndef RUSHHOUR_CLION_VEHICLE_H
#define RUSHHOUR_CLION_VEHICLE_H


enum orientation {horizontal, vertical};
class vehicle {

    const char vehiName;
    int startPos[2];
    int vehiSize;
    orientation vehiOrient;
public:
    vehicle(const char name, int x1, int y1, int size)
            : vehiName(name)
            , startPos{x1, y1}
            , vehiSize(size)
            , vehiOrient(vertical)
    { }

    void move(int newx, int newy);
    void increaseSize(orientation orient);
    int* getPositions(); // should return a value containing the positions -- eg: [[0,0],[0,1],[0,2]]
    int getOrientation();
    virtual ~vehicle();
};


#endif //RUSHHOUR_CLION_VEHICLE_H
