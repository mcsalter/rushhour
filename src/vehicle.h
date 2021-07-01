//
// Created by Lahral on 7/1/21.
//

#ifndef RUSHHOUR_CLION_VEHICLE_H
#define RUSHHOUR_CLION_VEHICLE_H


enum orientation {vertical, horizontal};
class vehicle {

    const char vehiName;
    int[2] startPos;
    const int vehiSize;
    const orientation vehiOrient;
public:
    vehicle(const char name, int x1, int y1, const int size, const orientation orient)
            : vehiName(name)
            , startPos({x1, y1})
            , vehiSize(size)
            , vehiOrient(orient)
    { }

    void move(int newx, int newy);
    virtual ~vehicle();
};


#endif //RUSHHOUR_CLION_VEHICLE_H
