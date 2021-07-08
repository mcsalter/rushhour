#include "main.h"

int main() {
    std::string tstboard[6] = {"------","--a---","xxa---","--a---","-bb---","------"};
    board firstBoard = readBoard(tstboard, 6);


    return 0;
}

board readBoard(std::string* boardstr, int rowIndex) {
    board output = board();
    std::vector<char> seenCars;
    for (int boardY = 0; boardY < rowIndex; boardY++) {
        for (int boardX = 0; boardX < rowIndex; boardX++) {
            if(boardstr[boardY][boardX] != '-'){
                char tempChar = boardstr[boardY][boardX];
                auto location = std::find(std::begin(seenCars), std::end(seenCars), tempChar);
                if(location == std::end(seenCars)){
                    seenCars.emplace_back(tempChar);
                    output.addVehicle(tempChar,boardX,boardY);
                } else{
                    output.updateVehicleSize(tempChar,boardX,boardY);
                }
            }
        }
    }
    return(output);
}