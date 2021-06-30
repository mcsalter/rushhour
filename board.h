#pragma once

enum orientation {vertical, horizontal};

class board{
    std::vector<vehicle> vehicles;
    int xcarIndex;
public:
    board();
    void moveVehicle(char letter, int newx, int newy);
    int runHeuristic(std::function<int> heuristic);
    void addVehicle(char letter, int startx, int starty, int len, orientation orient);

};
