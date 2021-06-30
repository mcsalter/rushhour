#pragma once

class vehicle{
    char vehiName;
    int[2] startPos;
    int[2] endPos;
public
    void vehicle(char name, int x1, int y1, int x2, int y2);
    move(int newx, int newy);
};


