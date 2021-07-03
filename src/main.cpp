#include "main.h"

int main() {
    board startBoard = board();

    Astar Frontier(&startBoard);
    Astar newStar(&Frontier, &startBoard);
    return 0;
}
