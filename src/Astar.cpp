//
// Created by MCS on 7/1/21.
//

#include "Astar.h"

std::vector<board> Astar::generateNewBoards(board startboard) {
    std::vector<board> outputs;
    //generate the 4 sets of all possible slides, and
    std::vector<board> upSlides = generateSlidesUp(startboard);
    std::vector<board> downSlides = generateSlidesDown(startboard);
    std::vector<board> leftSlides = generateSlidesLeft(startboard);
    std::vector<board> rightSlides = generateSlidesRight(startboard);
    outputs.insert(std::end(outputs), std::begin(upSlides), std::end(upSlides));
    outputs.insert(std::end(outputs), std::begin(downSlides), std::end(downSlides));
    outputs.insert(std::end(outputs), std::begin(leftSlides), std::end(leftSlides));
    outputs.insert(std::end(outputs), std::begin(rightSlides), std::end(rightSlides));

    return outputs;
}

std::vector<board> Astar::generateSlidesUp(board startboard) {
    std::vector<board> output;
    // collect the cars into 1 list
    // one is a list of occupied spaces
    // the vehicles in the board will count as the other list needed
    // will check each car to see:
    //      that it is vertical
    //      that it can be moved up without entering an occupied slot

    std::vector<char> carNames = startboard.getVehicles();
    std::vector<int**> occupiedSpaces;
    occupiedSpaces.reserve(startboard.numCars());
    for(char car : carNames){
        occupiedSpaces.emplace_back(startboard.getPositions(car));
    }
    return output;
}

// the following three functions are functionally the same as generateSlidesUp:
std::vector<board> Astar::generateSlidesDown(board startboard) {
    return std::vector<board>();
}

std::vector<board> Astar::generateSlidesLeft(board startboard) {
    return std::vector<board>();
}

std::vector<board> Astar::generateSlidesRight(board startboard) {
    return std::vector<board>();
}

int Astar::generateHeuristic(board startboard) {
    return 0;
}
