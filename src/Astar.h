//
// Created by MCS on 7/1/21.
//

#ifndef RUSHHOUR_ASTAR_H
#define RUSHHOUR_ASTAR_H

#include <vector>
#include "board.h"


class Astar {

    board baseBoard;
    const int g,h,f;
    std::vector<board> boardHist;

public:
    Astar(board startBoard)
            : baseBoard(startBoard)
            , g(generateHeuristic(startBoard))
            , h(0)
            , f(g+h)
    {boardHist.emplace_back(startBoard);}
    Astar(Astar* parent, board childBoard)
            : baseBoard()
            , g(generateHeuristic(childBoard))
            , h(parent->h + 1)
            , f(g+h)
            , boardHist(std::begin(parent->boardHist), std::end(parent->boardHist))
    {boardHist.emplace_back(childBoard);}

    std::vector<board> generateNewBoards(board startboard);
    std::vector<board> generateSlidesUp(board startboard);
    std::vector<board> generateSlidesDown(board startboard);
    std::vector<board> generateSlidesLeft(board startboard);
    std::vector<board> generateSlidesRight(board startboard);

    int generateHeuristic(board startboard);

    virtual ~Astar();

};



#endif //RUSHHOUR_ASTAR_H
