#pragma once

class vehicle{
    const char vehiName;
    int[2] startPos;
    const int vehiSize;
    const orientation vehiOrient
public
    vehicle(const char name, int x1, int y1, const int size, const orientation orient) 
        : vehicName(name) 
        , startPos({x1, y1}) 
        , vehiSize(size) 
        , vehiOrient(orient) 
        { }

    void move(int newx, int newy);
    virtual ~vehicle()
};


