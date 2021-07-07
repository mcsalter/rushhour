#include "main.h"

int main() {
    board startBoard = board();
    startBoard.addVehicle('x',1,2);
    startBoard.updateVehicleSize('x',2,2);
    startBoard.moveVehicle('x',5,3);
    std::cout << sizeof(startBoard) << std::endl;
    return 0;
}
